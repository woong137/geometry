/**
 * @file geometry/distance.hpp
 * @author woong137 (woong137137@gmail.com)
 * @brief Distance class declaration for abstracting distance
 * @version 1.0.0
 * @date 2023-01-09
 * @copyright Copyright (c) 2023 Programmers, All Rights Reserved.
 */

// Copyright (c) Programmers, All Rights Reserved.
// Authors: woong137

#ifndef PROGRAMMERS__GEOMETRY__DISTANCE_HPP_
#define PROGRAMMERS__GEOMETRY__DISTANCE_HPP_

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

 protected:
 private:
}; // class Distance
}  // namespace programmers::geometry

#endif
