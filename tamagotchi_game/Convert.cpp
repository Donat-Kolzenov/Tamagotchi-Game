#include <sstream>        // for std::string and std::stringstream
#include "Convert.h"


namespace myConvert
{
  std::string IntToString(const int value)
  {
    std::stringstream convert;
    std::string string_value;

    convert << value;
    convert >> string_value;

    return string_value;
  }
}