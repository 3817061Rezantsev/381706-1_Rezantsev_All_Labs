#include "TVector.h"
#include "gtest.h"

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int>(3));
}

TEST(TVector, can_get_length)
{
	TVector<int> bf(3);

	EXPECT_EQ(3, bf.GetSize());
}

TEST(TVector, cannot_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int>(-3));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> a(3);

	ASSERT_NO_THROW(TVector<int> b(a));
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v1(4);
	TVector<int> v2(4);

	ASSERT_NO_THROW(v1 = v2);
}

TEST(TVector, can_assign_vectors_of_non_size)
{
	TVector<int> v1(4);
	TVector<int> v2(5);

	ASSERT_NO_THROW(v1 = v2);
}


TEST(TVector, compare_vector_is_true)
{
	TVector<int> v1(4);

	for (int i(0); i < 4; ++i)
		v1[i] = 1;

	ASSERT_TRUE(v1 == v1);
}

TEST(TVector, cannot_plus_vectors_with_not_equal_size)
{
	TVector<int> a1(3);
	TVector<int> a2(4);

	ASSERT_ANY_THROW(a1 + a2);
}

TEST(TVector, cannot_minus_vectors_with_not_equal_size)
{
	TVector<int> a1(3);
	TVector<int> a2(4);

	ASSERT_ANY_THROW(a1 - a2);
}

TEST(TVector, can_umnogenie)
{
	TVector<int> v1(4);
	TVector<int> v2(4);
	for (int i(0); i < 4; ++i)
	{
		v1[i] = 1;
		v2[i] = 4;
	}
	
	v1 = v1 * 4;
	EXPECT_EQ(4,v1[1]);
}