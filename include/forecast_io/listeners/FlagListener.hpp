#ifndef FLAGLISTENER_HPP
#define FLAGLISTENER_HPP

#include <unordered_map>
#include <unordered_set>

#include "../../math/MeasurementSystem.hpp"

namespace forecast_io
{
namespace listeners
{

class FlagListener
{
public:
	virtual ~FlagListener() = default;

	virtual void notifyDarkskyUnavailable(bool darkskyUnavailable);
	virtual void notifySources(std::unordered_set<std::string>& sources);
	virtual void notifyStations(std::unordered_multimap<std::string, std::string>& stations);
	virtual void notifyMetnoLicense(bool metnoLicense);
	virtual void notifyUnits(math::MeasurementSystem units);
};

} // namespace listeners
} // namespace forecast_io

#endif // FLAGLISTENER_HPP
