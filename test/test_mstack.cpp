#include "../MStackLib/TMStack.h"
#include "../MStackLib/TNewStack.h"
#include "../StackLib/TStack.h"
#include "../Exception/Exception.h"
#include <gtest.h>
TEST(TNewStack, throws_when_create_newstack_with_negative_size)
{
  int *a = NULL;
  ASSERT_ANY_THROW(TNewStack<int> A(-1, a));
}

TEST(TNewStack, can_create_newstack)
{
  int *a = NULL;
  ASSERT_NO_THROW(TNewStack<int> A(3, a));
}

TEST(TNewStack, can_create_copy_newstack)
{
  int *a = NULL;
  TNewStack<int> S(2, a);
  ASSERT_NO_THROW(TNewStack<int> Sn(S));
}

TEST(TNewStack, can_get_Count_Free)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Put(3);
  S.Put(2);
  ASSERT_EQ(3, S.CountFree());
}

TEST(TNewStack, can_get_top)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Put(3);
  S.Put(2);
  ASSERT_EQ(2, S.GetTop());
}

TEST(TNewStack, can_get_size)
{
  int *a = NULL;
  TNewStack<int> S(5, a);
  ASSERT_EQ(5, S.GetSize());
}

TEST(TNewStack, can_set_multistack)
{
  int *a = new int[5];
  int *b = new int[5];
  TNewStack<int> S(5, a);
  S.SetMas(10, b);
  ASSERT_EQ(10, S.GetSize());
}

TEST(TNewStack, throw_set_multistack_negative_size)
{
  int *a = new int[5];
  int *b = new int[5];
  TNewStack<int> S(5, a);
  ASSERT_ANY_THROW(S.SetMas(-1, b));
}

TEST(TNewStack, can_put_and_get_elem)
{
  int *a = new int[5];
  TNewStack<int> S(5, a);
  S.Put(3);
  S.Put(2);
  ASSERT_EQ(2, S.Get());
  ASSERT_EQ(3, S.Get());
}


TEST(TMStack, can_create_mstack_with_positive_length)
{
  ASSERT_NO_THROW(TMStack<int> bf(3, 3));
}

TEST(TMStack, cannot_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TMStack<int> bf(-3, 3));
}

TEST(TMStack, cant_create_mstack_with_negative_kol)
{
  ASSERT_ANY_THROW(TMStack<int> A(0, 10));
}


TEST(TMStack, can_copy_mstack)
{
  TMStack<int> A(15, 3);
  ASSERT_NO_THROW(TMStack<int> B(A));
}

TEST(TMStack, can_set_and_get_val)
{
  TMStack<int> bf(10, 2);
  bf.Put(1, 3);
  EXPECT_EQ(3, bf.Get(1));
}

TEST(TMStack, throws_when_set_element_in_negative_index)
{
  TMStack<int> A(10, 2);
  ASSERT_ANY_THROW(A.Put(-2, 2));
}

TEST(TMStack, cannot_get_empty_stack)
{
  TMStack<int> bf(10, 2);
  ASSERT_ANY_THROW(bf.Get(1));
}

TEST(TMStack, cannot_set_full_stack)
{
  TMStack<int> bf(1, 1);
  ASSERT_ANY_THROW(bf.Put(1, 2));
}


TEST(TMStack, can_repack)
{
  TMStack<int> A(6, 2);
  A.Put(0, 1);
  A.Put(0, 2);
  A.Put(0, 3);
  A.Put(1, 3);
  ASSERT_NO_THROW(A.Put(0, 10));
  ASSERT_EQ(A.Get(0), 10);
}

TEST(TMStack, correct_order_return_value)
{
  TMStack <int> A(5, 2);
  A.Put(1, 1);
  A.Put(1, 2);
  A.Put(1, 3);
  ASSERT_EQ(3, A.Get(1));
  ASSERT_EQ(2, A.Get(1));
  ASSERT_EQ(1, A.Get(1));
}

TEST(TMStack, can_check_is_empty)
{
  TMStack<int> A(15, 5);
  ASSERT_TRUE(A.IsEmpty(1));
}

TEST(TMStack, can_check_is_full)
{
  TMStack<int> A(25, 5);
  A.Put(1, 43);
  A.Put(1, 43);
  A.Put(1, 43);
  A.Put(1, 43);
  A.Put(1, 43);
  EXPECT_EQ(1, A.IsFull(1));
}