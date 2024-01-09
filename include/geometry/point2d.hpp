/**
 * @file geometry/point2d.hpp
 * @author woong137 (woong137137@gmail.com)
 * @brief Point class declaration with 2-dimension
 * @version 1.0.1
 * @date 2023-01-09
 * @copyright Copyright (c) Programmers, All Rights Reserved.
 */

// Copyright (c) Programmers, All Rights Reserved.
// Authors: woong137

#ifndef PROGRAMMERS__GEOMETRY__POINT_2D_HPP_
#define PROGRAMMERS__GEOMETRY__POINT_2D_HPP_

namespace programmers::geometry {
/**
 * @brief Point class with 2-dimension
 */
class Point2D {
 public:
  /**
   * @brief Construct a new Point2D object
   */
  Point2D() = default;
  /**
   * @brief Construct a new Point2D object with x, y value
   * @param x Double type x coordinate value
   * @param y Double type y coordinate value
   */
  Point2D(double input_x, double input_y);

  /**
   * @brief Copy construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(const Point2D& other) = default;
  /**
   * @brief Move construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(Point2D&& other) noexcept = default;

  /**
   * @brief Destroy the Point2D object
   */
  virtual ~Point2D() = default;

  /**
   * @brief Copy assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator=(const Point2D& other) -> Point2D& = default;
  /**
   * @brief Move assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator=(Point2D&& other) -> Point2D& = default;

  /**
   * @brief Calculate distance between this point and target point
   * @param target Other Point2D object to calculate distance
   * @return double Euclidean distance between this point and target point
   */
  [[nodiscard]] auto CalculateDistance(const Point2D& target) const -> double;

  /**
   * @brief Calculate distance between lhs point and rhs point
   * @param lhs Left hand side Point2D object
   * @param rhs Right hand side Point2D object
   * @return double Euclidean distance between lhs point and rhs point
   */
  [[nodiscard]] static auto CalculateDistance(const Point2D& lhs,
                                              const Point2D& rhs) -> double;

  /**
   * @brief Calculate distance between lhs point and rhs point
   * @param lhs Left hand side Point2D object
   * @param rhs Right hand side Point2D object
   * @return double Euclidean distance between lhs point and rhs point
   */
  /**
   * @brief Set x coordinate value
   * @param coordinateX Double type input x coordinate value
   */
  void SetX(double input_x);
  /**
   * @brief Set y coordinate value
   * @param coordinateY Double type input y coordinate value
   */
  void SetY(double input_y);

  /**
   * @brief Get x coordinate value of this point
   * @return double x coordinate value of this point
   */
  [[nodiscard]] auto GetX() const -> double;
  /**
   * @brief Get y coordinate value of this point
   * @return double y coordinate value of this point
   */
  [[nodiscard]] auto GetY() const -> double;

  /**
   * @brief Add other point to this point
   * @param other
   * @return Point2D Result of addition
   */
  auto operator+(const Point2D& other) const -> Point2D;
  /**
   * @brief Subtract other point from this point
   * @param other
   * @return Point2D Result of subtraction
   */
  auto operator-(const Point2D& other) const -> Point2D;

  /**
   * @brief Add other point to this point and assign to this point
   * @param other
   * @return Point Result of addition and assignment
   */
  auto operator+=(const Point2D& other) -> Point2D&;
  /**
   * @brief Subtract other point from this point and assign to this point
   * @param other
   * @return Point Result of subtraction and assignment
   */
  auto operator-=(const Point2D& other) -> Point2D&;

  /**
   * @brief Multiply this point with scalar
   * @param scalar
   * @return Point2D Result of multiplication
   */
  auto operator*(double scalar) const -> Point2D;
  /**
   * @brief Divide this point with scalar
   * @param scalar
   * @return Point2D Result of division
   */
  auto operator/(double scalar) const -> Point2D;

  /**
   * @brief check if this point is equal to other point
   * @param other
   * @return true if this point is equal to other point
   * @return false if this point is not equal to other point
   */
  auto operator==(const Point2D& other) const -> bool;

  /**
   * @brief check if this point is not equal to other point
   * @param other
   * @return true if this point is not equal to other point
   * @return false if this point is equal to other point
   */
  auto operator!=(const Point2D& other) const -> bool;

 protected:
 private:
  double x_{0.0};  ///< x coordinate
  double y_{0.0};  ///< y coordinate
};

}  // namespace programmers::geometry

#endif
