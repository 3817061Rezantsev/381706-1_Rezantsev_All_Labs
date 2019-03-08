#include "../QueueLib/TQueue.h"
#include "../StackLib/TStack.h"
#include "gtest.h"

TEST(TQueue, can_create_queue)
{
  ASSERT_NO_THROW(TQueue<int> p(4));
}

TEST(TQueue, cant_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> p(-4));
}

TEST(TQueue, cant_add_in_full_queue)
{
  TQueue<int> p(5);
  for (int i = 0; i < 5; i++)
  {
    p.Put(i);
  }
  ASSERT_ANY_THROW(p.Put(4));
}

TEST(TQueue, can_get_next_elem_from_the_queue)
{
  TQueue<int> p(4);
  p.Put(2);
  EXPECT_EQ(p.Get(), 2);
}
TEST(TQueue, can_put_elem)
{
  TQueue<int> p(4);
  ASSERT_NO_THROW(p.Put(2));
}

TEST(TQueue, can_get_elem)
{
  TQueue<int> p(4);
  p.Put(2);
  ASSERT_NO_THROW(p.Get());
}

TEST(TQueue, can_correcttly_get_elem_from_the_queue)
{
  TQueue<int> p(4);
  p.Put(2);
  EXPECT_EQ(p.Get(), 2);
}

TEST(TQueue, can_check_queue_is_empty)
{
  TQueue<int> p(4);
  p.Put(1);
  EXPECT_EQ(p.IsEmpty(), 0);
  EXPECT_EQ(p.IsFull(), 0);
}

TEST(TQueue, can_check_queue_is_full)
{
  TQueue<int> p(2);
  p.Put(1);
  p.Put(2);
  EXPECT_EQ(p.IsFull(), 1);
}

TEST(TQueue, can_not_get_elem_from_empty_queue)
{
  TQueue<int> p(2);
  p.Put(1);
  p.Get();
  ASSERT_ANY_THROW(p.Get());
}

TEST(TQueue, can_not_put_elem_in_full_queue)
{
  TQueue<int> p(2);
  p.Put(1);
  p.Put(2);
  ASSERT_ANY_THROW(p.Put(3));
}

TEST(Queue, correct_order_of_return_values)
{
  TQueue <int> Q(3);
  Q.Put(5);
  Q.Put(4);
  Q.Put(3);
  Q.Get();
  Q.Put(5);
  ASSERT_EQ(4, Q.Get());
  ASSERT_EQ(3, Q.Get());
  ASSERT_EQ(5, Q.Get());
}