#include "../SListLib/TSList.h"
#include "gtest.h"

TEST(TStackList, can_create_stack)
{
  ASSERT_NO_THROW(TSList<int> A);
}

TEST(TStackList, can_create_create_with_parametr)
{
  ASSERT_NO_THROW(TSList<int> A(3));
}

TEST(TStackList, can_create_create_with_negative_size)
{
  ASSERT_ANY_THROW(TSList<int> A(-1));
}

TEST(TStackList, can_create_copy_create)
{
  TSList<int> S(1);
  ASSERT_NO_THROW(TSList<int> A(S));
}

TEST(TStackList, can_get_max_size)
{
  TSList<int> S(15);
  ASSERT_EQ(S.GetMaxSize(), 15);
}

TEST(TStackList, can_get_size)
{
  TSList<int> S(5);
  S.Put(1);
  S.Put(2);
  ASSERT_EQ(S.GetSize(), 2);
}

TEST(TStackList, can_put)
{
  TSList<int> A;

  ASSERT_NO_THROW(A.PutBegin(43));
}

TEST(TStackList, throws_when_in_full_stack_put_elem)
{
  TSList<int> S(1);
  S.Put(2);
  ASSERT_ANY_THROW(S.Put(5));
}

TEST(TStackList, can_get)
{
  TSList<int> A;
  A.Put(42);
  EXPECT_EQ(42, A.Get());
}

TEST(TStackList, throws_when_from_empty_stack_get_elem)
{
  TSList <int> S(5);
  ASSERT_ANY_THROW(S.Get());
}

TEST(TStackList, can_use_empty_check_true)
{
  TSList<int> S(5);
  ASSERT_TRUE(S.IsEmpty());
}

TEST(TStackList, can_use_empty_check_false)
{
  TSList<int> S(1);
  S.Put(5);
  ASSERT_FALSE(S.IsEmpty());
}

TEST(TStackList, Right_input)
{
  TSList<int> S(3);
  S.Put(1), S.Put(2), S.Put(3);
  ASSERT_EQ(S.Get(), 3);
  ASSERT_EQ(S.Get(), 2);
  ASSERT_EQ(S.Get(), 1);
}