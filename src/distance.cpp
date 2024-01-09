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
constexpr int64_t kKilometerToNanometer{static_cast<int64_t>(1.0e+12)};
constexpr int64_t kMeterToNanometer{static_cast<int64_t>(1.0e+9)};
constexpr int64_t kCentimeterToNanometer{static_cast<int64_t>(1.0e+7)};
constexpr int64_t kMillimeterToNanometer{static_cast<int64_t>(1.0e+6)};
constexpr int64_t kMicrometerToNanometer{static_cast<int64_t>(1.0e+3)};
constexpr double kNanometerToKilometer{static_cast<double>(1.0e-12)};
constexpr double kNanometerToMeter{static_cast<double>(1.0e-9)};
constexpr double kNanometerToCentimeter{static_cast<double>(1.0e-7)};
constexpr double kNanometerToMillimeter{static_cast<double>(1.0e-6)};
constexpr double kNanometerToMicrometer{static_cast<double>(1.0e-3)};

auto ScaleDistanceToNanometer(double input_value,
                              programmers::geometry::Distance::Type input_type)
    -> int64_t {
  int64_t result{static_cast<int64_t>(input_value)};
  if (input_type == programmers::geometry::Distance::Type::kKilometer) {
    result = static_cast<int64_t>(input_value * kKilometerToNanometer);
  } else if (input_type == programmers::geometry::Distance::Type::kMeter) {
    result = static_cast<int64_t>(input_value * kMeterToNanometer);
  } else if (input_type == programmers::geometry::Distance::Type::kCentimeter) {
    result = static_cast<int64_t>(input_value * kCentimeterToNanometer);
  } else if (input_type == programmers::geometry::Distance::Type::kMillimeter) {
    result = static_cast<int64_t>(input_value * kMillimeterToNanometer);
  } else if (input_type == programmers::geometry::Distance::Type::kMicrometer) {
    result = static_cast<int64_t>(input_value * kMicrometerToNanometer);
  } else if (input_type == programmers::geometry::Distance::Type::kNanometer) {
    result = static_cast<int64_t>(input_value);
  }
  return result;
}
}  // namespace

namespace programmers::geometry {

Distance::Distance(double input_value, Type input_type)
    : nanometer_(ScaleDistanceToNanometer(input_value, input_type)) {}

auto Distance::GetValue(const Type &input_type) const -> double {
  auto result{static_cast<double>(nanometer_)};
  if (input_type == programmers::geometry::Distance::Type::kKilometer) {
    result = result * kNanometerToKilometer;
  } else if (input_type == programmers::geometry::Distance::Type::kMeter) {
    result = result * kNanometerToMeter;
  } else if (input_type == programmers::geometry::Distance::Type::kCentimeter) {
    result = result * kNanometerToCentimeter;
  } else if (input_type == programmers::geometry::Distance::Type::kMillimeter) {
    result = result * kNanometerToMillimeter;
  } else if (input_type == programmers::geometry::Distance::Type::kMicrometer) {
    result = result * kNanometerToMicrometer;
  }
  return result;
}

auto Distance::SetValue(double input_value, Type input_type) -> void {
  nanometer_ = ScaleDistanceToNanometer(input_value, input_type);
}

auto Distance::operator==(const Distance &other) const -> bool {
  return (nanometer_ == other.nanometer_);
}

auto Distance::operator!=(const Distance &other) const -> bool {
  return (nanometer_ != other.nanometer_);
}

auto Distance::operator<(const Distance &other) const -> bool {
  return (nanometer_ < other.nanometer_);
}

auto Distance::operator<=(const Distance &other) const -> bool {
  return (nanometer_ <= other.nanometer_);
}

auto Distance::operator>(const Distance &other) const -> bool {
  return (nanometer_ > other.nanometer_);
}

auto Distance::operator>=(const Distance &other) const -> bool {
  return (nanometer_ >= other.nanometer_);
}
auto Distance::operator+(const Distance &other) const -> Distance {
  return Distance{static_cast<double>(nanometer_ + other.nanometer_),
                  Type::kNanometer};
}

auto Distance::operator-(const Distance &other) const -> Distance {
  return Distance{static_cast<double>(nanometer_ - other.nanometer_),
                  Type::kNanometer};
}

auto Distance::operator*(double scale) const -> Distance {
  return Distance{static_cast<double>(nanometer_ * scale), Type::kNanometer};
}

auto Distance::operator/(double scale) const -> Distance {
  return Distance{static_cast<double>(nanometer_ / scale), Type::kNanometer};
}

auto Distance::operator+=(const Distance &other) -> void {
  nanometer_ += other.nanometer_;
}

auto Distance::operator-=(const Distance &other) -> void {
  nanometer_ -= other.nanometer_;
}
}  // namespace programmers::geometry
