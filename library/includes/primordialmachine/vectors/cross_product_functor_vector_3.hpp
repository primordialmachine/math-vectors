#pragma once

#include "primordialmachine/vectors/cross_product_functor.hpp"
#include "primordialmachine/vectors/vector_n.hpp"

namespace primordialmachine {

template<typename LEFT_OPERAND_TRAITS, typename RIGHT_OPERAND_TRAITS>
struct cross_product_functor<
  vector<LEFT_OPERAND_TRAITS>,
  vector<RIGHT_OPERAND_TRAITS, void>,
  std::enable_if_t<LEFT_OPERAND_TRAITS::dimensionality == 3 &&
                   RIGHT_OPERAND_TRAITS::dimensionality == 3 &&
                   std::is_same_v<typename LEFT_OPERAND_TRAITS::element_type,
                                  typename RIGHT_OPERAND_TRAITS::element_type>>>
{
  using left_operand_type = vector<LEFT_OPERAND_TRAITS>;
  using right_operand_type = vector<RIGHT_OPERAND_TRAITS>;
  auto operator()(const left_operand_type& u, const right_operand_type& v) const
  {
    return vector<LEFT_OPERAND_TRAITS>(
      u(1) * v(2) - u(2) * v(1),
      u(2) * v(0) - u(0) * v(2),
      u(0) * v(1) - u(1) * v(0));
  }
}; // struct cross_product_functor

} // namespace primordialmachine
