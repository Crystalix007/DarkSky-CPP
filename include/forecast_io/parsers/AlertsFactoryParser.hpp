#ifndef ALERTSFACTORYPARSER_HPP
#define ALERTSFACTORYPARSER_HPP

#include "../../common/Notifier.hpp"      // Base class: Notifier
#include "../../json/JsonArrayParser.hpp" // Base class: json::JsonArrayParser

namespace forecast_io
{

// Forward declarations
namespace factories
{
class AlertFactory;
}
namespace listeners
{
class AlertsListener;
}

namespace parsers
{
// Forward declarations
class NotifyingAlertParser;

class AlertsFactoryParser : public json::JsonArrayParser<NotifyingAlertParser>,
                            public common::Notifier<listeners::AlertsListener>
{
public:
	AlertsFactoryParser(listeners::AlertsListener* pListener, NotifyingAlertParser& alertParser,
	                    factories::AlertFactory* pFactory) noexcept;

protected:
	virtual void handleArrayElement(json_object* const& arrayElement);

private:
	factories::AlertFactory& factory;
};

} // namespace parsers

} // namespace forecast_io

#endif // ALERTSFACTORYPARSER_HPP
