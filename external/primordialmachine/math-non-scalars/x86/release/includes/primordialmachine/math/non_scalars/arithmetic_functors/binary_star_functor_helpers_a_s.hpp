///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Non Scalars Library
// Copyright (c) 2019 Michael Heilmann
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

#include "primordialmachine/math/non_scalars/arithmetic_functors/arithmetic_functors_helpers.hpp"

namespace primordialmachine {

// The case of a * s where a is of type A and s is of type S.
// A is a non-scalar type with element type S.
// S is a scalar type.
// This case is reduced to the case s * a.
template<typename A, typename S>
struct default_elementwise_binary_star_functor<
  A,
  S,
  enable_if_t<is_non_scalar_v<A> && is_scalar_v<S> &&
              is_same_v<element_type_t<A>, S>>>
{
  using left_operand_type = A;

  using right_operand_type = S;

  using result_type = A;

  result_type operator()(const left_operand_type& a,
                         const right_operand_type& s) const
  {
    return s * a;
  }

}; // struct default_elementwise_binary_star_functor

} // namespace primordialmachine
