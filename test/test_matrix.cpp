#include "../MatrixLib/TMatrix.h"

#include <gtest.h>
TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(7));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-7));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(7);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(7);
	EXPECT_EQ(7, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(8);
	m[1][2] = 3;
	EXPECT_EQ(3, m[1][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(7);
	ASSERT_ANY_THROW(m[-2][1] = 1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(7);
	ASSERT_ANY_THROW(m[9][1] = 1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(7);
	TMatrix<int> m2(8);
	m1[1][1] = 1;
	m2 = m1;
	EXPECT_EQ(7, m2.GetSize());
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	TMatrix<int> m3(3);
	m1[1][1] = 1;
	m2[1][1] = 3;
	m3[1][1] = 4;
	m2 = m1 + m2;
	EXPECT_EQ(m3[1][1], m2[1][1]);
}

TEST(TMatrix, cant_plus_with_not_equal_size)
{
	TMatrix<int> m1(7);
	TMatrix<int> m2(8);
	m1[1][1] = 1;
	m2[1][1] = 3;
	m2[2][2] = 3;
	ASSERT_ANY_THROW(m1 + m2);
}
TEST(TMatrix, cant_minus_with_not_equal_size)
{
	TMatrix<int> m1(7);
	TMatrix<int> m2(8);
	m1[1][1] = 1;
	m2[1][1] = 3;
	m2[2][2] = 3;
	ASSERT_ANY_THROW(m1 - m2);
}
TEST(TMatrix, cant_umnogenie_with_not_equal_size)
{
	TMatrix<int> m1(7);
	TMatrix<int> m2(8);
	m1[1][1] = 1;
	m2[1][1] = 3;
	m2[2][2] = 3;
	ASSERT_ANY_THROW(m1 * m2);
}

TEST(TMatrix, can_umnogenie_with_equal_size)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2(3);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3 - i; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 2;

		}
	m2 = m1 * m2;
	EXPECT_EQ(6, m2[0][2]);
}