/**
 *@file geometry/distance.hpp
 *@author woong137
 *@brief Point class declaration with 2-dimension
 *@version 1.0.1
 *@date 2023-01-09
 *@copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) 2023 Programmers, All Rights Reserved.
// Authors : woong137

#ifndef PROGRAMMERS__GEOMETRY__DISTANCE_HPP_
#define PROGRAMMERS__GEOMETRY__DISTANCE_HPP_

namespace programmers::geometry {
/**
 * @brief
 */
class Distance {
 public:
  /**
   * @brief
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

  Distance& operator=(const Distance&) = delete;
  Distance& operator=(Distance&&) = delete;
  /**
   * @brief Construct a new Distance object
   * @param input_value
   * @param input_type
   */
  explicit Distance(double input_value, Type input_type = Type ::kMeter);

  /**
   * @brief Construct a new Distance object
   * @param other
   */
  Distance(const Distance& other) = default;
  /**
   * @brief Construct a new Distance object
   */
  Distance(Distance&& other) noexcept = default;

  virtual ~Distance() = default;

 protected:
 private:
};
}  // namespace programmers::geometry

#endif
