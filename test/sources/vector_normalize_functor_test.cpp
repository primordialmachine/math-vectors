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

#include "primordialmachine/vectors/include.hpp"
#include "gtest/gtest.h"

using vector_traits = primordialmachine::vector_traits<float, 3>;
using vector_type = primordialmachine::vector<vector_traits>;

TEST(vectors_tests, normalize_functor_vector_3_test)
{
  using namespace primordialmachine;
  auto value = normalize(vector_type(2.f, 3.f, 5.f),
                         euclidean_norm_functor<vector_type>());
  auto result = euclidean_norm(value) == 1.0f;
  ASSERT_TRUE(result);
}
