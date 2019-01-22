///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Relational Functors Library
// Copyright (C) 2017-2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "primordialmachine/functors/include.hpp"

namespace primordialmachine {

template<typename LEFT_OPERAND, typename RIGHT_OPERAND, typename ENABLED = void>
struct equal_to_functor;

template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
auto
equal_to(const LEFT_OPERAND& left_operand, const RIGHT_OPERAND& right_operand)
  -> decltype(equal_to_functor<LEFT_OPERAND, RIGHT_OPERAND>()(left_operand,
                                                              right_operand))
{
  return equal_to_functor<LEFT_OPERAND, RIGHT_OPERAND>()(left_operand,
                                                         right_operand);
}

// Default implementation for floating point types.
template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
struct equal_to_functor<
  LEFT_OPERAND,
  RIGHT_OPERAND,
  enable_if_t<is_floating_point_v<LEFT_OPERAND> &&
              is_floating_point_v<RIGHT_OPERAND>>>
{
  using left_operand_type = LEFT_OPERAND;
  using right_operand_type = RIGHT_OPERAND;
  using result_type = bool;
  auto operator()(LEFT_OPERAND x, RIGHT_OPERAND y) const
    noexcept(noexcept(x == y))
  {
    return x == y;
  }
}; // struct equal_to_functor

template<typename A, typename B>
auto
operator==(const A& a, const B& b) -> decltype(equal_to(a, b))
{
  return equal_to(a, b);
}

} // namespace primordialmachine
