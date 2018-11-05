#include "TVector.h"

#include <gtest.h>
TEST(TVector, can_create_vector_with_positive_length)
{
	int a[3] = {0,1,2};
 ASSERT_NO_THROW(TVector<int> bf(a,3));
}
TEST(TVector, can_get_length)
{
	int a[3] = { 0,1,2 };
	TVector<int> bf(a, 3);

  EXPECT_EQ(3, bf.GetLength());
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	int a[3] = { 0,1,2 };
  ASSERT_ANY_THROW(TVector<int> bf(a, -3));
}
TEST(TVector, throws_when_get_value_with_too_large_index)
{
	int a[3] = { 0,1,2 };
	TVector<int> bf(a, 3);

  ASSERT_ANY_THROW(bf.GetValue(11));
}

TEST(TVector, throws_when_get_value_with_negative_index)
{
	int a[3] = { 0,1,2 };
	TVector<int> bf(a, 3);

  ASSERT_ANY_THROW(bf.GetValue(-3));
}
