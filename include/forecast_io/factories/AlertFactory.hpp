#ifndef ALERTFACTORY_HPP
#define ALERTFACTORY_HPP

#include "../../common/AbstractFactory.hpp"      // Base class: AbstractFactory
#include "../listeners/AlertDetailsListener.hpp" // Base class: forecast_io::AlertDetailsListener

#include "../Alert.hpp"

namespace forecast_io
{

namespace factories
{

class AlertFactory : public common::AbstractFactory<Alert>,
                     public forecast_io::listeners::AlertDetailsListener
{
public:
	virtual Alert create();
	virtual void notifyDescription(const std::string& description);
	virtual void notifyExpiryTime(time_t expiryTime);
	virtual void notifyTitle(const std::string& title);
	virtual void notifyUri(const std::string& uri);

private:
	Alert result;
};

} // namespace factories

} // namespace forecast_io

#endif // ALERTFACTORY_HPP
