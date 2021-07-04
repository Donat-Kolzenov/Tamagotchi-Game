// Convert header
// Copyright (c) Donat Kolzenov.


/*
 * this header uses standard libraries <sstream>
 * <sstream> is used for std::string and std::stringstream
 */

#ifndef CONVERT_H
#define CONVERT_H
#include <sstream>

namespace myConvert
{
  std::string IntToString(const int value);
}

#endif  // CONVERT_H