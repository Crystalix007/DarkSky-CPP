#ifndef FLAGSLISTENER_HPP
#define FLAGSLISTENER_HPP

namespace forecast_io
{

// Forward declarations
class Flags;

namespace listeners
{

class FlagsListener
{
public:
	virtual ~FlagsListener() = default;

	virtual void notifyFlags(Flags& flags);
};

} // namespace listeners
} // namespace forecast_io

#endif // FLAGSLISTENER_HPP
