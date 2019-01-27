///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Arithmetic Functors Library
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
struct plus_assignment_functor;

template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
auto
plus_assignment(LEFT_OPERAND& left_operand, const RIGHT_OPERAND& right_operand)
  -> decltype(
    plus_assignment_functor<LEFT_OPERAND, RIGHT_OPERAND>()(left_operand,
                                                           right_operand))
{
  return plus_assignment_functor<LEFT_OPERAND, RIGHT_OPERAND>()(left_operand,
                                                                right_operand);
}

template<typename LEFT_OPERAND, typename RIGHT_OPERAND>
auto
operator+=(LEFT_OPERAND& left_operand, const RIGHT_OPERAND& right_operand)
  -> decltype(
    plus_assignment_functor<LEFT_OPERAND, RIGHT_OPERAND>()(left_operand,
                                                           right_operand))
{
  return plus_assignment_functor<LEFT_OPERAND, RIGHT_OPERAND>()(left_operand,
                                                                right_operand);
}

template<typename T, typename ENABLED = void>
struct has_plus_assignment_functor
{
  static constexpr bool value = false;
}; // struct has_plus_assignment_functor

template<typename A, typename B>
constexpr bool has_plus_assignment_functor_v =
  has_plus_assignment_functor<plus_assignment_functor<A, B>>::value;

template<typename A, typename B>
struct has_plus_assignment_functor<
  plus_assignment_functor<A, B>,
  decltype(typeid(plus_assignment_functor<A, B>), void())>
{
  static constexpr bool value = true;
}; // struct has_plus_assignment_functor

} // namespace primordialmachine
