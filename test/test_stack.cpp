#include "..\StackLib\TStack.h"

#include "../gtest/gtest.h"
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> bf(3));
}

TEST(TStack, cannot_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> bf(-3));
}

TEST(TStack, can_set_and_get_val)
{
	TStack<int> bf(10);
	bf.Put(0);
	EXPECT_EQ(0, bf.Get());
}

TEST(TStack, cannot_get_empty_stack)
{
	TStack<int> bf(10);
	ASSERT_ANY_THROW(bf.Get());
}

TEST(TStack, cannot_set_full_stack)
{
	TStack<int> bf(0);
	ASSERT_ANY_THROW(bf.Put(1));
}

TEST(TQueue, can_copy_stack)
{
	TStack<int> S(3);
	S.Put(3);
	ASSERT_NO_THROW(TStack<int> S1(S));
}

TEST(Stack, correct_order_of_return_values)
{
	TStack <int> S(3);
	S.Put(3);
	S.Put(4);
	S.Put(5);
	ASSERT_EQ(5, S.Get());
	ASSERT_EQ(4, S.Get());
	ASSERT_EQ(3, S.Get());
}

TEST(Stack, is_full_false)
{
	TStack <int> S(3);
	ASSERT_FALSE(S.IsFull());
}

TEST(Stack, is_full_true)
{
	TStack <int> S(3);
	S.Put(3);
	S.Put(4);
	S.Put(5);
	ASSERT_TRUE(S.IsFull());
}

TEST(Stack, is_empty_false)
{
	TStack <int> S(3);
	S.Put(3);
	S.Put(4);
	ASSERT_FALSE(S.IsEmply());
}

TEST(Stack, is_empty_true)
{
	TStack <int> S(3);
	ASSERT_TRUE(S.IsEmply());
}
