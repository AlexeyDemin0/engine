/**
 * SPDX-License-Identifier: MIT
 *
 * @file test_Vector2.cpp
 * @brief Tests for Vector2 class
 *
 * @todo Add tests for boundary conditions
 *
 * @author Alexey Demin (AlexeyDeminA@gmail.com)
 */

#include <gtest/gtest.h>

#include <core/math/Vector2.h>
#include <string>

using namespace Engine::Core::Math;

/* ------------------------------------------- Other ------------------------------------------- */
TEST(Vector2Test, Sizeof)
{
  EXPECT_TRUE(sizeof(Vector2f) == 2 * sizeof(float));
  EXPECT_TRUE(sizeof(Vector2d) == 2 * sizeof(double));
}

/* ---------------------------------------- Constructors --------------------------------------- */
TEST(Vector2Test, ConstructorDefault)
{
  Vector2f v;

  EXPECT_FLOAT_EQ(v.x, 0.0f);
  EXPECT_FLOAT_EQ(v.y, 0.0f);
}

TEST(Vector2Test, ConstructorOneParam)
{
  Vector2f v(1.0f);

  EXPECT_FLOAT_EQ(v.x, 1.0f);
  EXPECT_FLOAT_EQ(v.y, 0.0f);
}

TEST(Vector2Test, ConstructorTwoParam)
{
  Vector2f v(1.0f, 2.0f);

  EXPECT_FLOAT_EQ(v.x, 1.0f);
  EXPECT_FLOAT_EQ(v.y, 2.0f);
}

/* --------------------------------- Copy and move constructors -------------------------------- */
TEST(Vector2Test, ConstructorCopy)
{
  Vector2f v(1.0f, 2.0f);

  Vector2f copy(v);

  EXPECT_FLOAT_EQ(copy.x, 1.0f);
  EXPECT_FLOAT_EQ(copy.y, 2.0f);
}

TEST(Vector2Test, ConstructorMove)
{
  Vector2f v(1.0f, 2.0f);

  Vector2f copy(std::move(v));

  EXPECT_FLOAT_EQ(copy.x, 1.0f);
  EXPECT_FLOAT_EQ(copy.y, 2.0f);
}

/* ---------------------------------- Copy and move operators ---------------------------------- */
TEST(Vector2Test, OperatorCopyAssignment)
{
  Vector2f v(1.0f, 2.0f);

  Vector2f copy = v;

  EXPECT_FLOAT_EQ(copy.x, 1.0f);
  EXPECT_FLOAT_EQ(copy.y, 2.0f);
}

TEST(Vector2Test, OperatorMoveAssignment)
{
  Vector2f v(1.0f, 2.0f);

  Vector2f copy = std::move(v);

  EXPECT_FLOAT_EQ(copy.x, 1.0f);
  EXPECT_FLOAT_EQ(copy.y, 2.0f);
}

/* ------------------------------------ Arithmetic operators ----------------------------------- */
TEST(Vector2Test, OperatorPlus)
{
  Vector2f v1(1.0f, 2.0f);
  Vector2f v2(3.0f, 4.0f);

  Vector2f result = v1 + v2;

  EXPECT_FLOAT_EQ(result.x, 4.0f);
  EXPECT_FLOAT_EQ(result.y, 6.0f);
}

TEST(Vector2Test, OperatorMinus)
{
  Vector2f v1(1.0f, 2.0f);
  Vector2f v2(3.0f, 4.0f);

  Vector2f result = v1 - v2;

  EXPECT_FLOAT_EQ(result.x, -2.0f);
  EXPECT_FLOAT_EQ(result.y, -2.0f);
}

TEST(Vector2Test, OperatorMultiply)
{
  Vector2f v1(1.0f, 2.0f);

  Vector2f result = v1 * 2;

  EXPECT_FLOAT_EQ(result.x, 2.0f);
  EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(Vector2Test, OperatorMultiplyFriend)
{
  Vector2f v1(1.0f, 2.0f);

  Vector2f result = 2.0f * v1;

  EXPECT_FLOAT_EQ(result.x, 2.0f);
  EXPECT_FLOAT_EQ(result.y, 4.0f);
}

TEST(Vector2Test, OperatorDivision)
{
  Vector2f v1(1.0f, 2.0f);

  Vector2f result = v1 / 2.0f;

  EXPECT_FLOAT_EQ(result.x, 0.5f);
  EXPECT_FLOAT_EQ(result.y, 1.0f);
}

TEST(Vector2Test, OperatorUnaryMinus)
{
  Vector2f v1(1.0f, 2.0f);

  Vector2f result = -v1;

  EXPECT_FLOAT_EQ(result.x, -1.0f);
  EXPECT_FLOAT_EQ(result.y, -2.0f);
}

/* ------------------------------ Assignment arithmetic operators ------------------------------ */
TEST(Vector2Test, OperatorPlusAssignment)
{
  Vector2f v1(1.0f, 2.0f);
  Vector2f v2(3.0f, 4.0f);

  v2 += v1;

  EXPECT_FLOAT_EQ(v2.x, 4.0f);
  EXPECT_FLOAT_EQ(v2.y, 6.0f);
}

TEST(Vector2Test, OperatorMinusAssignment)
{
  Vector2f v1(1.0f, 2.0f);
  Vector2f v2(3.0f, 4.0f);

  v1 -= v2;

  EXPECT_FLOAT_EQ(v1.x, -2.0f);
  EXPECT_FLOAT_EQ(v1.y, -2.0f);
}

TEST(Vector2Test, OperatorMultiplyAssignment)
{
  Vector2f v1(1.0f, 2.0f);

  v1 *= 2.0f;

  EXPECT_FLOAT_EQ(v1.x, 2.0f);
  EXPECT_FLOAT_EQ(v1.y, 4.0f);
}

TEST(Vector2Test, OperatorDivisionAssignment)
{
  Vector2f v1(1.0f, 2.0f);

  v1 /= 2.0f;

  EXPECT_FLOAT_EQ(v1.x, 0.5f);
  EXPECT_FLOAT_EQ(v1.y, 1.0f);
}

/* ------------------------------------- Compare operators ------------------------------------- */
TEST(Vector2Test, OperatorEqual)
{
  Vector2f v1(1.0f, 2.0f);
  Vector2f v2(1.0f, 2.0f);
  Vector2f v3(3.0f, 4.0f);

  EXPECT_TRUE(v1 == v2);
  EXPECT_FALSE(v1 == v3);
}

TEST(Vector2Test, OperatorNotEqual)
{
  Vector2f v1(1.0f, 2.0f);
  Vector2f v2(1.0f, 2.0f);
  Vector2f v3(3.0f, 4.0f);

  EXPECT_FALSE(v1 != v2);
  EXPECT_TRUE(v1 != v3);
}

/* -------------------------------------- General methods -------------------------------------- */

TEST(Vector2Test, MethodLength)
{
  Vector2f v1(3.0f, 4.0f);

  EXPECT_FLOAT_EQ(v1.Length(), 5.0f);
}

TEST(Vector2Test, MethodLengthSquared)
{
  Vector2f v1(3.0f, 4.0f);

  EXPECT_FLOAT_EQ(v1.LengthSquared(), 25.0f);
}

TEST(Vector2Test, MethodNormalized)
{
  Vector2f v1(3.0f, 4.0f);
  float length = v1.Length();

  Vector2f normalized = v1.Normalized();

  Vector2f expected = v1 / length;
  EXPECT_FLOAT_EQ(normalized.Length(), 1.0f);
  EXPECT_TRUE(normalized == expected);
}

TEST(Vector2Test, MethodNormalize)
{
  Vector2f v1(3.0f, 4.0f);
  Vector2f v2 = v1;
  float length = v1.Length();

  v1.Normalize();

  Vector2f expected = v2 / length;
  EXPECT_FLOAT_EQ(v1.Length(), 1.0f);
  EXPECT_TRUE(v1 == expected);
}

TEST(Vector2Test, MethodDot)
{
  Vector2f v1(1.0f, 2.0f);
  Vector2f v2(3.0f, 4.0f);

  EXPECT_FLOAT_EQ(v1.Dot(v2), 11.0f);
}

TEST(Vector2Test, MethodCross)
{
  Vector2f v1(1.0f, 2.0f);
  Vector2f v2(3.0f, 4.0f);

  EXPECT_FLOAT_EQ(v1.Cross(v2), -2.0f);
}

TEST(Vector2Test, MethodPerpendicular)
{
  Vector2f v1(1.0f, 2.0f);

  Vector2f perpendicularCounterclockwise = v1.Perpendicular();
  Vector2f perpendicularClockwise = v1.Perpendicular(true);

  Vector2f expectedCounterclockwise = Vector2f(2.0f, -1.0f);
  Vector2f expectedClockwise = Vector2f(-2.0f, 1.0f);
  EXPECT_TRUE(perpendicularCounterclockwise == expectedCounterclockwise);
  EXPECT_TRUE(perpendicularClockwise == expectedClockwise);
  EXPECT_FLOAT_EQ(v1.Dot(perpendicularCounterclockwise), 0.0f);
  EXPECT_FLOAT_EQ(v1.Dot(perpendicularClockwise), 0.0f);
}

TEST(Vector2Test, MethodAngleTo)
{
  Vector2f v1(1.0f, 1.0f);
  Vector2f v2(1.0f, -1.0f);
  Vector2f v3(-1.0f, 1.0f);
  Vector2f v4(1.0f, 0.0f);
  float pi = 3.14159265;

  float expected12 = -pi / 2.0f;
  float expected13 = pi / 2.0f;
  float expected23 = pi;
  float expected14 = -pi / 4.0f;
  EXPECT_FLOAT_EQ(v1.AngleTo(v2), expected12);
  EXPECT_FLOAT_EQ(v1.AngleTo(v3), expected13);
  EXPECT_FLOAT_EQ(v2.AngleTo(v3), expected23);
  EXPECT_FLOAT_EQ(v1.AngleTo(v4), expected14);
}

TEST(Vector2Test, MethodDistanceTo)
{
  Vector2f v1(0.0f, 3.0f);
  Vector2f v2(4.0f, 0.0f);

  EXPECT_FLOAT_EQ(v1.DistanceTo(v2), 5.0f);
}

TEST(Vector2Test, MethodProjected)
{
  Vector2f v1(2.0f, 6.0f);
  Vector2f v2(2.0f, 1.0f);

  Vector2f result = v1.Projected(v2);

  Vector2f expected(4.0f, 2.0f);
  EXPECT_TRUE(result == expected);
}

TEST(Vector2Test, MethodProject)
{
  Vector2f v1(2.0f, 6.0f);
  Vector2f v2(2.0f, 1.0f);

  v1.Project(v2);

  Vector2f expected(4.0f, 2.0f);
  EXPECT_TRUE(v1 == expected);
}

TEST(Vector2Test, MethodLerp)
{
  Vector2f v1(1.0f, 2.0f);
  Vector2f v2(3.0f, 4.0f);

  Vector2f result1 = v1.Lerp(v2, 0.0f);
  Vector2f result2 = v1.Lerp(v2, 1.0f);
  Vector2f result3 = v1.Lerp(v2, 0.5f);

  Vector2f expected1 = v1;
  Vector2f expected2 = v2;
  Vector2f expected3(2.0f, 3.0f);
  EXPECT_TRUE(result1 == expected1);
  EXPECT_TRUE(result2 == expected2);
  EXPECT_TRUE(result3 == expected3);
}

TEST(Vector2Test, MethodReflected)
{
  Vector2f v1(1.0f, 3.0f);
  Vector2f normal(-1.0f, 2.0f);

  Vector2f result = v1.Reflected(normal);

  Vector2f expected(3.0f, -1.0f);
  EXPECT_TRUE(result == expected);
}

TEST(Vector2Test, MethodReflect)
{
  Vector2f v1(1.0f, 3.0f);
  Vector2f normal(-1.0f, 2.0f);

  v1.Reflect(normal);

  Vector2f expected(3.0f, -1.0f);
  EXPECT_TRUE(v1 == expected);
}

/* ------------------------------------------- Debug ------------------------------------------- */

TEST(Vector2Test, MethodToString)
{
  Vector2f v1(-1.0f, 2.0f);

  std::string str = v1.ToString();
  std::string expected = "(-1.00, 2.00)";
  EXPECT_TRUE(str == expected);
}
