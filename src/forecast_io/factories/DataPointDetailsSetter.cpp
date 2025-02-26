#include "forecast_io/factories/DataPointDetailsSetter.hpp"

namespace forecast_io
{

namespace factories
{

DataPointDetailsSetter::DataPointDetailsSetter(DataPoint& instance) noexcept
    : common::InstanceReferenceHolder<DataPoint>(instance)
{
}

void DataPointDetailsSetter::notifyCloudCover(double cloudCover)
{
	getInstance().setCloudCover(cloudCover);
}

void DataPointDetailsSetter::notifyDewPoint(double dewPoint)
{
	getInstance().setDewPoint(dewPoint);
}

void DataPointDetailsSetter::notifyHumidity(double humidity)
{
	getInstance().setHumidity(humidity);
}

void DataPointDetailsSetter::notifyIcon(const std::string& name)
{
	getInstance().getOverview().setIconName(name);
}

void DataPointDetailsSetter::notifyOzone(double ozone)
{
	getInstance().setOzone(ozone);
}

void DataPointDetailsSetter::notifyPrecipitationIntensity(double intensity)
{
	getInstance().getPrecipitation().setIntensity(intensity);
}

void DataPointDetailsSetter::notifyPrecipitationProbability(double probability)
{
	getInstance().getPrecipitation().setProbability(probability);
}

void DataPointDetailsSetter::notifyPrecipitationType(const std::string& type)
{
	getInstance().getPrecipitation().setType(type);
}

void DataPointDetailsSetter::notifyPressure(double pressure)
{
	getInstance().setPressure(pressure);
}

void DataPointDetailsSetter::notifySummary(const std::string& summary)
{
	getInstance().getOverview().setSummary(summary);
}

void DataPointDetailsSetter::notifyTime(time_t time)
{
	getInstance().setTime(time);
}

void DataPointDetailsSetter::notifyUVIndex(double uvIndex)
{
	getInstance().setUVIndex(uvIndex);
}

void DataPointDetailsSetter::notifyVisibility(double visibility)
{
	getInstance().setVisibility(visibility);
}

void DataPointDetailsSetter::notifyWindBearing(double bearing)
{
	getInstance().getWind().setDirection(bearing);
}

void DataPointDetailsSetter::notifyWindGust(double gust)
{
	getInstance().getWind().setDirection(gust);
}

void DataPointDetailsSetter::notifyWindSpeed(double speed)
{
	getInstance().getWind().setMagnitude(speed);
}

} // namespace factories

} // namespace forecast_io
