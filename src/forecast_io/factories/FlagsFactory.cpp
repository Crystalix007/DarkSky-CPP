#include "forecast_io/factories/FlagsFactory.hpp"

#include "forecast_io/Flags.hpp"

namespace forecast_io
{
namespace factories
{

FlagsFactory::FlagsFactory(math::MeasurementSystem defaultUnits) noexcept
    : defaultUnits(defaultUnits), result(defaultUnits)
{
}

Flags FlagsFactory::create()
{
	return result;
}

void FlagsFactory::notifyDarkskyUnavailable(bool darkskyUnavailable)
{
	result.setDarkskyUnavailable(darkskyUnavailable);
}

void FlagsFactory::notifyMetnoLicense(bool metnoLicense)
{
	result.setMetnoLicense(metnoLicense);
}

void FlagsFactory::notifySources(std::unordered_set<std::string>& sources)
{
	result.setSources(sources);
}

void FlagsFactory::notifyNearestStation(double nearestStation)
{
	result.setNearestStation(nearestStation);
}

void FlagsFactory::notifyStations(std::unordered_multimap<std::string, std::string>& stations)
{
	result.setStations(stations);
}

void FlagsFactory::notifyUnits(math::MeasurementSystem units)
{
	result.setUnits(units);
}

} // namespace factories

} // namespace forecast_io
