#ifndef SYNCHRONICDATAPOINTDETAILSLISTENER_HPP
#define SYNCHRONICDATAPOINTDETAILSLISTENER_HPP

#include "SingleDataPointDetailsListener.hpp" // Base class: forecast_io::listeners::SingleDataPointDetailsListener

namespace forecast_io
{

namespace listeners
{

class SynchronicDataPointDetailsListener
    : public forecast_io::listeners::SingleDataPointDetailsListener
{

public:
	virtual void notifyNearestStormBearing(double bearing);
	virtual void notifyNearestStormDistance(double distance);
};

} // namespace listeners

} // namespace forecast_io

#endif // SYNCHRONICDATAPOINTDETAILSLISTENER_HPP
