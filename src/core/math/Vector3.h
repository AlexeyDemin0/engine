/**
 * SPDX-License-Identifier: MIT
 *
 * @file Vector3.h
 * @brief Implementation of Vector3 class
 *
 * @author Alexey Demin (AlexeyDeminA@gmail.com)
 */

#pragma once

#include "core/Types.h"
#include "core/math/FloatComparator.h"

#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

namespace Engine::Core::Math
{

/* ------------------------------------- Class declaration ------------------------------------- */
template <typename T>
class Vector3
{
  static constexpr T epsilon = std::numeric_limits<T>::epsilon();

 public:
  T x;
  T y;
  T z;

  static constexpr Vector3<T> Zero() noexcept;
  static constexpr Vector3<T> One() noexcept;
  static constexpr Vector3<T> UnitX() noexcept;
  static constexpr Vector3<T> UnitY() noexcept;
  static constexpr Vector3<T> UnitZ() noexcept;

  constexpr Vector3() noexcept;
  constexpr explicit Vector3(T x) noexcept;
  constexpr Vector3(T x, T y) noexcept;
  constexpr Vector3(T x, T y, T z) noexcept;

  template <typename U>
  constexpr explicit Vector3(const Vector3<U>& other) noexcept;
  template <typename U>
  constexpr explicit Vector3(Vector3<U>&& other) noexcept;

  template <typename U>
  constexpr Vector3<T>& operator=(const Vector3<U>& other) noexcept;
  template <typename U>
  constexpr Vector3<T>& operator=(Vector3<U>&& other) noexcept;

  constexpr Vector3<T> operator+(const Vector3<T>& v) const noexcept;
  constexpr Vector3<T> operator-(const Vector3<T>& v) const noexcept;
  constexpr Vector3<T> operator*(T scalar) const noexcept;
  constexpr Vector3<T> operator/(T scalar) const noexcept;
  constexpr Vector3<T> operator-() const noexcept;

  constexpr Vector3<T>& operator+=(const Vector3<T>& v) noexcept;
  constexpr Vector3<T>& operator-=(const Vector3<T>& v) noexcept;
  constexpr Vector3<T>& operator*=(T scalar) noexcept;
  constexpr Vector3<T>& operator/=(T scalar) noexcept;

  constexpr bool operator==(const Vector3<T>& v) const noexcept;
  constexpr bool operator!=(const Vector3<T>& v) const noexcept;

  constexpr T Length() const noexcept;
  constexpr T LengthSquared() const noexcept;
  constexpr Vector3<T> Normalized() const noexcept;
  constexpr Vector3<T>& Normalize() noexcept;
  constexpr T Dot(const Vector3<T>& v) const noexcept;
  constexpr Vector3<T> Cross(const Vector3<T>& v) const noexcept;
  constexpr T AngleTo(const Vector3<T>& v) const noexcept;
  constexpr T DistanceTo(const Vector3<T>& v) const noexcept;
  constexpr Vector3<T> Projected(const Vector3<T>& v) const noexcept;
  constexpr Vector3<T>& Project(const Vector3<T>& v) noexcept;
  constexpr Vector3<T> Lerp(const Vector3<T>& v, T t) const noexcept;
  constexpr Vector3<T> Reflected(const Vector3<T>& normal) const noexcept;
  constexpr Vector3<T>& Reflect(const Vector3<T>& normal) noexcept;

  static constexpr T Dot(const Vector3<T>& v1, const Vector3<T>& v2) noexcept;
  static constexpr Vector3<T> Cross(const Vector3<T>& v1, const Vector3<T>& v2) noexcept;
  static constexpr T Angle(const Vector3<T>& v1, const Vector3<T>& v2) noexcept;
  static constexpr T Distance(const Vector3<T>& v1, const Vector3<T>& v2) noexcept;
  static constexpr Vector3<T> Project(const Vector3<T>& v1, const Vector3<T>& v2) noexcept;
  static constexpr Vector3<T> Lerp(const Vector3<T>& v1, const Vector3<T>& v2, T t) noexcept;
  static constexpr Vector3<T> Reflect(const Vector3<T>& v1, const Vector3<T>& normal) noexcept;

  std::string ToString(int precision = 2) const noexcept;
};

/* --------------------------------- Friend methods declaration -------------------------------- */
template <typename T>
constexpr Vector3<T> operator*(T scalar, const Vector3<T>& v) noexcept;

template <typename T>
constexpr std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) noexcept;

/* ------------------------------------------- Usings ------------------------------------------ */
using Vector3f = Vector3<f32>;
using Vector3d = Vector3<f64>;

/* --------------------------------------- Implementation -------------------------------------- */
template <typename T>
constexpr Vector3<T> Vector3<T>::Zero() noexcept
{
  return Vector3<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
}

template <typename T>
constexpr Vector3<T> Vector3<T>::One() noexcept
{
  return Vector3<T>(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));
}

template <typename T>
constexpr Vector3<T> Vector3<T>::UnitX() noexcept
{
  return Vector3<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
}

template <typename T>
constexpr Vector3<T> Vector3<T>::UnitY() noexcept
{
  return Vector3<T>(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
}

template <typename T>
constexpr Vector3<T> Vector3<T>::UnitZ() noexcept
{
  return Vector3<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
}

template <typename T>
constexpr Vector3<T>::Vector3() noexcept
    : x(static_cast<T>(0)),
      y(static_cast<T>(0)),
      z(static_cast<T>(0))
{
}

template <typename T>
constexpr Vector3<T>::Vector3(T x) noexcept
    : x(x),
      y(static_cast<T>(0)),
      z(static_cast<T>(0))
{
}

template <typename T>
constexpr Vector3<T>::Vector3(T x, T y) noexcept
    : x(x),
      y(y),
      z(static_cast<T>(0))
{
}

template <typename T>
constexpr Vector3<T>::Vector3(T x, T y, T z) noexcept
    : x(x),
      y(y),
      z(z)
{
}

template <typename T>
template <typename U>
constexpr Vector3<T>::Vector3(const Vector3<U>& other) noexcept
    : x(static_cast<T>(other.x)),
      y(static_cast<T>(other.y)),
      z(static_cast<T>(other.z))
{
}

template <typename T>
template <typename U>
constexpr Vector3<T>::Vector3(Vector3<U>&& other) noexcept
    : x(static_cast<T>(other.x)),
      y(static_cast<T>(other.y)),
      z(static_cast<T>(other.z))
{
}

template <typename T>
template <typename U>
constexpr Vector3<T>& Vector3<T>::operator=(const Vector3<U>& other) noexcept
{
  if (this != &other) {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);
  }
  return *this;
}

template <typename T>
template <typename U>
constexpr Vector3<T>& Vector3<T>::operator=(Vector3<U>&& other) noexcept
{
  if (this != &other) {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);
  }
  return *this;
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator+(const Vector3<T>& v) const noexcept
{
  return Vector3<T>(x + v.x, y + v.y, z + v.z);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator-(const Vector3<T>& v) const noexcept
{
  return Vector3<T>(x - v.x, y - v.y, z - v.z);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator*(T scalar) const noexcept
{
  return Vector3<T>(x * scalar, y * scalar, z * scalar);
}

template <typename T>
constexpr Vector3<T> operator*(T scalar, const Vector3<T>& v) noexcept
{
  return Vector3<T>(v.x * scalar, v.y * scalar, v.z * scalar);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator/(T scalar) const noexcept
{
  assert(std::abs(scalar) > epsilon && "Division by zero");
  if (std::abs(scalar) > epsilon)
    return Vector3<T>(x / scalar, y / scalar, z / scalar);

  return Vector3<T>();
}

template <typename T>
constexpr Vector3<T> Vector3<T>::operator-() const noexcept
{
  return Vector3<T>(-x, -y, -z);
}

template <typename T>
constexpr Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& v) noexcept
{
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

template <typename T>
constexpr Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& v) noexcept
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

template <typename T>
constexpr Vector3<T>& Vector3<T>::operator*=(T scalar) noexcept
{
  x *= scalar;
  y *= scalar;
  z *= scalar;
  return *this;
}

template <typename T>
constexpr Vector3<T>& Vector3<T>::operator/=(T scalar) noexcept
{
  assert(std::abs(scalar) > epsilon && "Division by zero");
  if (std::abs(scalar) > epsilon) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
  } else
    x = y = z = static_cast<T>(0);
  return *this;
}

template <typename T>
constexpr bool Vector3<T>::operator==(const Vector3<T>& v) const noexcept
{
  constexpr FloatComparator<T> comparator(5 * std::numeric_limits<T>::epsilon());
  return comparator.Compare(x, v.x) && comparator.Compare(y, v.y) && comparator.Compare(z, v.z);
}

template <typename T>
constexpr bool Vector3<T>::operator!=(const Vector3<T>& v) const noexcept
{
  constexpr FloatComparator<T> comparator(5 * std::numeric_limits<T>::epsilon());
  return !comparator.Compare(x, v.x) || !comparator.Compare(y, v.y) || !comparator.Compare(z, v.z);
}

template <typename T>
constexpr T Vector3<T>::Length() const noexcept
{
  return std::sqrt(x * x + y * y + z * z);
}

template <typename T>
constexpr T Vector3<T>::LengthSquared() const noexcept
{
  return x * x + y * y + z * z;
}

template <typename T>
constexpr Vector3<T> Vector3<T>::Normalized() const noexcept
{
  T length = Length();
  return length > epsilon ? *this / length : Vector3<T>();
}

template <typename T>
constexpr Vector3<T>& Vector3<T>::Normalize() noexcept
{
  T length = Length();
  if (length > epsilon)
    *this /= length;
  else
    *this = Vector3<T>();
  return *this;
}

template <typename T>
constexpr T Vector3<T>::Dot(const Vector3<T>& v) const noexcept
{
  return x * v.x + y * v.y + z * v.z;
}

template <typename T>
constexpr Vector3<T> Vector3<T>::Cross(const Vector3<T>& v) const noexcept
{
  return Vector3<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

template <typename T>
constexpr T Vector3<T>::AngleTo(const Vector3<T>& v) const noexcept
{
  T dot = Dot(v);
  T det = Cross(v).Length();
  return std::atan2(det, dot);
}

template <typename T>
constexpr T Vector3<T>::DistanceTo(const Vector3<T>& v) const noexcept
{
  return (*this - v).Length();
}

template <typename T>
constexpr Vector3<T> Vector3<T>::Projected(const Vector3<T>& v) const noexcept
{
  T lengthSquared = v.LengthSquared();
  if (lengthSquared < epsilon)
    return Vector3<T>();
  return v * Dot(v) / lengthSquared;
}

template <typename T>
constexpr Vector3<T>& Vector3<T>::Project(const Vector3<T>& v) noexcept
{
  T lengthSquared = v.LengthSquared();
  if (lengthSquared < epsilon)
    *this = Vector3<T>();
  else
    *this = v * Dot(v) / lengthSquared;
  return *this;
}

template <typename T>
constexpr Vector3<T> Vector3<T>::Lerp(const Vector3<T>& v, T t) const noexcept
{
  return (static_cast<T>(1) - t) * *this + t * v;
}

template <typename T>
constexpr Vector3<T> Vector3<T>::Reflected(const Vector3<T>& normal) const noexcept
{
  Vector3<T> n = normal.Normalized();
  return *this - static_cast<T>(2) * Dot(n) * n;
}

template <typename T>
constexpr Vector3<T>& Vector3<T>::Reflect(const Vector3<T>& normal) noexcept
{
  Vector3<T> n = normal.Normalized();
  *this -= static_cast<T>(2) * Dot(n) * n;
  return *this;
}

template <typename T>
constexpr T Vector3<T>::Dot(const Vector3<T>& v1, const Vector3<T>& v2) noexcept
{
  return v1.Dot(v2);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::Cross(const Vector3<T>& v1, const Vector3<T>& v2) noexcept
{
  return v1.Cross(v2);
}

template <typename T>
constexpr T Vector3<T>::Angle(const Vector3<T>& v1, const Vector3<T>& v2) noexcept
{
  return v1.AngleTo(v2);
}

template <typename T>
constexpr T Vector3<T>::Distance(const Vector3<T>& v1, const Vector3<T>& v2) noexcept
{
  return v1.DistanceTo(v2);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::Project(const Vector3<T>& v1, const Vector3<T>& v2) noexcept
{
  return v1.Projected(v2);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::Lerp(const Vector3<T>& v1, const Vector3<T>& v2, T t) noexcept
{
  return v1.Lerp(v2, t);
}

template <typename T>
constexpr Vector3<T> Vector3<T>::Reflect(const Vector3<T>& v1, const Vector3<T>& normal) noexcept
{
  return v1.Reflected(normal);
}

template <typename T>
std::string Vector3<T>::ToString(int precision) const noexcept
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(precision);
  oss << "(" << x << ", " << y << ", " << z << ")";
  return oss.str();
}

template <typename T>
constexpr std::ostream& operator<<(std::ostream& os, const Vector3<T>& v) noexcept
{
  return os << v.ToString();
}

} // namespace Engine::Core::Math
