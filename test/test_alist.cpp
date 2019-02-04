#include <gtest.h>
#include "../AListLib/TAList.h"

TEST(TAList, can_create_list_with_not_specified_size)
{
	ASSERT_NO_THROW(TAList <int> L());
}

TEST(TAList, can_create_list_with_specified_size)
{
	ASSERT_NO_THROW(TAList <int> L(3));
}

TEST(TAList, can_create_copy_empty_list)
{
	TAList <int> L(1);
	L.PutStart(1);
	TAList <int> L2(L);
	ASSERT_EQ(L.GetStart(), L2.GetStart());
}

TEST(TAList, can_create_copy_not_empty_list)
{
	TAList <int> L(3);

	ASSERT_NO_THROW(TAList <int> L2(L));
}

TEST(TAList, throws_when_create_list_with_size_eq_zero)
{
	ASSERT_ANY_THROW(TAList <int> L(0));
}

TEST(TAList, throws_when_create_list_with_negative_size)
{
	ASSERT_ANY_THROW(TAList <int> L(-1));
}

TEST(TAList, can_get_and_put_start)
{
	TAList <int> L(2);
	L.PutStart(1);
	L.PutStart(2);
	ASSERT_EQ(2, L.GetStart());
	ASSERT_EQ(1, L.GetStart());
}

TEST(TAList, can_put_and_get_end)
{
	TAList <int> L(2);
	L.PutEnd(1);
	L.PutEnd(2);
	ASSERT_EQ(2, L.GetEnd());
	ASSERT_EQ(1, L.GetEnd());
}

TEST(TAList, can_use_full_check_false)
{
	TAList <int> L(1);
	ASSERT_FALSE(L.IsFull());
}

TEST(TAList, can_use_full_check_true)
{
	TAList <int> L(1);
	L.PutStart(5);
	ASSERT_TRUE(L.IsFull());
}

TEST(TAList, can_use_empty_check_false)
{
	TAList <int> L(1);
	L.PutStart(5);
	ASSERT_FALSE(L.IsEmpty());
}

TEST(TAList, can_use_empty_check_true)
{
	TAList <int> L(1);
	ASSERT_TRUE(L.IsEmpty());
}

TEST(TAList, throws_when_in_full_list_put_start_elem)
{
	TAList <int> L(1);
	L.PutStart(1);
	ASSERT_ANY_THROW(L.PutStart(2));
}

TEST(TAList, throws_when_in_full_list_put_finish_elem)
{
	TAList <int> L(1);
	L.PutStart(1);
	ASSERT_ANY_THROW(L.PutEnd(2));
}

TEST(TAList, throws_when_in_empty_list_get_start_elem)
{
	TAList <int> L(1);
	ASSERT_ANY_THROW(L.GetStart());
}

TEST(TAList, throws_when_in_empty_list_get_end_elem)
{
	TAList <int> L(1);
	ASSERT_ANY_THROW(L.GetEnd());
}

TEST(TAList, true_posledovatelnost_vivoda)
{
	TAList <int> L(5);
	L.PutStart(1); 
	L.PutEnd(2);   
	L.PutStart(3); 
	L.PutEnd(4);   
	L.PutStart(5);
	ASSERT_EQ(4, L.GetEnd());   
	ASSERT_EQ(5, L.GetStart());   
	ASSERT_EQ(2, L.GetEnd());     
	ASSERT_EQ(3, L.GetStart());   
	ASSERT_EQ(1, L.GetEnd());    
}

TEST(TAList, throws_when_in_empty_list_get_elem)
{
	TAList <int> L(10);
	ASSERT_ANY_THROW(L.Get(3));
}

TEST(TAList, throws_when_in_full_list_put_elem)
{
	TAList <int> L(3);
	L.PutEnd(1);
	L.PutEnd(1);
	L.PutEnd(1);

	ASSERT_ANY_THROW(L.Put(1, 6));
}

TEST(TAList, throws_when_incurrent_index_when_list_put_elem)
{
	TAList <int> L(4);
	L.PutEnd(1);
	L.PutEnd(1);
	L.PutEnd(1);

	ASSERT_ANY_THROW(L.Put(10, 6));
}

TEST(TAList, throws_when_incurrent_index_when_list_get_elem)
{
	TAList <int> L(3);
	L.PutEnd(1);
	L.PutEnd(1);
	L.PutEnd(1);

	ASSERT_ANY_THROW(L.Get(10));
}

TEST(TAList, can_get_elem)
{
	TAList <int> L(3);
	L.PutEnd(1);
	L.PutEnd(2);
	L.PutEnd(3);

	ASSERT_EQ(L.Get(1), 2);
}

TEST(TAList, can_put_elem)
{
	TAList <int> L(4);
	L.PutEnd(1);
	L.PutEnd(2);
	L.PutEnd(3);
	L.Put(2, 10);

	ASSERT_EQ(L.Get(1), 2);
	ASSERT_EQ(L.Get(1), 10);
}