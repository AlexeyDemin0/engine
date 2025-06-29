/**
 * SPDX-License-Identifier: MIT
 *
 * @file test_Vector3.cpp
 * @brief Tests for Vector3 class
 *
 * @author Alexey Demin (AlexeyDeminA@gmail.com)
 */

#include <gtest/gtest.h>

#include <core/math/Vector3.h>
#include <string>

using namespace Engine::Core::Math;

/* ------------------------------------------- Other ------------------------------------------- */

TEST(Vector3Test, Sizeof)
{
  EXPECT_TRUE(sizeof(Vector3f) == 3 * sizeof(float));
  EXPECT_TRUE(sizeof(Vector3d) == 3 * sizeof(double));
}

/* ---------------------------------------- Constructors --------------------------------------- */

TEST(Vector3Test, ConstructorDefault)
{
  Vector3f v;

  EXPECT_FLOAT_EQ(v.x, 0.0f);
  EXPECT_FLOAT_EQ(v.y, 0.0f);
  EXPECT_FLOAT_EQ(v.z, 0.0f);
}

TEST(Vector3Test, ConstructorOneParam)
{
  Vector3f v(1.0f);

  EXPECT_FLOAT_EQ(v.x, 1.0f);
  EXPECT_FLOAT_EQ(v.y, 0.0f);
  EXPECT_FLOAT_EQ(v.z, 0.0f);
}

TEST(Vector3Test, ConstructorTwoParam)
{
  Vector3f v(1.0f, 2.0f);

  EXPECT_FLOAT_EQ(v.x, 1.0f);
  EXPECT_FLOAT_EQ(v.y, 2.0f);
  EXPECT_FLOAT_EQ(v.z, 0.0f);
}

TEST(Vector3Test, ConstructorThreeParam)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  EXPECT_FLOAT_EQ(v.x, 1.0f);
  EXPECT_FLOAT_EQ(v.y, 2.0f);
  EXPECT_FLOAT_EQ(v.z, 3.0f);
}

/* --------------------------------- Copy and move constructors -------------------------------- */

TEST(Vector3Test, ConstructorCopy)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  Vector3f copy(v);

  EXPECT_FLOAT_EQ(copy.x, 1.0f);
  EXPECT_FLOAT_EQ(copy.y, 2.0f);
  EXPECT_FLOAT_EQ(copy.z, 3.0f);
}

TEST(Vector3Test, ConstructorMove)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  Vector3f copy(std::move(v));

  EXPECT_FLOAT_EQ(copy.x, 1.0f);
  EXPECT_FLOAT_EQ(copy.y, 2.0f);
  EXPECT_FLOAT_EQ(copy.z, 3.0f);
}

/* ---------------------------------- Copy and move operators ---------------------------------- */

TEST(Vector3Test, OperatorCopyAssignment)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  Vector3f copy = v;

  EXPECT_FLOAT_EQ(copy.x, 1.0f);
  EXPECT_FLOAT_EQ(copy.y, 2.0f);
  EXPECT_FLOAT_EQ(copy.z, 3.0f);
}

TEST(Vector3Test, OperatorMoveAssignment)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  Vector3f copy = std::move(v);

  EXPECT_FLOAT_EQ(copy.x, 1.0f);
  EXPECT_FLOAT_EQ(copy.y, 2.0f);
  EXPECT_FLOAT_EQ(copy.z, 3.0f);
}

/* ------------------------------------ Arithmetic operators ----------------------------------- */

TEST(Vector3Test, OperatorPlus)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(4.0f, 5.0f, 6.0f);

  Vector3f result = v1 + v2;

  EXPECT_FLOAT_EQ(result.x, 5.0f);
  EXPECT_FLOAT_EQ(result.y, 7.0f);
  EXPECT_FLOAT_EQ(result.z, 9.0f);
}

TEST(Vector3Test, OperatorMinus)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(4.0f, 5.0f, 6.0f);

  Vector3f result = v1 - v2;

  EXPECT_FLOAT_EQ(result.x, -3.0f);
  EXPECT_FLOAT_EQ(result.y, -3.0f);
  EXPECT_FLOAT_EQ(result.z, -3.0f);
}

TEST(Vector3Test, OperatorMultiply)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  Vector3f result = v * 2.0f;

  EXPECT_FLOAT_EQ(result.x, 2.0f);
  EXPECT_FLOAT_EQ(result.y, 4.0f);
  EXPECT_FLOAT_EQ(result.z, 6.0f);
}

TEST(Vector3Test, OperatorFriendMultiply)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  Vector3f result = 2.0f * v;

  EXPECT_FLOAT_EQ(result.x, 2.0f);
  EXPECT_FLOAT_EQ(result.y, 4.0f);
  EXPECT_FLOAT_EQ(result.z, 6.0f);
}

TEST(Vector3Test, OperatorDivision)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  Vector3f result = v / 2.0f;

  EXPECT_FLOAT_EQ(result.x, 0.5f);
  EXPECT_FLOAT_EQ(result.y, 1.0f);
  EXPECT_FLOAT_EQ(result.z, 1.5f);
}

TEST(Vector3Test, OperatorUnaryMinus)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  Vector3f result = -v;

  EXPECT_FLOAT_EQ(result.x, -1.0f);
  EXPECT_FLOAT_EQ(result.y, -2.0f);
  EXPECT_FLOAT_EQ(result.z, -3.0f);
}

/* ------------------------------ Assignment arithmetic operators ------------------------------ */

TEST(Vector3Test, OperatorPlusAssignment)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(4.0f, 5.0f, 6.0f);

  v1 += v2;

  EXPECT_FLOAT_EQ(v1.x, 5.0f);
  EXPECT_FLOAT_EQ(v1.y, 7.0f);
  EXPECT_FLOAT_EQ(v1.z, 9.0f);
}

TEST(Vector3Test, OperatorMinusAssignment)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(4.0f, 5.0f, 6.0f);

  v1 -= v2;

  EXPECT_FLOAT_EQ(v1.x, -3.0f);
  EXPECT_FLOAT_EQ(v1.y, -3.0f);
  EXPECT_FLOAT_EQ(v1.z, -3.0f);
}

TEST(Vector3Test, OperatorMultiplyAssignment)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  v *= 2.0f;

  EXPECT_FLOAT_EQ(v.x, 2.0f);
  EXPECT_FLOAT_EQ(v.y, 4.0f);
  EXPECT_FLOAT_EQ(v.z, 6.0f);
}

TEST(Vector3Test, OperatorDivisionAssignment)
{
  Vector3f v(1.0f, 2.0f, 3.0f);

  v /= 2.0f;

  EXPECT_FLOAT_EQ(v.x, 0.5f);
  EXPECT_FLOAT_EQ(v.y, 1.0f);
  EXPECT_FLOAT_EQ(v.z, 1.5f);
}

/* ------------------------------------- Compare operators ------------------------------------- */

TEST(Vector3Test, OperatorEqual)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(1.0f, 2.0f, 3.0f);
  Vector3f v3(4.0f, 5.0f, 6.0f);

  EXPECT_TRUE(v1 == v2);
  EXPECT_FALSE(v1 == v3);
}

TEST(Vector3Test, OperatorNotEqual)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(1.0f, 2.0f, 3.0f);
  Vector3f v3(4.0f, 5.0f, 6.0f);

  EXPECT_FALSE(v1 != v2);
  EXPECT_TRUE(v1 != v3);
}

/* -------------------------------------- General methods -------------------------------------- */

TEST(Vector3Test, MethodLength)
{
  Vector3f v(3.0f, 4.0f, 12.0f);

  EXPECT_FLOAT_EQ(v.Length(), 13.0f);
}

TEST(Vector3Test, MethodLengthSquared)
{
  Vector3f v(3.0f, 4.0f, 12.0f);

  EXPECT_FLOAT_EQ(v.LengthSquared(), 169.0f);
}

TEST(Vector3Test, MethodNormalized)
{
  Vector3f v(3.0f, 4.0f, 5.0f);
  Vector3f normalized = v.Normalized();

  float length = std::sqrt(3.0f * 3.0f + 4.0f * 4.0f + 5.0f * 5.0f);
  EXPECT_FLOAT_EQ(normalized.x, 3.0f / length);
  EXPECT_FLOAT_EQ(normalized.y, 4.0f / length);
  EXPECT_FLOAT_EQ(normalized.z, 5.0f / length);
}

TEST(Vector3Test, MethodNormalize)
{
  Vector3f v(3.0f, 4.0f, 5.0f);
  v.Normalize();

  float length = std::sqrt(3.0f * 3.0f + 4.0f * 4.0f + 5.0f * 5.0f);
  EXPECT_FLOAT_EQ(v.x, 3.0f / length);
  EXPECT_FLOAT_EQ(v.y, 4.0f / length);
  EXPECT_FLOAT_EQ(v.z, 5.0f / length);
}

TEST(Vector3Test, MethodDot)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(4.0f, 5.0f, 6.0f);

  EXPECT_FLOAT_EQ(v1.Dot(v2), 32.0f);
}

TEST(Vector3Test, MethodCross)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(4.0f, 5.0f, 6.0f);

  Vector3f result = v1.Cross(v2);

  EXPECT_FLOAT_EQ(result.x, -3.0f);
  EXPECT_FLOAT_EQ(result.y, 6.0f);
  EXPECT_FLOAT_EQ(result.z, -3.0f);
}

TEST(Vector3Test, MethodAngleTo)
{
  Vector3f v1(1.0f, 0.0f, 0.0f);
  Vector3f v2(0.0f, 1.0f, 0.0f);
  Vector3f v3(2.0f, 0.0f, 0.0f);
  Vector3f v4(-1.0f, 0.0f, 0.0f);
  Vector3f v5(1.0f, 1.0f, 0.0f);
  Vector3f vzero(0.0f, 0.0f, 0.0f);
  float pi = 3.14159265;

  EXPECT_FLOAT_EQ(v1.AngleTo(v2), pi / 2.0f);
  EXPECT_FLOAT_EQ(v1.AngleTo(v3), 0.0f);
  EXPECT_FLOAT_EQ(v1.AngleTo(v4), pi);
  EXPECT_FLOAT_EQ(v1.AngleTo(v5), pi / 4.0f);
  EXPECT_FLOAT_EQ(v1.AngleTo(vzero), 0.0f);
}

TEST(Vector3Test, MethodDistanceTo)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(4.0f, 6.0f, 3.0f);

  EXPECT_FLOAT_EQ(v1.DistanceTo(v2), 5.0f);
}

TEST(Vector3Test, MethodProjected)
{
  Vector3f v1(3.0f, 2.0f, 1.0f);
  Vector3f v2(1.0f, 0.0f, 0.0f);

  Vector3f result = v1.Projected(v2);

  Vector3f expected(3.0f, 0.0f, 0.0f);
  EXPECT_TRUE(result == expected);
}

TEST(Vector3Test, MethodProject)
{
  Vector3f v1(3.0f, 2.0f, 1.0f);
  Vector3f v2(1.0f, 0.0f, 0.0f);

  v1.Project(v2);

  Vector3f expected(3.0f, 0.0f, 0.0f);
  EXPECT_TRUE(v1 == expected);
}

TEST(Vector3Test, MethodLerp)
{
  Vector3f v1(1.0f, 2.0f, 3.0f);
  Vector3f v2(4.0f, 5.0f, 6.0f);
  float t = 0.5f;

  Vector3f result = v1.Lerp(v2, t);

  EXPECT_FLOAT_EQ(result.x, 2.5f);
  EXPECT_FLOAT_EQ(result.y, 3.5f);
  EXPECT_FLOAT_EQ(result.z, 4.5f);
}

TEST(Vector3Test, MethodReflected)
{
  Vector3f v(1.0f, -1.0f, -1.0f);
  Vector3f normal(0.0f, 1.0f, 0.0f);

  Vector3f result = v.Reflected(normal);

  EXPECT_FLOAT_EQ(result.x, 1.0f);
  EXPECT_FLOAT_EQ(result.y, 1.0f);
  EXPECT_FLOAT_EQ(result.z, -1.0f);
}

TEST(Vector3Test, MethodReflect)
{
  Vector3f v(1.0f, -1.0f, -1.0f);
  Vector3f normal(0.0f, 1.0f, 0.0f);

  v.Reflect(normal);

  EXPECT_FLOAT_EQ(v.x, 1.0f);
  EXPECT_FLOAT_EQ(v.y, 1.0f);
  EXPECT_FLOAT_EQ(v.z, -1.0f);
}

/* ------------------------------------------- Debug ------------------------------------------- */

TEST(Vector3Test, MethodToString)
{
  Vector3f v1(-1.0f, 2.0f, -3.0f);

  std::string str = v1.ToString();
  std::string expected = "(-1.00, 2.00, -3.00)";
  EXPECT_TRUE(str == expected);
}
