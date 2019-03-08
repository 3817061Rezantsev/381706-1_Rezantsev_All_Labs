#include "TVector.h"
#include "gtest.h"
//-----------------------------------------------------------------------
TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int>(3));
}
//-----------------------------------------------------------------------
TEST(TVector, can_get_length)
{
  TVector<int> bf(3);

  EXPECT_EQ(3, bf.GetSize());
}
//-----------------------------------------------------------------------
TEST(TVector, cannot_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int>(-3));
}
//-----------------------------------------------------------------------
TEST(TVector, can_create_copied_vector)
{
  TVector<int> a(3);

  ASSERT_NO_THROW(TVector<int> b(a));
}
//-----------------------------------------------------------------------
TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v1(4);
  TVector<int> v2(4);

  ASSERT_NO_THROW(v1 = v2);
}
//-----------------------------------------------------------------------
TEST(TVector, can_assign_vectors_of_non_size)
{
  TVector<int> v1(4);
  TVector<int> v2(5);

  ASSERT_NO_THROW(v1 = v2);
}
//-----------------------------------------------------------------------
TEST(TVector, compare_vector_is_true)
{
  TVector<int> v1(4);

  for (int i(0); i < 4; ++i)
    v1[i] = 1;

  ASSERT_TRUE(v1 == v1);
}
//-----------------------------------------------------------------------
TEST(TVector, cannot_plus_vectors_with_not_equal_size)
{
  TVector<int> a1(3);
  TVector<int> a2(4);

  ASSERT_ANY_THROW(a1 + a2);
}
//-----------------------------------------------------------------------
TEST(TVector, cannot_minus_vectors_with_not_equal_size)
{
  TVector<int> a1(3);
  TVector<int> a2(4);

  ASSERT_ANY_THROW(a1 - a2);
}
//-----------------------------------------------------------------------
TEST(TVector, can_mult)
{
  TVector<int> v1(4);
  TVector<int> v2(4);
  for (int i(0); i < 4; ++i)
  {
    v1[i] = 1;
    v2[i] = 4;
  }

  v1 = v1 * 4;
  ASSERT_TRUE(v1 == v2);
}
//-----------------------------------------------------------------------
TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> a(7);

  ASSERT_NO_THROW(a = a);
}
//-----------------------------------------------------------------------
TEST(TVector, can_increase)
{
  TVector<int> a(6);

  ASSERT_NO_THROW(a++);
}
//-----------------------------------------------------------------------
TEST(TVector, can_add_number)
{
  TVector<int> a(6);

  ASSERT_NO_THROW(a + 6);
}
//-----------------------------------------------------------------------
TEST(TVector, can_subtract_number)
{
  TVector<int> a(6);

  ASSERT_NO_THROW(a - 6);
}
//-----------------------------------------------------------------------
TEST(TVector, can_add_float_number)
{
  TVector<int> a(6);

  ASSERT_NO_THROW(a + 6.5);
}
//-----------------------------------------------------------------------
TEST(TVector, can_subtract_float_number)
{
  TVector<int> a(6);

  ASSERT_NO_THROW(a - 6.5);
}
//-----------------------------------------------------------------------
TEST(TVector, can_decrease)
{
  TVector<int> a(6);

  ASSERT_NO_THROW(a--);
}
//-----------------------------------------------------------------------
TEST(TVector, can_multiply_vectors_of_equal_size)
{
  TVector<int> a1(6);
  TVector<int> a2(6);

  ASSERT_NO_THROW(a1*a2);
}
//-----------------------------------------------------------------------
TEST(TVector, cannot_multiply_vectors_of_not_equal_size)
{
  TVector<int> a1(6);
  TVector<int> a2(8);

  ASSERT_ANY_THROW(a1*a2);
}
//-----------------------------------------------------------------------
TEST(TVector, can_multiply_vector_and_const)
{
  TVector<int> a1(6);

  ASSERT_NO_THROW(a1 * 5);
}
//-----------------------------------------------------------------------
TEST(TVector, throws_when_position_is_less_then_0)
{
  TVector<int> a1(6);

  ASSERT_ANY_THROW(a1[-5]);
}
//-----------------------------------------------------------------------
TEST(TVector, throws_when_position_is_greatere_then_size)
{
  TVector<int> a1(6);

  ASSERT_ANY_THROW(a1[8]);
}
//-----------------------------------------------------------------------
TEST(TVector, when_position_is_adequate)
{
  TVector<int> a1(6);

  ASSERT_NO_THROW(a1[4]);
}
//-----------------------------------------------------------------------