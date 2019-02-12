#include "../ListLib/TList.h"

#include <gtest.h>
TEST(TNode, can_get_data)
{
  TNode<int> el(3, 0);
  ASSERT_EQ(el.GetData(), 3);
}

TEST(TNode, can_get_next)
{
  TNode<int>* a = 0;
  TNode<int> el(3, a);
  ASSERT_EQ(el.GetNext(), a);
}

TEST(TNode, can_create_elem_default)
{
  TNode<int> el;
  ASSERT_EQ(el.GetData(), 0);
}

TEST(TNode, can_set_data)
{
  TNode<int> el;
  el.SetData(5);
  ASSERT_EQ(el.GetData(), 5);
}

TEST(TNode, can_set_next)
{
  TNode<int>* a = 0;
  TNode<int> el;
  el.SetNext(a);

  ASSERT_EQ(el.GetNext(), a);
}

TEST(TNode, can_copy_elem)
{
  TNode<int> el(2, 0);
  TNode<int> el2(el);

  ASSERT_EQ(el.GetNext(), el2.GetNext());
  ASSERT_EQ(el.GetData(), el2.GetData());
}

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

TEST(TList, can_check_empty_true)
{
  TList<int> list;
  ASSERT_TRUE(list.IsEmpty());
}

TEST(TList, can_check_empty_false)
{
  TList<int> list;
  list.PutBegin(1);
  ASSERT_FALSE(list.IsEmpty());
}

TEST(TList, can_check_full_false)
{
  TList<int> list;
  ASSERT_FALSE(list.IsFull());
}

TEST(TList, can_get_begin)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);

  ASSERT_EQ(list.GetBegin(), 3);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 1);
}

TEST(TList, can_get_end)
{
  TList<int> list;
  list.PutBegin(3);
  list.PutBegin(2);

  ASSERT_EQ(list.GetEnd(), 3);
}

TEST(TList, no_Throw_when_create_copy_of_the_list)
{
  TList<int> otherlist;
  ASSERT_NO_THROW(TList<int> list(otherlist));
}

TEST(TList, can_put_begin)
{
  TList<int> list;
  list.PutBegin(3);
  list.PutBegin(2);
  list.PutBegin(1);

  ASSERT_EQ(list.GetBegin(), 1);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 3);
}

TEST(TList, can_put_end)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);

  ASSERT_EQ(list.GetBegin(), 1);
  ASSERT_EQ(list.GetBegin(), 2);
  ASSERT_EQ(list.GetBegin(), 3);
}

TEST(TList, can_get_size_no_zero)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(1);

  ASSERT_EQ(list.GetSize(), 2);
}

TEST(TList, can_get_size_zero)
{
  TList<int> list;

  ASSERT_EQ(list.GetSize(), 0);
}

TEST(TList, throw_get_elem_to_index_when_list_is_empty)
{
  TList<int> list;

  ASSERT_ANY_THROW(list.GetBegin());
}

TEST(TList, throw_get_elem_to_incorrent_val)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(1);
  list.PutBegin(1);

  ASSERT_ANY_THROW(list.GetCurrent(0));
}

TEST(TList, can_get_current_elem)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(2);
  list.PutBegin(3);
  TNode<int>* a = list.Search(2);

  ASSERT_EQ(list.GetCurrent(a), 2);
}

TEST(TList, throw_put_elem_to_incorrent_val)
{
  TList<int> list;
  list.PutBegin(1);
  list.PutBegin(1);
  list.PutBegin(1);
  TNode<int> a = 1;
  ASSERT_ANY_THROW(list.PutAfter(0, 0));
}

TEST(TList, can_put_elem_to_index)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);
  TNode<int>* a = list.Search(1);
  list.PutAfter(10, a);
  a = list.Search(10);
  ASSERT_EQ(list.GetCurrent(a), 10);
}

TEST(TList, throw_get_begin_and_get_end_when_list_is_empty)
{
  TList<int> list;

  ASSERT_ANY_THROW(list.GetBegin());
  ASSERT_ANY_THROW(list.GetEnd());
}

TEST(TList, can_copy_list)
{
  TList<int> list;
  list.PutEnd(1);
  list.PutEnd(2);
  list.PutEnd(3);
  TList<int> list2(list);

  ASSERT_EQ(list.GetBegin(), list2.GetBegin());
  ASSERT_EQ(list.GetBegin(), list2.GetBegin());
  ASSERT_EQ(list.GetBegin(), list2.GetBegin());
}

/*TEST(List, can_check_full_true)
{
  TList<int> list;
  try
  {
    while (1)
      list.PutEnd(1);
  }
  catch (...)
  {
    ASSERT_TRUE(list.IsFull());
  }
}*/