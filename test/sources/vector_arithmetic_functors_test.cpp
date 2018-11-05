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
using vector_type =
  primordialmachine::vector<vector_traits>;

TEST(vectors_tests, vector_3_default_constructor_test)
{
  using namespace primordialmachine;
  vector_type();
}

TEST(vectors_tests, vector_3_constructor_test)
{
  using namespace primordialmachine;
  vector_type(0.f, 1.f, 2.f);
}

TEST(vectors_tests, binary_plus_vector_3_vector_3_test)
{
  using namespace primordialmachine;
  auto result = vector_type(6.f, 6.f, 6.f) ==
                vector_type(4.f, 4.f, 4.f) + vector_type(2.f, 2.f, 2.f);
  ASSERT_TRUE(result);
}
TEST(vectors_tests, plus_assignment_vector_3_vector_3_test)
{
  using namespace primordialmachine;
  auto lhs = vector_type(4.f, 4.f, 4.f);
  lhs += vector_type(2.f, 2.f, 2.f);
  auto result = vector_type(6.f, 6.f, 6.f) == lhs;
  ASSERT_TRUE(result);
}

TEST(vectors_tests, binary_minus_vector_3_vector_3_test)
{
  using namespace primordialmachine;
  auto result = vector_type(2.f, 2.f, 2.f) ==
                vector_type(4.f, 4.f, 4.f) - vector_type(2.f, 2.f, 2.f);
  ASSERT_TRUE(result);
}
TEST(vectors_tests, minus_assignment_vector_3_vector_3_test)
{
  using namespace primordialmachine;
  auto lhs = vector_type(4.f, 4.f, 4.f);
  lhs -= vector_type(2.f, 2.f, 2.f);
  auto result = vector_type(2.f, 2.f, 2.f) == lhs;
  ASSERT_TRUE(result);
}

TEST(vectors_tests, binary_star_vector_3_vector_3_test)
{
  using namespace primordialmachine;
  auto result = vector_type(8.f, 8.f, 8.f) ==
                vector_type(4.f, 4.f, 4.f) * vector_type(2.f, 2.f, 2.f);
  ASSERT_TRUE(result);
}

TEST(vectors_tests, binary_slash_vector_3_vector_3_test)
{
  using namespace primordialmachine;
  auto result = vector_type(2.f, 2.f, 2.f) ==
                vector_type(4.f, 4.f, 4.f) / vector_type(2.f, 2.f, 2.f);
  ASSERT_TRUE(result);
}
TEST(vectors_tests, slash_assignment_vector_3_vector_3_test)
{
  using namespace primordialmachine;
  auto lhs = vector_type(4.f, 4.f, 4.f);
  lhs /= vector_type(2.f, 2.f, 2.f);
  auto result = vector_type(2.f, 2.f, 2.f) == lhs;
  ASSERT_TRUE(result);
}

TEST(vectors_tests, unary_plus_vector_3_test)
{
  using namespace primordialmachine;
  auto result = vector_type(4.f, 4.f, 4.f) == +vector_type(4.f, 4.f, 4.f);
  ASSERT_TRUE(result);
}

TEST(vectors_tests, unary_minus_vector_3_test)
{
  using namespace primordialmachine;
  auto result = vector_type(-4.f, -4.f, -4.f) == -vector_type(4.f, 4.f, 4.f);
  ASSERT_TRUE(result);
}

TEST(vectors_tests, binary_star_vector_3_scalar_test)
{
  using namespace primordialmachine;
  auto result = vector_type(8.f, 8.f, 8.f) == vector_type(4.f, 4.f, 4.f) * 2.f;
  ASSERT_TRUE(result);
}
TEST(vectors_tests, star_assignment_vector_3_scalar_test)
{
  using namespace primordialmachine;
  auto lhs = vector_type(4.f, 4.f, 4.f);
  lhs *= 2.f;
  auto result = vector_type(8.f, 8.f, 8.f) == lhs;
  ASSERT_TRUE(result);
}

TEST(vectors_tests, binary_star_scalar_vector_3_test)
{
  using namespace primordialmachine;
  auto lhs = vector_type(8.f, 8.f, 8.f);
  auto rhs = 2.f * vector_type(4.f, 4.f, 4.f);
  auto result = lhs == rhs;
  ASSERT_TRUE(result);
}

TEST(vectors_tests, binary_slash_vector_3_scalar_test)
{
  using namespace primordialmachine;
  auto result = vector_type(2.f, 2.f, 2.f) == vector_type(4.f, 4.f, 4.f) / 2.f;
  ASSERT_TRUE(result);
}
TEST(vectors_tests, slash_assignment_vector_3_scalar_test)
{
  using namespace primordialmachine;
  auto lhs = vector_type(4.f, 4.f, 4.f);
  lhs /= 2.f;
  auto result = vector_type(2.f, 2.f, 2.f) == lhs;
  ASSERT_TRUE(result);
}
