/**
 * @file geometry/distance.hpp
 * @author woong137 (woong137137@gmail.com)
 * @brief Distance class declaration for abstracting distance
 * @version 1.0.0
 * @date 2024-01-09
 * @copyright Copyright (c) 2024 Programmers, All Rights Reserved.
 */

// Copyright (c) 2024 Programmers, All Rights Reserved.
// Authors: woong137

#ifndef PROGRAMMERS__GEOMETRY__DISTANCE_HPP_
#define PROGRAMMERS__GEOMETRY__DISTANCE_HPP_

#include <cstdint>
namespace programmers::geometry {
/**
 * @brief The class for abstracting distance
 */
class Distance {
 public:
  /**
   * @brief The enum class for distance type
   */
  enum class Type {
    kKilometer = 0,
    kMeter = 1,
    kCentimeter = 2,
    kMillimeter = 3,
    kMicrometer = 4,
    kNanometer = 5
  };
  /**
   * @brief Construct a new Distance object
   */
  Distance() = default;

  explicit Distance(double input_value, Type input_type=Type::kMeter);

  /**
   * @brief The copy constructor
   * @param other The other distance object
   */
  Distance(const Distance& other) = default;
  /**
   * @brief The move constructor
   * @param other The other distance object
   */
  Distance(Distance&& other) = default;
  /**
   * @brief Destroy the Distance object
   */
  virtual ~Distance() = default;
  /**
   * @brief The copy assignment operator
   * @param other The other distance object
   * @return Distance& The reference of distance object
   */
  auto operator=(const Distance& other) -> Distance& = default;
  /**
   * @brief The move assignment operator
   * @param other The other distance object
   * @return Distance& The reference of distance object
   */
  auto operator=(Distance&& other) -> Distance& = default;
  /**
   * @brief Get the Distance value for distance type
   * @param input_type The input distance type
   * @return double The value of distance
   */
  [[nodiscard]] auto GetValue(const Type& input_type) const -> double;
  /**
   * @brief Set the Distance value for distance type
   * @param input_value The input distance value
   * @param input_type The input distance type
   * @return void
   */
  auto SetValue(double input_value, Type input_type=Type::kMeter) -> void;

  /**
   * @brief Compare with other distance object for equality
   * @param other The other distance object
   * @return true If equal
   * @return false If not equal
   */
  auto operator==(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for inequality
   * @param other The other distance object
   * @return true If not equal
   * @return false If equal
   */
  auto operator!=(const Distance& other) const -> bool;

  /**
   * @brief Compare with other distance object for less than
   * @param other The other distance object
   * @return true If less than
   * @return false If not less than
   */
  auto operator<(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for less than or equal
   * @param other The other distance object
   * @return true If less than or equal
   * @return false If not less than or equal
   */
  auto operator<=(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for greater than
   * @param other The other distance object
   * @return true If greater than
   * @return false If not greater than
   */
  auto operator>(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for greater than or equal
   * @param other The other distance object
   * @return true If greater than or equal
   * @return false If not greater than or equal
   */
  auto operator>=(const Distance& other) const -> bool;
  /**
   * @brief Add other distance object
   * @param other The other distance object
   * @return Distance The result of addition
   */
  auto operator+(const Distance& other) const -> Distance;
  /**
   * @brief Subtract other distance object
   * @param other The other distance object
   * @return Distance The result of subtraction
   */
  auto operator-(const Distance& other) const -> Distance;
  /**
   * @brief Multiply by scale
   * @param scale The scale
   * @return Distance The result of multiplication
   */
  auto operator*(double scale) const -> Distance;
  /**
   * @brief Divide by scale
   * @param scale The scale
   * @return Distance The result of division
   */
  auto operator/(double scale) const -> Distance;
  /**
   * @brief Add and assign other distance object
   * @param other The other distance object
   * @return Distance The result of addition and assignment
   */
  auto operator+=(const Distance& other) -> void;
  /**
   * @brief Subtract and assign other distance object
   * @param other The other distance object
   * @return Distance The result of subtraction and assignment
   */
  auto operator-=(const Distance& other) -> void;

 protected:
 private:
  int64_t nanometer_{0};  ///< Nanometer
};  // class Distance
}  // namespace programmers::geometry

#endif
