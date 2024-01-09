/**
 * @file geometry/point2d.cpp
 * @author woong137 (woong137137@gmail.com)
 * @brief Point class developments with 2-dimension
 * @version 1.0.1
 * @date 2023-01-09
 * @copyright Copyright (c) Programmers, All Rights Reserved.
 */

// Copyright (c) Programmers, All Rights Reserved.
// Authors: woong137

#include "geometry/point2d.hpp"

#include <cmath>

namespace programmers::geometry {
Point2D::Point2D(double input_x, double input_y) : x_(input_x), y_(input_y) {}

auto Point2D::CalculateDistance(const Point2D& target) const -> double {
  return Point2D::CalculateDistance(*this, target);
}

auto Point2D::CalculateDistance(const Point2D& lhs,
                                const Point2D& rhs) -> double {
  return std::sqrt(std::pow((lhs.x_ - rhs.x_), 2) +
                   std::pow((lhs.y_ - rhs.y_), 2));
}

auto Point2D::GetX() const -> double { return x_; }
auto Point2D::GetY() const -> double { return y_; }

auto Point2D::SetX(double input_x) -> void { x_ = input_x; }
auto Point2D::SetY(double input_y) -> void { y_ = input_y; }

auto Point2D::operator+(const Point2D& other) const -> Point2D {
  return {x_ + other.x_, y_ + other.y_};
}
auto Point2D::operator-(const Point2D& other) const -> Point2D {
  return {x_ - other.x_, y_ - other.y_};
}
auto Point2D::operator+=(const Point2D& other) -> Point2D& {
  x_ += other.x_;
  y_ += other.y_;
  return *this;
}
auto Point2D::operator-=(const Point2D& other) -> Point2D& {
  x_ -= other.x_;
  y_ -= other.y_;
  return *this;
}

}  // namespace programmers::geometry
