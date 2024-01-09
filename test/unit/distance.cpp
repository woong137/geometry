// Copyright (c) 2024 Programmers, All Rights Reserved.
// Authors: woong137

#include "geometry/distance.hpp"

#include "gtest/gtest.h"

namespace {
constexpr uint32_t kTestCount = 1000U;
}
namespace programmers::geometry {
TEST(GeometryDistance, Constructor) {
  Distance distance1;
  Distance distance2(distance1);
  Distance distance3(std::move(Distance()));
}
TEST(GeometryDistance, AssignmentOperator) {
  Distance distance1;
  Distance distance2;
  distance2 = distance1;
  Distance distance3;
  distance3 = std::move(Distance());
}
TEST(GeometryDistance, ConstructorWithInputValue) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    Distance distance1(static_cast<double>(std::rand()));
    Distance distance2(static_cast<double>(std::rand()),
                       Distance::Type::kKilometer);
    Distance distance3(static_cast<double>(std::rand()),
                       Distance::Type::kMeter);
    Distance distance4(static_cast<double>(std::rand()),
                       Distance::Type::kCentimeter);
    Distance distance5(static_cast<double>(std::rand()),
                       Distance::Type::kMillimeter);
    Distance distance6(static_cast<double>(std::rand()),
                       Distance::Type::kMicrometer);
    Distance distance7(static_cast<double>(std::rand()),
                       Distance::Type::kNanometer);
  }
}
TEST(GeometryDistance, GetValue) {
  const auto KInputValue = static_cast<double>(2038.0);

  Distance distance1(KInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2(KInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(KInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3(KInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4(KInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5(KInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6(KInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance6.GetValue(Distance::Type::kNanometer));
}
TEST(GeometryDistance, SetValue) {
  const auto KInputValue = static_cast<double>(2038.0);

  Distance distance1;
  distance1.SetValue(KInputValue, Distance::Type::kKilometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance1.GetValue(Distance::Type::kKilometer));

  Distance distance2;
  distance2.SetValue(KInputValue, Distance::Type::kMeter);
  EXPECT_DOUBLE_EQ(KInputValue, distance2.GetValue(Distance::Type::kMeter));

  Distance distance3;
  distance3.SetValue(KInputValue, Distance::Type::kCentimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance3.GetValue(Distance::Type::kCentimeter));

  Distance distance4;
  distance4.SetValue(KInputValue, Distance::Type::kMillimeter);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance4.GetValue(Distance::Type::kMillimeter));

  Distance distance5;
  distance5.SetValue(KInputValue, Distance::Type::kMicrometer);
  EXPECT_DOUBLE_EQ(KInputValue,
                   distance5.GetValue(Distance::Type::kMicrometer));

  Distance distance6;
  distance6.SetValue(KInputValue, Distance::Type::kNanometer);
  EXPECT_DOUBLE_EQ(KInputValue, distance6.GetValue(Distance::Type::kNanometer));
}

TEST(GeometryDistance, OperatorEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue * 1.0e+5, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue * 1.0e+6, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue * 1.0e+9, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo == distance_by_meter);
  EXPECT_TRUE(distance_by_kilo == distance_by_centi);
  EXPECT_TRUE(distance_by_kilo == distance_by_milli);
  EXPECT_TRUE(distance_by_kilo == distance_by_micro);
  EXPECT_TRUE(distance_by_kilo == distance_by_nano);
}

TEST(GeometryDistance, OperatorNotEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue * 1.0e+5, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue * 1.0e+6, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue * 1.0e+9, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  EXPECT_FALSE(distance_by_kilo != distance_by_meter);
  EXPECT_FALSE(distance_by_kilo != distance_by_centi);
  EXPECT_FALSE(distance_by_kilo != distance_by_milli);
  EXPECT_FALSE(distance_by_kilo != distance_by_micro);
  EXPECT_FALSE(distance_by_kilo != distance_by_nano);
}

TEST(GeometryDistance, OperatorGreaterThan) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo > distance_by_meter);
  EXPECT_TRUE(distance_by_kilo > distance_by_centi);
  EXPECT_TRUE(distance_by_kilo > distance_by_milli);
  EXPECT_TRUE(distance_by_kilo > distance_by_micro);
  EXPECT_TRUE(distance_by_kilo > distance_by_nano);
}

TEST(GeometryDistance, OperatorGreaterThanOrEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo >= distance_by_kilo);
  EXPECT_TRUE(distance_by_kilo >= distance_by_meter);
  EXPECT_TRUE(distance_by_kilo >= distance_by_centi);
  EXPECT_TRUE(distance_by_kilo >= distance_by_milli);
  EXPECT_TRUE(distance_by_kilo >= distance_by_micro);
  EXPECT_TRUE(distance_by_kilo >= distance_by_nano);
}

TEST(GeometryDistance, OperatorLessThan) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_meter < distance_by_kilo);
  EXPECT_TRUE(distance_by_centi < distance_by_kilo);
  EXPECT_TRUE(distance_by_milli < distance_by_kilo);
  EXPECT_TRUE(distance_by_micro < distance_by_kilo);
  EXPECT_TRUE(distance_by_nano < distance_by_kilo);
}

TEST(GeometryDistance, OperatorLessThanOrEqual) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue, Distance::Type::kNanometer);

  EXPECT_TRUE(distance_by_kilo <= distance_by_kilo);
  EXPECT_TRUE(distance_by_meter <= distance_by_kilo);
  EXPECT_TRUE(distance_by_centi <= distance_by_kilo);
  EXPECT_TRUE(distance_by_milli <= distance_by_kilo);
  EXPECT_TRUE(distance_by_micro <= distance_by_kilo);
  EXPECT_TRUE(distance_by_nano <= distance_by_kilo);
}


TEST(GeometryDistance, OperatorAdd) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue * 1.0e+5, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue * 1.0e+6, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue * 1.0e+9, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto distance1 = distance_by_kilo + distance_by_meter;
  const auto distance2 = distance_by_kilo + distance_by_centi;
  const auto distance3 = distance_by_kilo + distance_by_milli;
  const auto distance4 = distance_by_kilo + distance_by_micro;
  const auto distance5 = distance_by_kilo + distance_by_nano;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
  EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
  EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
  EXPECT_DOUBLE_EQ(distance4.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
  EXPECT_DOUBLE_EQ(distance5.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
}

TEST(GeometryDistance, OperatorSubtract){
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue * 1.0e+5, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue * 1.0e+6, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue * 1.0e+9, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto distance1 = distance_by_kilo - distance_by_meter;
  const auto distance2 = distance_by_kilo - distance_by_centi;
  const auto distance3 = distance_by_kilo - distance_by_milli;
  const auto distance4 = distance_by_kilo - distance_by_micro;
  const auto distance5 = distance_by_kilo - distance_by_nano;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kKilometer),
                   KInputValue * 0.0);
  EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::Type::kKilometer),
                   KInputValue * 0.0);
  EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::Type::kKilometer),
                   KInputValue * 0.0);
  EXPECT_DOUBLE_EQ(distance4.GetValue(Distance::Type::kKilometer),
                   KInputValue * 0.0);
  EXPECT_DOUBLE_EQ(distance5.GetValue(Distance::Type::kKilometer),
                   KInputValue * 0.0);
}

TEST(GeometryDistance, OperatorMultiply) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue * 1.0e+5, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue * 1.0e+6, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue * 1.0e+9, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto distance1 = distance_by_kilo * 2.0;
  const auto distance2 = distance_by_meter * 3.0;
  const auto distance3 = distance_by_nano * 5.0;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kKilometer),
                   KInputValue * 2.0);
  EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::Type::kKilometer),
                   KInputValue * 3.0);
  EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::Type::kKilometer),
                   KInputValue * 5.0);
}

TEST(GeometryDistance, OperatorDivide) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance_by_kilo(KInputValue, Distance::Type::kKilometer);
  Distance distance_by_meter(KInputValue * 1.0e+3, Distance::Type::kMeter);
  Distance distance_by_centi(KInputValue * 1.0e+5, Distance::Type::kCentimeter);
  Distance distance_by_milli(KInputValue * 1.0e+6, Distance::Type::kMillimeter);
  Distance distance_by_micro(KInputValue * 1.0e+9, Distance::Type::kMicrometer);
  Distance distance_by_nano(KInputValue * 1.0e+12, Distance::Type::kNanometer);

  const auto distance1 = distance_by_kilo / 2.0;
  const auto distance2 = distance_by_meter / 3.0;
  const auto distance3 = distance_by_nano / 5.0;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kKilometer),
                   KInputValue / 2.0);
  EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::Type::kKilometer),
                   KInputValue / 3.0);
  EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::Type::kKilometer),
                   KInputValue / 5.0);
}

TEST(GeometryDistance, OperatorAddAssignment) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance1(KInputValue, Distance::Type::kKilometer);
  Distance distance2(KInputValue * 2, Distance::Type::kMeter);

  distance1 += distance2;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kMeter),
                   KInputValue * 1002);
}

TEST(GeometryDistance, OperatorSubtractAssignment) {
  const auto KInputValue = static_cast<double>(2038.0);
  Distance distance1(KInputValue, Distance::Type::kKilometer);
  Distance distance2(KInputValue * 2, Distance::Type::kMeter);

  distance1 -= distance2;

  EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::Type::kMeter),
                   KInputValue * 998);
}
}  // namespace programmers::geometry
