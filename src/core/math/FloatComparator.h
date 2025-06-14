/**
 * SPDX-License-Identifier: MIT
 *
 * @file FloatComparator.h
 * @brief Contains implementation of FloatComparator class
 *
 * @todo Add doxygen documentation
 *
 * @author Alexey Demin (AlexeyDeminA@gmail.com)
 */

#pragma once

#include <algorithm>
#include <limits>
#include <type_traits>

namespace Engine::Core::Math
{

template <typename T>
struct FloatComparator
{
  static_assert(std::is_floating_point<T>::value, "Template param T must be floating point");

  T epsilon;

  constexpr explicit FloatComparator(T epsilon = std::numeric_limits<T>::epsilon()) noexcept;

  constexpr bool Compare(T lhs, T rhs) const noexcept;
};

template <typename T>
constexpr FloatComparator<T>::FloatComparator(T epsilon) noexcept
    : epsilon(epsilon)
{
}

template <typename T>
constexpr bool FloatComparator<T>::Compare(T lhs, T rhs) const noexcept
{
  T diff = std::abs(lhs - rhs);
  T max = std::max(std::abs(lhs), std::abs(rhs));

  if (max == static_cast<T>(0))
    return true;

  return diff < max * epsilon;
}

} // namespace Engine::Core::Math
