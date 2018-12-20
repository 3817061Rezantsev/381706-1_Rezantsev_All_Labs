#include "gtest.h"
#include "../AListLib/TAList.h"
TEST(TArrayList, can_create_array_list)
{
	ASSERT_NO_THROW(TArrayList<int> m);
}

TEST(TArrayList, can_create_copied_array_list)
{
	TArrayList<int> m;

	ASSERT_NO_THROW(TArrayList<int> m1(m));
}

TEST(TArrayList, can_put_and_get_start)
{
	TArrayList<int> m;
	m.PutStart(7);
	EXPECT_EQ(7, m.GetStart());
}

TEST(TArrayList, can_put_and_get_end)
{
	TArrayList<int> m;
	m.PutEnd(3);
	EXPECT_EQ(3, m.GetEnd());
}

TEST(TArrayList, throws_when_get_empty_start)
{
	TArrayList<int> m;
	ASSERT_ANY_THROW(m.GetStart());
}

TEST(TArrayList, throws_when_get_empty_end)
{
	TArrayList<int> m;
	ASSERT_ANY_THROW(m.GetEnd());
}