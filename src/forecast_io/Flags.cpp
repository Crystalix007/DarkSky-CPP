#include "forecast_io/Flags.hpp"

#include "common/enumeration.hpp"
#include "common/to_string.hpp"
#include "forecast_io/MeasurementSystemDefaultNameArrayHolder.hpp"

namespace forecast_io
{

Flags::Flags(math::MeasurementSystem units) noexcept
    : Flags(true, false, std::unordered_set<std::string>(), -1.0,
            std::unordered_multimap<std::string, std::string>(), units)
{
}

Flags::Flags(bool darkskyUnavailable, bool metnoLicense, std::unordered_set<std::string> sources,
             double nearestStation, std::unordered_multimap<std::string, std::string> stations,
             math::MeasurementSystem units) noexcept
    : darkskyUnavailable(darkskyUnavailable), metnoLicense(metnoLicense), sources(sources),
      nearestStation(nearestStation), stations(stations), units(units)
{
}

std::ostream& Flags::dump(std::ostream& o) const
{
	o << "Flags[hasMetnoLicense()=";
	o << common::to_quoted_string(hasMetnoLicense());
	o << ", isDarkskyUnavailable()=";
	o << common::to_quoted_string(isDarkskyUnavailable());
	o << ", getSources()=";
	o << common::to_collection_string(getSources());
	o << ", getNearestStation()=";
	o << common::to_quoted_string(getNearestStation());
	o << ", getStations()=";
	o << common::to_collection_string(getStations());
	o << ", getUnits()=";
	const math::MeasurementSystem units = getUnits();
	const std::string& defaultUnitsName = MeasurementSystemDefaultNameArrayHolder::getName(units);
	o << defaultUnitsName;
	o << ']';

	return o;
}

std::string Flags::str() const
{
	std::stringstream ss(std::stringstream::out);
	dump(ss);
	return ss.str();
}

} // namespace forecast_io

namespace std
{

string to_string(const forecast_io::Flags& value)
{
	return value.str();
}

} // namespace std

std::ostream& operator<<(std::ostream& o, const forecast_io::Flags& value)
{
	return value.dump(o);
}
