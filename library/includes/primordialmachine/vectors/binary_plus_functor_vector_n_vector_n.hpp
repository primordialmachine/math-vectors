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

template<typename TRAITS>
struct binary_plus_functor<vector<TRAITS>, vector<TRAITS>, void>
  : public elementwise_binary_vector_functor<
      TRAITS,
      binary_plus_functor<typename TRAITS::element_type,
                          typename TRAITS::element_type>>
{};

template<typename TRAITS>
auto
operator+(vector<TRAITS> const& u, vector<TRAITS> const& v)
{
  return binary_plus_functor<vector<TRAITS>, vector<TRAITS>>()(u, v);
}

template<typename TRAITS>
auto& /*TODO: Does this return a reference? Is this the best method?*/
operator+=(vector<TRAITS>& u, const vector<TRAITS>& v)
{
  u = u + v;
  return u;
}

} // namespace primordialmachine
