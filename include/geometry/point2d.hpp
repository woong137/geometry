/**
 * @file geometry/point2d.hpp
 * @author woong137 (woong137137@gmail.com)
 * @brief Point class declaration with 2-dimension
 * @version 1.0.0
 * @date 2023-12-21
 * @copyright Copyright (c) Programmers, All Rights Reserved.
 */

// Copyright (c) Programmers, All Rights Reserved.
// Authors: woong137

#ifndef HOLYGROUND__GEOMETRY__POINT_2D_HPP_
#define HOLYGROUND__GEOMETRY__POINT_2D_HPP_

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
  Point2D(double x, double y);

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
  auto CalculateDistance(const Point2D& target) const -> double;

  /**
   * @brief Calculate distance between lhs point and rhs point
   * @param lhs Left hand side Point2D object
   * @param rhs Right hand side Point2D object
   * @return double Euclidean distance between lhs point and rhs point
   */
  [[nodiscard]] static auto CalculateDistance(const Point2D& lhs,
                                              const Point2D& rhs) -> double;

  /**
   * @brief Set x coordinate value
   * @param x Double type input x coordinate value
   */
  void SetX(double x);
  /**
   * @brief Set y coordinate value
   * @param y Double type input y coordinate value
   */
  void SetY(double y);

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

  auto operator+(const Point2D& other) const -> Point2D;
  auto operator-(const Point2D& other) const -> Point2D;

  auto operator+=(const Point2D& other) -> Point2D&;
  auto operator-=(const Point2D& other) -> Point2D&;

  auto operator*(double scalar) const -> Point2D;
  auto operator/(double scalar) const -> Point2D;

  auto operator==(const Point2D& other) const -> bool;
  auto operator!=(const Point2D& other) const -> bool;

 protected:
 private:
  double x_{0.0};  ///< x coordinate
  double y_{0.0};  ///< y coordinate
};

}  // namespace programmers::geometry

#endif  // HOLYGROUND__GEOMETRY__POINT_2D_HPP_