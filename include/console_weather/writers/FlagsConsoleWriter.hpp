#ifndef FLAGSCONSOLEWRITER_HPP
#define FLAGSCONSOLEWRITER_HPP

#include <ostream>

// Forward declarations
namespace forecast_io
{
class Flags;
}

namespace console_weather
{
namespace writers
{

class FlagsConsoleWriter
{

public:
	virtual ~FlagsConsoleWriter() = default;
	virtual void write(const forecast_io::Flags& value, std::ostream& output);
};

} // namespace writers
} // namespace console_weather

#endif // FLAGSCONSOLEWRITER_HPP
