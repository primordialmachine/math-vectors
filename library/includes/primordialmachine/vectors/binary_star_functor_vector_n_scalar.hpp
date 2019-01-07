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

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/vectors/vector_n.hpp"

namespace primordialmachine {

template<typename TRAITS, typename SCALAR>
struct binary_star_functor<vector<TRAITS>,
                           scalar_generator_functor<SCALAR>,
                           void>
  : elementwise_binary_functor<
      vector<TRAITS>,
      scalar_generator_functor<SCALAR>,
      vector<TRAITS>,
      TRAITS::dimensionality,
      binary_star_functor<typename TRAITS::element_type, SCALAR>,
      void>
{};

template<typename TRAITS, typename SCALAR>
auto operator*(vector<TRAITS> const& v, SCALAR s)
{
  using v_type = vector<TRAITS>;
  using g_type = scalar_generator_functor<SCALAR>;
  return binary_star_functor<v_type, g_type>()(v, g_type(s));
}

template<typename TRAITS, typename SCALAR>
auto& /*TODO: Does this return a reference? Is this the best method?*/
operator*=(vector<TRAITS>& v, SCALAR s)
{
  v = v * s;
  return v;
}

template<typename TRAITS, typename SCALAR>
struct binary_star_functor<scalar_generator_functor<SCALAR>,
                           vector<TRAITS>,
                           void>
  : elementwise_binary_functor<
      scalar_generator_functor<SCALAR>,
      vector<TRAITS>,
      vector<TRAITS>,
      TRAITS::dimensionality,
      binary_star_functor<SCALAR, typename TRAITS::element_type>,
      void>
{};

template<typename TRAITS, typename SCALAR>
auto
operator*(SCALAR s, vector<TRAITS> const& v)
{
  using g_type = scalar_generator_functor<SCALAR>;
  using v_type = vector<TRAITS>;
  return binary_star_functor<g_type, v_type>()(g_type(s), v);
}

} // namespace primordialmachine
