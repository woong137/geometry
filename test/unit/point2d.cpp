// Copyright (c) Programmers, All Rights Reserved.
// Authors: woong137

#include "geometry/point2d.hpp"

#include <cmath>
#include <stdexcept>

#include "gtest/gtest.h"

namespace {
constexpr uint32_t kTestCount = 1000U;
}

namespace programmers::geometry {
TEST(GeometryPoint2D, Constructor) {
  Point2D point1;
  Point2D point2(0.0, 1.0);
  Point2D point3(point2);
  Point2D point4(std::move(Point2D()));
}

TEST(GeometryPoint2D, AssignmentOperator) {
  Point2D point1;
  auto Point2 = point1;
  auto point3 = std::move(Point2D());
}

TEST(GeometryPoint2D, CalculateDistance) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
                         (kSourceY - kTargetY) * (kSourceY - kTargetY)),
                    source.CalculateDistance(target));
  }
}

TEST(GeometryPoint2D, StaticCalculateDistance) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_FLOAT_EQ(sqrt((kSourceX - kTargetX) * (kSourceX - kTargetX) +
                         (kSourceY - kTargetY) * (kSourceY - kTargetY)),
                    Point2D::CalculateDistance(source, target));
  }
}

TEST(GeometryPoint2D, GetX) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);

    EXPECT_FLOAT_EQ(kSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, GetY) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);

    EXPECT_FLOAT_EQ(kSourceY, source.GetY());
  }
}

TEST(GeometryPoint2D, SetX) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());

    Point2D source;
    source.SetX(kSourceX);

    EXPECT_FLOAT_EQ(kSourceX, source.GetX());
  }
}

TEST(GeometryPoint2D, SetY) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source;
    source.SetY(kSourceY);

    EXPECT_FLOAT_EQ(kSourceY, source.GetY());
  }
}

TEST(GeometryPoint2D, operatorAdd) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    Point2D result = source + target;

    EXPECT_FLOAT_EQ(kSourceX + kTargetX, result.GetX());
    EXPECT_FLOAT_EQ(kSourceY + kTargetY, result.GetY());
  }
}

TEST(GeometryPoint2D, operatorSubtract) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    Point2D result = source - target;

    EXPECT_FLOAT_EQ(kSourceX - kTargetX, result.GetX());
    EXPECT_FLOAT_EQ(kSourceY - kTargetY, result.GetY());
  }
}

TEST(GeometryPoint2D, operatorAddAssign) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    source += target;

    EXPECT_FLOAT_EQ(kSourceX + kTargetX, source.GetX());
    EXPECT_FLOAT_EQ(kSourceY + kTargetY, source.GetY());
  }
}

TEST(GeometryPoint2D, operatorSubtractAssign) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    source -= target;

    EXPECT_FLOAT_EQ(kSourceX - kTargetX, source.GetX());
    EXPECT_FLOAT_EQ(kSourceY - kTargetY, source.GetY());
  }
}
}  // namespace programmers::geometry
