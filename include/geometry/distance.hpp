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

 protected:
 private:
  int64_t nanometer_{0};  ///< Nanometer
};  // class Distance
}  // namespace programmers::geometry

#endif
