#ifndef ALERTCONSOLEWRITER_HPP
#define ALERTCONSOLEWRITER_HPP

#include <string>

// Forward declarations
namespace forecast_io
{

class Alert;
}

namespace console_weather
{
namespace writers
{

class AlertConsoleWriter
{
public:
	AlertConsoleWriter(int consoleWidth) noexcept;

	void write(const forecast_io::Alert& value, std::ostream& output);

private:
	std::string headerSeparator;
};

} // namespace writers
} // namespace console_weather

#endif // ALERTCONSOLEWRITER_HPP
