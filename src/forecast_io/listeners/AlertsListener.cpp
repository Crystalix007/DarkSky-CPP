#include "forecast_io/listeners/AlertsListener.hpp"

namespace forecast_io
{

// Forward declarations
class Alert;

namespace listeners
{

void AlertsListener::notifyAlert(Alert& alert)
{
	(void)alert; /*Avoid "unused parameter" warning*/
}

} // namespace listeners
} // namespace forecast_io
