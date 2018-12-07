#include "..\StackLib\TStack.h"

#include <gtest.h>
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> bf(3));
}

TEST(TStack, cannot_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> bf(-3));
}

TEST(TStack, can_create_stack_from_stack)
{
	TStack<int> a(4);
	ASSERT_NO_THROW(TStack<int> bf(a));
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