/**
 * @file geometry/distance.cpp
 * @author woong137 (woong137137@gmail.com)
 * @brief Distance class declaration for abstracting distance
 * @version 1.0.0
 * @date 2024-01-09
 * @copyright Copyright (c) 2024 Programmers, All Rights Reserved.
 */

// Copyright (c) 2024 Programmers, All Rights Reserved.
// Authors: woong137

#include "geometry/distance.hpp"

#include <cstdint>
#include <sys/stat.h>

namespace {
auto ScaleDistanceToNanometer(double input_value,
                              programmers::geometry::Distance::Type input_type)
    -> int64_t {
  int64_t result{static_cast<int64_t>(input_value)};
  if (input_type == programmers::geometry::Distance::Type::kKilometer) {
    result = static_cast<int64_t>(input_value * 1.0e+12);
  } else if (input_type == programmers::geometry::Distance::Type::kMeter) {
    result = static_cast<int64_t>(input_value * 1.0e+9);
  } else if (input_type == programmers::geometry::Distance::Type::kCentimeter) {
    result = static_cast<int64_t>(input_value * 1.0e+7);
  } else if (input_type == programmers::geometry::Distance::Type::kMillimeter) {
    result = static_cast<int64_t>(input_value * 1.0e+6);
  } else if (input_type == programmers::geometry::Distance::Type::kMicrometer) {
    result = static_cast<int64_t>(input_value * 1.0e+3);
  }
  return result;
}
}  // namespace

namespace programmers::geometry {

Distance::Distance(double input_value, Type input_type)
    : nanometer_(ScaleDistanceToNanometer(input_value, input_type)) {}
}  // namespace programmers::geometry
