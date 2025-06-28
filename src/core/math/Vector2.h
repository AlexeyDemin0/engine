/**
 * SPDX-License-Identifier: MIT
 *
 * @file Vector2.h
 * @brief Contains implementation of Vector2 class
 *
 * @todo Add doxygen documentation
 *
 * @author Alexey Demin (AlexeyDeminA@gmail.com)
 */

#pragma once

#include "core/Types.h"
#include "core/math/FloatComparator.h"

#include <cassert>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

namespace Engine::Core::Math
{

/* ------------------------------------- Class declaration ------------------------------------- */
template <typename T>
class Vector2
{
  static constexpr T epsilon = std::numeric_limits<T>::epsilon();

 public:
  T x;
  T y;

  constexpr Vector2() noexcept;
  constexpr explicit Vector2(T x) noexcept;
  constexpr Vector2(T x, T y) noexcept;

  template <typename U>
  constexpr explicit Vector2(const Vector2<U>& other) noexcept;
  template <typename U>
  constexpr explicit Vector2(Vector2<U>&& other) noexcept;

  template <typename U>
  constexpr Vector2<T>& operator=(const Vector2<U>& other) noexcept;
  template <typename U>
  constexpr Vector2<T>& operator=(Vector2<U>&& other) noexcept;

  constexpr Vector2<T> operator+(const Vector2<T>& v) const noexcept;
  constexpr Vector2<T> operator-(const Vector2<T>& v) const noexcept;
  constexpr Vector2<T> operator*(T scalar) const noexcept;
  constexpr Vector2<T> operator/(T scalar) const noexcept;
  constexpr Vector2<T> operator-() const noexcept;

  constexpr Vector2<T>& operator+=(const Vector2<T>& v) noexcept;
  constexpr Vector2<T>& operator-=(const Vector2<T>& v) noexcept;
  constexpr Vector2<T>& operator*=(T scalar) noexcept;
  constexpr Vector2<T>& operator/=(T scalar) noexcept;

  constexpr bool operator==(const Vector2<T>& v) const noexcept;
  constexpr bool operator!=(const Vector2<T>& v) const noexcept;

  constexpr T Length() const noexcept;
  constexpr T LengthSquared() const noexcept;
  constexpr Vector2<T> Normalized() const noexcept;
  constexpr Vector2<T>& Normalize() noexcept;
  constexpr T Dot(const Vector2<T>& v) const noexcept;
  constexpr T Cross(const Vector2<T>& v) const noexcept;
  constexpr Vector2<T> Perpendicular(bool clockwise = false) const noexcept;
  constexpr T AngleTo(const Vector2<T>& v) const noexcept;
  constexpr T DistanceTo(const Vector2<T>& v) const noexcept;
  constexpr Vector2<T> Projected(const Vector2<T>& v) const noexcept;
  constexpr Vector2<T>& Project(const Vector2<T>& v) noexcept;
  constexpr Vector2<T> Lerp(const Vector2<T>& v, T t) const noexcept;
  constexpr Vector2<T> Reflected(const Vector2<T>& normal) const noexcept;
  constexpr Vector2<T>& Reflect(const Vector2<T>& normal) noexcept;

  static constexpr T Dot(const Vector2<T>& v1, const Vector2<T>& v2) noexcept;
  static constexpr T Cross(const Vector2<T>& v1, const Vector2<T>& v2) noexcept;
  static constexpr T Angle(const Vector2<T>& v1, const Vector2<T>& v2) noexcept;
  static constexpr T Distance(const Vector2<T>& v1, const Vector2<T>& v2) noexcept;
  static constexpr Vector2<T> Project(const Vector2<T>& v1, const Vector2<T>& v2) noexcept;
  static constexpr Vector2<T> Lerp(const Vector2<T>& v1, const Vector2<T>& v2, T t) noexcept;
  static constexpr Vector2<T> Reflect(const Vector2<T>& v1, const Vector2<T>& normal) noexcept;

  std::string ToString(int precision = 2) const noexcept;
};

/* --------------------------------- Friend methods declaration -------------------------------- */
template <typename T>
constexpr Vector2<T> operator*(T scalar, const Vector2<T>& v) noexcept;

template <typename T>
constexpr std::ostream& operator<<(std::ostream& os, const Vector2<T>& v) noexcept;

/* ------------------------------------------- Usings ------------------------------------------ */
using Vector2f = Vector2<f32>;
using Vector2d = Vector2<f64>;

/* -------------------------------------- Implementations -------------------------------------- */
template <typename T>
constexpr Vector2<T>::Vector2() noexcept
    : x(static_cast<T>(0)),
      y(static_cast<T>(0))
{
}

template <typename T>
constexpr Vector2<T>::Vector2(T x) noexcept
    : x(x),
      y(static_cast<T>(0))
{
}

template <typename T>
constexpr Vector2<T>::Vector2(T x, T y) noexcept
    : x(x),
      y(y)
{
}

template <typename T>
template <typename U>
constexpr Vector2<T>::Vector2(const Vector2<U>& other) noexcept
    : x(static_cast<U>(other.x)),
      y(static_cast<U>(other.y))
{
}

template <typename T>
template <typename U>
constexpr Vector2<T>::Vector2(Vector2<U>&& other) noexcept
    : x(static_cast<U>(other.x)),
      y(static_cast<U>(other.y))
{
}

template <typename T>
template <typename U>
constexpr Vector2<T>& Vector2<T>::operator=(const Vector2<U>& other) noexcept
{
  if (this != &other) {
    x = static_cast<U>(other.x);
    y = static_cast<U>(other.y);
  }
  return *this;
}

template <typename T>
template <typename U>
constexpr Vector2<T>& Vector2<T>::operator=(Vector2<U>&& other) noexcept
{
  if (this != &other) {
    x = static_cast<U>(other.x);
    y = static_cast<U>(other.y);
  }
  return *this;
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator+(const Vector2<T>& v) const noexcept
{
  return Vector2<T>(x + v.x, y + v.y);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator-(const Vector2<T>& v) const noexcept
{
  return Vector2<T>(x - v.x, y - v.y);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator*(T scalar) const noexcept
{
  return Vector2<T>(x * scalar, y * scalar);
}

template <typename T>
constexpr Vector2<T> operator*(T scalar, const Vector2<T>& v) noexcept
{
  return Vector2<T>(v.x * scalar, v.y * scalar);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator/(T scalar) const noexcept
{
  assert(std::abs(scalar) > epsilon && "Division by zero");
  if (std::abs(scalar) > epsilon)
    return Vector2<T>(x / scalar, y / scalar);

  return Vector2<T>();
}

template <typename T>
constexpr Vector2<T> Vector2<T>::operator-() const noexcept
{
  return Vector2<T>(-x, -y);
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& v) noexcept
{
  x += v.x;
  y += v.y;
  return *this;
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& v) noexcept
{
  x -= v.x;
  y -= v.y;
  return *this;
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::operator*=(T scalar) noexcept
{
  x *= scalar;
  y *= scalar;
  return *this;
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::operator/=(T scalar) noexcept
{
  assert(std::abs(scalar) > epsilon && "Division by zero");
  if (std::abs(scalar) > epsilon) {
    x /= scalar;
    y /= scalar;
  } else
    x = y = static_cast<T>(0);
  return *this;
}

template <typename T>
constexpr bool Vector2<T>::operator==(const Vector2<T>& v) const noexcept
{
  constexpr FloatComparator<T> comparator(5 * std::numeric_limits<T>::epsilon());
  return comparator.Compare(x, v.x) && comparator.Compare(y, v.y);
}

template <typename T>
constexpr bool Vector2<T>::operator!=(const Vector2<T>& v) const noexcept
{
  constexpr FloatComparator<T> comparator(5 * std::numeric_limits<T>::epsilon());
  return !comparator.Compare(x, v.x) || !comparator.Compare(y, v.y);
}

template <typename T>
constexpr T Vector2<T>::Length() const noexcept
{
  return std::sqrt(x * x + y * y);
}

template <typename T>
constexpr T Vector2<T>::LengthSquared() const noexcept
{
  return x * x + y * y;
}

template <typename T>
constexpr Vector2<T> Vector2<T>::Normalized() const noexcept
{
  T length = Length();
  return length > epsilon ? *this / length : Vector2<T>();
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::Normalize() noexcept
{
  T length = Length();
  if (length > epsilon)
    *this /= length;
  else
    *this = Vector2<T>();
  return *this;
}

template <typename T>
constexpr T Vector2<T>::Dot(const Vector2<T>& v) const noexcept
{
  return x * v.x + y * v.y;
}

template <typename T>
constexpr T Vector2<T>::Cross(const Vector2<T>& v) const noexcept
{
  return x * v.y - y * v.x;
}

template <typename T>
constexpr Vector2<T> Vector2<T>::Perpendicular(bool clockwise) const noexcept
{
  return clockwise ? Vector2<T>(-y, x) : Vector2<T>(y, -x);
}

template <typename T>
constexpr T Vector2<T>::AngleTo(const Vector2<T>& v) const noexcept
{
  T dot = Dot(v);
  T det = Cross(v);
  return std::atan2(det, dot);
}

template <typename T>
constexpr T Vector2<T>::DistanceTo(const Vector2<T>& v) const noexcept
{
  return (*this - v).Length();
}

template <typename T>
constexpr Vector2<T> Vector2<T>::Projected(const Vector2<T>& v) const noexcept
{
  T lengthSquared = v.LengthSquared();
  if (lengthSquared < epsilon)
    return Vector2<T>();
  return v * (Dot(v) / lengthSquared);
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::Project(const Vector2<T>& v) noexcept
{
  T lengthSquared = v.LengthSquared();
  if (lengthSquared < epsilon)
    *this = Vector2<T>();
  else
    *this = v * Dot(v) / lengthSquared;
  return *this;
}

template <typename T>
constexpr Vector2<T> Vector2<T>::Lerp(const Vector2<T>& v, T t) const noexcept
{
  return (static_cast<T>(1) - t) * *this + t * v;
}

template <typename T>
constexpr Vector2<T> Vector2<T>::Reflected(const Vector2<T>& normal) const noexcept
{
  Vector2<T> n = normal.Normalized();
  return *this - static_cast<T>(2) * Dot(n) * n;
}

template <typename T>
constexpr Vector2<T>& Vector2<T>::Reflect(const Vector2<T>& normal) noexcept
{
  Vector2<T> n = normal.Normalized();
  *this -= static_cast<T>(2) * Dot(n) * n;
  return *this;
}

template <typename T>
constexpr T Vector2<T>::Dot(const Vector2<T>& v1, const Vector2<T>& v2) noexcept
{
  return v1.Dot(v2);
}

template <typename T>
constexpr T Vector2<T>::Cross(const Vector2<T>& v1, const Vector2<T>& v2) noexcept
{
  return v1.Cross(v2);
}

template <typename T>
constexpr T Vector2<T>::Angle(const Vector2<T>& v1, const Vector2<T>& v2) noexcept
{
  return v1.AngleTo(v2);
}

template <typename T>
constexpr T Vector2<T>::Distance(const Vector2<T>& v1, const Vector2<T>& v2) noexcept
{
  return v1.DistanceTo(v2);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::Project(const Vector2<T>& v1, const Vector2<T>& v2) noexcept
{
  return v1.Projected(v2);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::Lerp(const Vector2<T>& v1, const Vector2<T>& v2, T t) noexcept
{
  return v1.Lerp(v2, t);
}

template <typename T>
constexpr Vector2<T> Vector2<T>::Reflect(const Vector2<T>& v1, const Vector2<T>& v2) noexcept
{
  return v1.Reflected(v2);
}

template <typename T>
std::string Vector2<T>::ToString(int precision) const noexcept
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(precision);
  oss << "(" << x << ", " << y << ")";
  return oss.str();
}

template <typename T>
constexpr std::ostream& operator<<(std::ostream& os, const Vector2<T>& v) noexcept
{
  return os << v.ToString();
}

} // namespace Engine::Core::Math
