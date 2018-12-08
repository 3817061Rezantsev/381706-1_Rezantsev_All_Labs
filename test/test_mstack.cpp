#include "..\MStackLib\TMStack.h"
#include "..\MStackLib\TNewStack.h"
#include "..\StackLib\TStack.h"
#include <gtest.h>
TEST(TMStack, can_create_mstack_with_positive_length)
{
	ASSERT_NO_THROW(TMStack<int> bf(3,3));
}

TEST(TMStack, cannot_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TMStack<int> bf(-3,3));
}

TEST(TMStack, can_set_and_get_val)
{
	TMStack<int> bf(10,2);
	bf.Put(1,3);
	EXPECT_EQ(3, bf.Get(1));
}

TEST(TMStack, cannot_get_empty_stack)
{
	TMStack<int> bf(10,2);
	ASSERT_ANY_THROW(bf.Get(1));
}

TEST(TMStack, cannot_set_full_stack)
{
	TMStack<int> bf(1,1);
	ASSERT_ANY_THROW(bf.Put(1,2));
}