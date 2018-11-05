///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Vectors Library
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

#include "primordialmachine/vectors/are_orthogonal_functor.hpp"
#include "primordialmachine/vectors/dot_product_functor_vector_n.hpp"
#include <type_traits>

namespace primordialmachine {

template<typename LEFT_OPERAND_TRAITS,
         typename RIGHT_OPERAND_TRAITS,
         typename EQUAL_TO_FUNCTOR>
struct are_orthogonal_functor<
  vector<LEFT_OPERAND_TRAITS>,
  vector<RIGHT_OPERAND_TRAITS>,
  EQUAL_TO_FUNCTOR,
  std::enable_if_t<
    std::is_floating_point_v<typename LEFT_OPERAND_TRAITS::element_type> &&
    std::is_floating_point_v<typename RIGHT_OPERAND_TRAITS::element_type>>>
{
  using left_operand_type = vector<LEFT_OPERAND_TRAITS>;
  using right_operand_type = vector<RIGHT_OPERAND_TRAITS>;
  using equal_to_functor_type = EQUAL_TO_FUNCTOR;
  auto operator()(const left_operand_type& u, const right_operand_type& v, equal_to_functor_type equal_to_functor)
  {
    // EQUAL_TO_FUNCTOR can be a relation of d == 0 e.g. abs(d) < 0.001f.
    const auto d = dot_product(u, v);
    return equal_to_functor(zero_functor<std::remove_cv_t<decltype(d)>>()(), d);
  }
}; // struct are_orthogonal_functor

} // namespace primordialmachine
