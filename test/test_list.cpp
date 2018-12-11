#include "../ListLib/TList.h"

#include <gtest.h>
TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> bf);
}

TEST(TList, can_set_val)
{
	TList<int> bf;
	ASSERT_NO_THROW(bf.PutBegin(0));
}

TEST(TList, can_clean)
{
	TList<int> bf;
	bf.PutBegin(0);
	bf.Clean();
	EXPECT_EQ(0, bf.GetSize());
}


TEST(TList, can_get_size)
{
	TList<int> bf;
	bf.PutBegin(0);
	EXPECT_EQ(1, bf.GetSize());
}


TEST(TList, can_delete)
{
	TList<int> bf;
	bf.PutBegin(0);
	bf.Delete(0);
	EXPECT_EQ(0, bf.GetSize());
}
