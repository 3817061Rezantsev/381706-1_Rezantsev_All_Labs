#include <gtest.h>
#include "THTable.h"
TEST(Elem, can_create_elem)
{
  ASSERT_NO_THROW(TElem<int>("key", 10));
}
// ---------------------------------------------------------------------------
TEST(Elem, can_create_copied_elem)
{
  TElem<int> elem1("key", 10);
  ASSERT_NO_THROW(TElem<int>elem2(elem1));
}
// ---------------------------------------------------------------------------
TEST(Elem, can_set_and_get_key)
{
  string key = "key";
  TElem<int> elem;
  ASSERT_NO_THROW(elem.SetKey(key));
  EXPECT_EQ(key, elem.GetKey());
}
// ---------------------------------------------------------------------------
TEST(Elem, can_set_and_get_data)
{
  TElem<int> elem;
  ASSERT_NO_THROW(elem.SetData(10));
  EXPECT_EQ(10, elem.GetData());
}
// ---------------------------------------------------------------------------
TEST(Elem, can_compare_two_elems)
{
  TElem<int> elem1("key1", 10);
  TElem<int> elem2("key1", 10);
  TElem<int> elem3("key2", 10);
  TElem<int> elem4("key3", 5);
  ASSERT_TRUE(elem1 == elem2);
  ASSERT_FALSE(elem1 == elem3);
  ASSERT_FALSE(elem1 == elem4);
}
// ---------------------------------------------------------------------------
TEST(Elem, can_assign_elem)
{
  TElem<int> elem1("key", 10);
  TElem<int> elem2;
  ASSERT_NO_THROW(elem2 = elem1);
  EXPECT_EQ("key", elem2.GetKey());
  EXPECT_EQ(10, elem2.GetData());
}
// ---------------------------------------------------------------------------
TEST(THTable, can_create_table)
{
  ASSERT_NO_THROW(THTable<int> table);
}
// ---------------------------------------------------------------------------
TEST(THTable, throw_when_creat_table_with_negative_size)
{
  ASSERT_ANY_THROW(THTable<int> table(-1));
}
// ---------------------------------------------------------------------------
TEST(THTable, can_create_copied_table)
{
  THTable<int> table1(5);
  ASSERT_NO_THROW(THTable<int> table2(table1));
}
// ---------------------------------------------------------------------------
TEST(THTable, can_and_get_size)
{
  THTable<int> table(5);
  EXPECT_EQ(5, table.GetSize());
}
// ---------------------------------------------------------------------------
TEST(THTable, can_delete_elem_from_table)
{
  THTable<int> table(5);
  table.Put("key", 10);
  ASSERT_NO_THROW(table.Del("key"));
}
// ---------------------------------------------------------------------------
TEST(THTable, throw_when_delete_elem_from_table_but_table_is_empty)
{
  THTable<int> table(5);
  ASSERT_ANY_THROW(table.Del("key"));
}