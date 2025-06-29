/**
 * SPDX-License-Identifier: MIT
 *
 * @file Vector4.h
 * @brief Implementation of Vector4 class
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
class Vector4
{
  static constexpr T epsilon = std::numeric_limits<T>::epsilon();

 public:
  T x;
  T y;
  T z;
  T w;

  static constexpr Vector4<T> Zero() noexcept;
  static constexpr Vector4<T> One() noexcept;
  static constexpr Vector4<T> UnitX() noexcept;
  static constexpr Vector4<T> UnitY() noexcept;
  static constexpr Vector4<T> UnitZ() noexcept;
  static constexpr Vector4<T> UnitW() noexcept;

  constexpr Vector4() noexcept;
  constexpr explicit Vector4(T x) noexcept;
  constexpr Vector4(T x, T y) noexcept;
  constexpr Vector4(T x, T y, T z) noexcept;
  constexpr Vector4(T x, T y, T z, T w) noexcept;

  template <typename U>
  constexpr explicit Vector4(const Vector4<U>& other) noexcept;
  template <typename U>
  constexpr explicit Vector4(Vector4<U>&& other) noexcept;

  template <typename U>
  constexpr Vector4<T>& operator=(const Vector4<U>& other) noexcept;
  template <typename U>
  constexpr Vector4<T>& operator=(Vector4<U>&& other) noexcept;

  constexpr Vector4<T> operator+(const Vector4<T>& v) const noexcept;
  constexpr Vector4<T> operator-(const Vector4<T>& v) const noexcept;
  constexpr Vector4<T> operator*(T scalar) const noexcept;
  constexpr Vector4<T> operator/(T scalar) const noexcept;
  constexpr Vector4<T> operator-() const noexcept;

  constexpr Vector4<T>& operator+=(const Vector4<T>& v) noexcept;
  constexpr Vector4<T>& operator-=(const Vector4<T>& v) noexcept;
  constexpr Vector4<T>& operator*=(T scalar) noexcept;
  constexpr Vector4<T>& operator/=(T scalar) noexcept;

  constexpr bool operator==(const Vector4<T>& v) const noexcept;
  constexpr bool operator!=(const Vector4<T>& v) const noexcept;

  constexpr T Length() const noexcept;
  constexpr T LengthSquared() const noexcept;
  constexpr Vector4<T> Normalized() const noexcept;
  constexpr Vector4<T>& Normalize() noexcept;
  constexpr T Dot(const Vector4<T>& v) const noexcept;
  constexpr Vector4<T> Cross(const Vector4<T>& v) const noexcept;
  constexpr T AngleTo(const Vector4<T>& v) const noexcept;
  constexpr T DistanceTo(const Vector4<T>& v) const noexcept;
  constexpr Vector4<T> Projected(const Vector4<T>& v) const noexcept;
  constexpr Vector4<T>& Project(const Vector4<T>& v) noexcept;
  constexpr Vector4<T> Lerp(const Vector4<T>& v, T t) const noexcept;
  constexpr Vector4<T> Reflected(const Vector4<T>& normal) const noexcept;
  constexpr Vector4<T>& Reflect(const Vector4<T>& normal) noexcept;

  static constexpr T Dot(const Vector4<T>& v1, const Vector4<T>& v2) noexcept;
  static constexpr Vector4<T> Cross(const Vector4<T>& v1, const Vector4<T>& v2) noexcept;
  static constexpr T Angle(const Vector4<T>& v1, const Vector4<T>& v2) noexcept;
  static constexpr T Distance(const Vector4<T>& v1, const Vector4<T>& v2) noexcept;
  static constexpr Vector4<T> Project(const Vector4<T>& v1, const Vector4<T>& v2) noexcept;
  static constexpr Vector4<T> Lerp(const Vector4<T>& v1, const Vector4<T>& v2, T t) noexcept;
  static constexpr Vector4<T> Reflect(const Vector4<T>& v1, const Vector4<T>& normal) noexcept;

  std::string ToString(int precision = 2) const noexcept;
};

/* --------------------------------- Friend methods declaration -------------------------------- */
template <typename T>
constexpr Vector4<T> operator*(T scalar, const Vector4<T>& v) noexcept;

template <typename T>
constexpr std::ostream& operator<<(std::ostream& os, const Vector4<T>& v) noexcept;

/* ------------------------------------------- Usings ------------------------------------------ */
using Vector4f = Vector4<f32>;
using Vector4d = Vector4<f64>;

/* --------------------------------------- Implementation -------------------------------------- */
template <typename T>
constexpr Vector4<T> Vector4<T>::Zero() noexcept
{
  return Vector4<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
}

template <typename T>
constexpr Vector4<T> Vector4<T>::One() noexcept
{
  return Vector4<T>(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));
}

template <typename T>
constexpr Vector4<T> Vector4<T>::UnitX() noexcept
{
  return Vector4<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
}

template <typename T>
constexpr Vector4<T> Vector4<T>::UnitY() noexcept
{
  return Vector4<T>(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
}

template <typename T>
constexpr Vector4<T> Vector4<T>::UnitZ() noexcept
{
  return Vector4<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
}

template <typename T>
constexpr Vector4<T> Vector4<T>::UnitW() noexcept
{
  return Vector4<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
}

template <typename T>
constexpr Vector4<T>::Vector4() noexcept
    : x(static_cast<T>(0)),
      y(static_cast<T>(0)),
      z(static_cast<T>(0)),
      w(static_cast<T>(0))
{
}

template <typename T>
constexpr Vector4<T>::Vector4(T x) noexcept
    : x(x),
      y(static_cast<T>(0)),
      z(static_cast<T>(0)),
      w(static_cast<T>(0))
{
}

template <typename T>
constexpr Vector4<T>::Vector4(T x, T y) noexcept
    : x(x),
      y(y),
      z(static_cast<T>(0)),
      w(static_cast<T>(0))

{
}

template <typename T>
constexpr Vector4<T>::Vector4(T x, T y, T z) noexcept
    : x(x),
      y(y),
      z(z),
      w(static_cast<T>(0))
{
}

template <typename T>
constexpr Vector4<T>::Vector4(T x, T y, T z, T w) noexcept
    : x(x),
      y(y),
      z(z),
      w(w)
{
}

template <typename T>
template <typename U>
constexpr Vector4<T>::Vector4(const Vector4<U>& other) noexcept
    : x(static_cast<T>(other.x)),
      y(static_cast<T>(other.y)),
      z(static_cast<T>(other.z)),
      w(static_cast<T>(other.w))
{
}

template <typename T>
template <typename U>
constexpr Vector4<T>::Vector4(Vector4<U>&& other) noexcept
    : x(static_cast<T>(other.x)),
      y(static_cast<T>(other.y)),
      z(static_cast<T>(other.z)),
      w(static_cast<T>(other.w))
{
}

template <typename T>
template <typename U>
constexpr Vector4<T>& Vector4<T>::operator=(const Vector4<U>& other) noexcept
{
  if (this != &other) {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);
    w = static_cast<T>(other.w);
  }
  return *this;
}

template <typename T>
template <typename U>
constexpr Vector4<T>& Vector4<T>::operator=(Vector4<U>&& other) noexcept
{
  if (this != &other) {
    x = static_cast<T>(other.x);
    y = static_cast<T>(other.y);
    z = static_cast<T>(other.z);
    w = static_cast<T>(other.w);
  }
  return *this;
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator+(const Vector4<T>& v) const noexcept
{
  return Vector4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator-(const Vector4<T>& v) const noexcept
{
  return Vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator*(T scalar) const noexcept
{
  return Vector4<T>(x * scalar, y * scalar, z * scalar, w * scalar);
}

template <typename T>
constexpr Vector4<T> operator*(T scalar, const Vector4<T>& v) noexcept
{
  return Vector4<T>(v.x * scalar, v.y * scalar, v.z * scalar, v.w * scalar);
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator/(T scalar) const noexcept
{
  assert(std::abs(scalar) > epsilon && "Division by zero");
  if (std::abs(scalar) > epsilon)
    return Vector4<T>(x / scalar, y / scalar, z / scalar, w / scalar);
  return Vector4<T>();
}

template <typename T>
constexpr Vector4<T> Vector4<T>::operator-() const noexcept
{
  return Vector4<T>(-x, -y, -z, -w);
}

template <typename T>
constexpr Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& v) noexcept
{
  x += v.x;
  y += v.y;
  z += v.z;
  w += v.w;
  return *this;
}

template <typename T>
constexpr Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& v) noexcept
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
  w -= v.w;
  return *this;
}

template <typename T>
constexpr Vector4<T>& Vector4<T>::operator*=(T scalar) noexcept
{
  x *= scalar;
  y *= scalar;
  z *= scalar;
  w *= scalar;
  return *this;
}

template <typename T>
constexpr Vector4<T>& Vector4<T>::operator/=(T scalar) noexcept
{
  assert(std::abs(scalar) > epsilon && "Division by zero");
  if (std::abs(scalar) > epsilon) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;
  } else
    x = y = z = w = static_cast<T>(0);
  return *this;
}

template <typename T>
constexpr bool Vector4<T>::operator==(const Vector4<T>& v) const noexcept
{
  constexpr FloatComparator<T> comparator(5 * std::numeric_limits<T>::epsilon());
  return comparator.Compare(x, v.x) && comparator.Compare(y, v.y) && //
         comparator.Compare(z, v.z) && comparator.Compare(w, v.w);
}

template <typename T>
constexpr bool Vector4<T>::operator!=(const Vector4<T>& v) const noexcept
{
  constexpr FloatComparator<T> comparator(5 * std::numeric_limits<T>::epsilon());
  return !comparator.Compare(x, v.x) || !comparator.Compare(y, v.y) || //
         !comparator.Compare(z, v.z) || !comparator.Compare(w, v.w);
}

template <typename T>
constexpr T Vector4<T>::Length() const noexcept
{
  return std::sqrt(x * x + y * y + z * z + w * w);
}

template <typename T>
constexpr T Vector4<T>::LengthSquared() const noexcept
{
  return x * x + y * y + z * z + w * w;
}

template <typename T>
constexpr Vector4<T> Vector4<T>::Normalized() const noexcept
{
  T length = Length();
  return length > epsilon ? *this / length : Vector4<T>();
}

template <typename T>
constexpr Vector4<T>& Vector4<T>::Normalize() noexcept
{
  T length = Length();
  if (length > epsilon)
    *this /= length;
  else
    x = y = z = w = static_cast<T>(0);
  return *this;
}

template <typename T>
constexpr T Vector4<T>::Dot(const Vector4<T>& v) const noexcept
{
  return x * v.x + y * v.y + z * v.z + w * v.w;
}

template <typename T>
constexpr Vector4<T> Vector4<T>::Cross(const Vector4<T>& v) const noexcept
{
  return Vector4<T>(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, static_cast<T>(0));
}

template <typename T>
constexpr T Vector4<T>::AngleTo(const Vector4<T>& v) const noexcept
{
  T dotProduct = Dot(v);
  T lengthProduct = Length() * v.Length();
  return std::acos(dotProduct / lengthProduct);
}

template <typename T>
constexpr T Vector4<T>::DistanceTo(const Vector4<T>& v) const noexcept
{
  return (*this - v).Length();
}

template <typename T>
constexpr Vector4<T> Vector4<T>::Projected(const Vector4<T>& v) const noexcept
{
  T lengthSquared = v.LengthSquared();
  if (lengthSquared < epsilon)
    return Vector4<T>();
  return v * (Dot(v) / lengthSquared);
}

template <typename T>
constexpr Vector4<T>& Vector4<T>::Project(const Vector4<T>& v) noexcept
{
  T lengthSquared = v.LengthSquared();
  if (lengthSquared < epsilon)
    *this = Vector4<T>();
  else
    *this = v * Dot(v) / lengthSquared;
  return *this;
}

template <typename T>
constexpr Vector4<T> Vector4<T>::Lerp(const Vector4<T>& v, T t) const noexcept
{
  return *this * (static_cast<T>(1) - t) + v * t;
}

template <typename T>
constexpr Vector4<T> Vector4<T>::Reflected(const Vector4<T>& normal) const noexcept
{
  Vector4<T> n = normal.Normalized();
  return *this - static_cast<T>(2) * Dot(n) * n;
}

template <typename T>
constexpr Vector4<T>& Vector4<T>::Reflect(const Vector4<T>& normal) noexcept
{
  Vector4<T> n = normal.Normalized();
  *this -= static_cast<T>(2) * Dot(n) * n;
  return *this;
}

template <typename T>
std::string Vector4<T>::ToString(int precision) const noexcept
{
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(precision);
  oss << "(" << x << ", " << y << ", " << z << ", " << w << ")";
  return oss.str();
}

template <typename T>
constexpr std::ostream& operator<<(std::ostream& os, const Vector4<T>& v) noexcept
{
  return os << v.ToString();
}

} // namespace Engine::Core::Math
