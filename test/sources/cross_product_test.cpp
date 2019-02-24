///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Vectors Library
// Copyright (c) 2017-2019 Michael Heilmann
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

#include "primordialmachine/math/vectors/include.hpp"
#include "gtest/gtest.h"

using vector_traits = primordialmachine::vector_traits<float, 3>;
using vector_type = primordialmachine::vector<vector_traits>;

TEST(vectors_tests, cross_product_test)
{
  using namespace primordialmachine;
  ASSERT_TRUE(cross_product(vector_type(+1.f, 0.f, 0.f), vector_type(0.f, +1.f, 0.f)) == vector_type(0.f, 0.f, +1.f));
  ASSERT_TRUE(cross_product(vector_type(-1.f, 0.f, 0.f), vector_type(0.f, +1.f, 0.f))  == vector_type(0.f, 0.f, -1.f));
}
