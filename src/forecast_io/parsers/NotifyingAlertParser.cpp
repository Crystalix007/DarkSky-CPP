#include "forecast_io/parsers/NotifyingAlertParser.hpp"

#include <ctime>
#include <stdexcept>

#include "forecast_io/listeners/AlertDetailsListener.hpp"

namespace forecast_io
{
namespace parsers
{

// Free functions ---------------------------------------------------------------
static AlertAttributeNameMap createDefaultAttributeNameMap()
{
	AlertAttributeNameMap result(
			AlertAttribute::AlertAttribute_COUNT);

	result["description"] = AlertAttribute::DESCRIPTION;
	result["expires"] = AlertAttribute::EXPIRY_TIME;
	result["title"] = AlertAttribute::TITLE;
	result["uri"] = AlertAttribute::URI;

	return result;
}

// Con-/destructors -------------------------------------------------------------

NotifyingAlertParser::NotifyingAlertParser(listeners::AlertDetailsListener& listener,
		const AlertAttributeNameMap& attributeNames) :
		AbstractJsonStateMapParser(attributeNames), Notifier(listener)
{
}

// Members ----------------------------------------------------------------------
const AlertAttributeNameMap NotifyingAlertParser::DEFAULT_ATTRIBUTE_NAMES =
		createDefaultAttributeNameMap();

void NotifyingAlertParser::parseAttribute(const AlertAttribute& attribute,
		json_object* const & pValue)
{
	switch (attribute)
	{
	case AlertAttribute::DESCRIPTION:
	{
		const std::string description(json_object_get_string(pValue));
		getListener()->notifyDescription(description);
		break;
	}
	case AlertAttribute::EXPIRY_TIME:
	{
		const time_t expiryTime(
				static_cast<time_t>(json_object_get_int64(pValue)));
		getListener()->notifyExpiryTime(expiryTime);
		break;
	}
	case AlertAttribute::TITLE:
	{
		const std::string title(json_object_get_string(pValue));
		getListener()->notifyTitle(title);
		break;
	}
	case AlertAttribute::URI:
	{
		const std::string uri(json_object_get_string(pValue));
		getListener()->notifyUri(uri);
		break;
	}
	default:
	{
		throw std::logic_error(
				createUndefinedAttributeErrorMessage(AlertAttribute_NAME,
						attribute));
		break;
	}
	}
}

}
}
