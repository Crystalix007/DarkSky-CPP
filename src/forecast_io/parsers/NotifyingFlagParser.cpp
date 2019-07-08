#include "forecast_io/parsers/NotifyingFlagParser.hpp"

#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "common/to_string.hpp"
#include "forecast_io/listeners/FlagListener.hpp"
#include "math/MeasurementSystem.hpp"
#include "json/ParseError.hpp"
#include "json/json_maps.hpp"

namespace forecast_io
{

namespace parsers
{

// Free functions ---------------------------------------------------------------

static std::string
createUnknownMeasurementSystemAttributeValueErrorMessage(const std::string& attributeValue)
{
	std::stringstream ss(std::stringstream::out);
	ss << "Unknown " << math::MeasurementSystem_NAME << " for attribute value "
	   << common::to_quoted_string(attributeValue) << ".";
	return ss.str();
}

static json::ParseError
createUnknownMeasurementSystemAttributeValueError(const std::string& attributeValue)
{
	const std::string errorMessage =
	    createUnknownMeasurementSystemAttributeValueErrorMessage(attributeValue);
	return json::ParseError(errorMessage);
}

// Con-/destructors -------------------------------------------------------------

NotifyingFlagParser::NotifyingFlagParser(
    listeners::FlagListener* pListener, const FlagsAttributeNameMap& attributeNames,
    const MeasurementSystemAttributeValueMap& measurementSystemAttributeValues,
    std::string sourceStationAttributeSuffix) noexcept
    : AbstractJsonStateMapParser(attributeNames), Notifier(pListener),
      measurementSystemAttributeValues(measurementSystemAttributeValues),
      sourceStationAttributeSuffix(sourceStationAttributeSuffix)
{
}

// Members ----------------------------------------------------------------------
const std::string NotifyingFlagParser::DEFAULT_SOURCE_STATION_ATTRIBUTE_SUFFIX = "stations";

void NotifyingFlagParser::finishParse()
{
	// If there are no sources to notify about,
	if (sources.empty())
	{
		// If there are stations to notify about,
		if (!stations.empty())
		{
			for (listeners::FlagListener* const& pListener : getListeners())
			{
				pListener->notifyStations(stations);
			}
		}
	}
	else if (stations.empty())
	{
		// There are sources but no stations to notify about
		for (listeners::FlagListener* const& pListener : getListeners())
		{
			pListener->notifySources(sources);
		}
	}
	else
	{
		// There are both sources and stations to notify about
		for (listeners::FlagListener* const& pListener : getListeners())
		{
			pListener->notifySources(sources);
			pListener->notifyStations(stations);
		}
	}
}

void NotifyingFlagParser::handleUnmappedAttribute(const std::string& key,
                                                  json_object* const& pValue)
{
	std::cerr << "Found unmapped attribute: " << key << std::endl;
	const size_t foundIdx = key.find_last_of(sourceStationAttributeSuffix);
	if (foundIdx == std::string::npos)
	{
		json::AbstractJsonStateMapParser<FlagsAttribute>::handleUnmappedAttribute(key, pValue);
	}
	else
	{
		const std::string sourceName = key.substr(0, foundIdx);

		if (json_object_get_type(pValue) == json_type_array)
		{
			// Parse all values in the JSON array and add them to the set of station IDs for the
			// given source
			json::insertJsonStringArrayValues(stations, sourceName, pValue);
		}
	}
}

void NotifyingFlagParser::parseAttribute(const FlagsAttribute& attribute,
                                         json_object* const& pValue)
{
	switch (attribute)
	{
		case FlagsAttribute::DARKSKY_UNAVAILABLE:
		{
			const bool darkskyUnavailable = bool(json_object_get_boolean(pValue));
			for (listeners::FlagListener* const& pListener : getListeners())
			{
				pListener->notifyDarkskyUnavailable(darkskyUnavailable);
			}
			break;
		}
		case FlagsAttribute::METNO_LICENSE:
		{
			const bool metnoLicense = bool(json_object_get_boolean(pValue));
			for (listeners::FlagListener* const& pListener : getListeners())
			{
				pListener->notifyMetnoLicense(metnoLicense);
			}
			break;
		}
		case FlagsAttribute::SOURCES:
		{
			json::insertJsonStringArrayValues(sources, pValue);
			break;
		}
		case FlagsAttribute::NEAREST_STATION:
		{
			const double nearestStation = double(json_object_get_double(pValue));
			for (listeners::FlagListener* const& pListener : getListeners())
			{
				pListener->notifyNearestStation(nearestStation);
			}
			break;
		}
		case FlagsAttribute::UNITS:
		{
			const std::string unitsStr(json_object_get_string(pValue));
			const math::MeasurementSystem& measurementSystem = parseMeasurementSystem(unitsStr);
			for (listeners::FlagListener* const& pListener : getListeners())
			{
				pListener->notifyUnits(measurementSystem);
			}
			break;
		}
		default:
			throw std::logic_error(
			    createUndefinedAttributeErrorMessage(FlagsAttribute_NAME, attribute));
			break;
	}
}

const math::MeasurementSystem& NotifyingFlagParser::parseMeasurementSystem(
    const MeasurementSystemAttributeValueMap::key_type& attributeValue) const
{
	auto iter = measurementSystemAttributeValues.find(attributeValue);
	if (iter == measurementSystemAttributeValues.end())
	{
		const json::ParseError error =
		    createUnknownMeasurementSystemAttributeValueError(attributeValue);
		throw error;
	}
	else
	{
		const math::MeasurementSystem& measurementSystem = iter->second;
		return measurementSystem;
	}
}

} // namespace parsers
} // namespace forecast_io
