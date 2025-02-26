#ifndef NOTIFYINGSYNCHRONICDATAPOINTPARSER_HPP
#define NOTIFYINGSYNCHRONICDATAPOINTPARSER_HPP

#include "../../common/Notifier.hpp"                 // Base class: Notifier
#include "../../json/AbstractJsonStateMapParser.hpp" // Base class: json::AbstractJsonStateMapParser

#include "DataPointAttribute.hpp"
#include "DataPointAttributeDefaultNameMapHolder.hpp"

namespace forecast_io
{

// Forward declarations
namespace listeners
{
class SynchronicDataPointDetailsListener;
}

namespace parsers
{

class NotifyingSynchronicDataPointParser
    : public json::AbstractJsonStateMapParser<DataPointAttribute>,
      public common::Notifier<listeners::SynchronicDataPointDetailsListener>
{
public:
	NotifyingSynchronicDataPointParser(
	    listeners::SynchronicDataPointDetailsListener* pListener,
	    const DataPointAttributeNameMap& attributeNames =
	        *DataPointAttributeDefaultNameMapHolder::getInstance()) noexcept;

protected:
	virtual void parseAttribute(const DataPointAttribute& attribute, json_object* const& pValue);
};

} // namespace parsers

} // namespace forecast_io

#endif // NOTIFYINGSYNCHRONICDATAPOINTPARSER_HPP
