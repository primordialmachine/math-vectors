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

#include "primordialmachine/vectors/dot_product_functor.hpp"
#include "primordialmachine/vectors/vector_n.hpp"
#include <type_traits>

namespace primordialmachine {

template<typename LEFT_OPERAND_TRAITS, typename RIGHT_OPERAND_TRAITS>
struct dot_product_functor<
  vector<LEFT_OPERAND_TRAITS>,
  vector<RIGHT_OPERAND_TRAITS>,
  std::enable_if_t<LEFT_OPERAND_TRAITS::dimensionality ==
                   RIGHT_OPERAND_TRAITS::dimensionality>>
{
  static constexpr auto dimensionality = LEFT_OPERAND_TRAITS::dimensionality;
  using left_operand_type = vector<LEFT_OPERAND_TRAITS>;
  using right_operand_type = vector<RIGHT_OPERAND_TRAITS>;
  auto operator()(const left_operand_type& left_operand,
                  const right_operand_type& right_operand) const
  {
    return implementation(
      left_operand, right_operand, std::make_index_sequence<dimensionality>());
  }
  template<size_t... Is>
  auto implementation(const left_operand_type& left_operand,
                      const right_operand_type& right_operand,
                      std::index_sequence<Is...>) const
  {
    return ((left_operand(Is) * right_operand(Is)) + ...);
  }
}; // struct dot_product_functor

} // namespace primordialmachine
