#ifndef CONSOLE_WRITING_HPP
#define CONSOLE_WRITING_HPP

#include <sstream>
#include <string>

namespace console_weather
{
namespace writers
{

constexpr char MAIN_SECTION_HEADER_PADDING = '=';
constexpr char SUBSECTION_HEADER_PADDING = '-';

std::string createPaddedHeader(const std::string& prefix,
                               const std::stringstream::char_type paddingSymbol, int resultLength);

std::string createHeaderSeparator(const std::stringstream::char_type symbol, int times);

} // namespace writers

} // namespace console_weather

#endif // CONSOLE_HPP
