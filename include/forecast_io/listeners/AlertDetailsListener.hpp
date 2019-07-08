#ifndef ALERTDETAILSLISTENER_HPP
#define ALERTDETAILSLISTENER_HPP

#include <ctime>
#include <string>

namespace forecast_io
{
namespace listeners
{

class AlertDetailsListener
{
public:
	virtual ~AlertDetailsListener() = default;

	virtual void notifyTitle(const std::string& title);
	virtual void notifyExpiryTime(time_t expiryTime);
	virtual void notifyDescription(const std::string& description);
	virtual void notifyUri(const std::string& uri);
};

} // namespace listeners
} // namespace forecast_io

#endif // ALERTDETAILSLISTENER_HPP
