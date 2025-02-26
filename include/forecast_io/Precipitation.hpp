#ifndef PRECIPITATION_HPP
#define PRECIPITATION_HPP

#include <ostream>
#include <string>

namespace forecast_io
{

class Precipitation
{
public:
	Precipitation() = default;
	Precipitation(double intensity, double probability, std::string type) noexcept;

	// Constant getters ---------------------------------------------------------
	double getIntensity() const
	{
		return intensity;
	}

	double getProbability() const
	{
		return probability;
	}

	std::string getType() const
	{
		return type;
	}

	// Setters ------------------------------------------------------------------
	void setIntensity(double intensity)
	{
		this->intensity = intensity;
	}

	void setProbability(double probability)
	{
		this->probability = probability;
	}

	void setType(std::string type)
	{
		this->type = type;
	}

private:
	double intensity;
	double probability;
	std::string type;
};

} // namespace forecast_io

#endif // PRECIPITATION_HPP
