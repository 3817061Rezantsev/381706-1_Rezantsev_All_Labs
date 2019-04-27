#include "gtest.h"
#include "../TextLib/TLink.cpp"

#include "../TextLib/TLink.h"
#include "../TextLib/TText.h"
#include "../TextLib/TText.cpp"
#include <windows.h>
#include <winuser.h>
#include <conio.h>
#include <string>
#include <stdio.h>
TMem TLink::mem;

char* m = "aaa";
bool g = true;

TLink *p = (TLink*)new char[sizeof(TLink) * 5];

TEST(TLink, can_create_link_with_zero_var)
{ 
  ASSERT_NO_THROW(TLink a);
}

TEST(TLink, can_create_link)
{
  TLink a;
  ASSERT_NO_THROW(TLink a(m,0,0));
}

TEST(TLink, can_set_and_get_flag)
{
  TLink a(m, 0, 0);
  a.SetFlag(g);
  ASSERT_EQ(g, a.GetFlag());
}

TEST(TLink, can_set_and_get_str)
{
  TLink a;
  a.SetLine(m);
  char* k = m;
  k = a.GetLine();
  ASSERT_EQ(k,a.GetLine());
}

TEST(TLink, can_set_and_get_pNext)
{
  TLink a;
  a.SetNext(p);
  ASSERT_EQ(p, a.GetNext());
}

TEST(TLink, can_set_and_get_pDown)
{
  TLink a;
  a.SetDown(p);
  ASSERT_EQ(p, a.GetDown());
}

TEST(TLink, can_initmem)
{
  TLink a;
  ASSERT_NO_THROW(a.InitMem(4));
}

TEST(TLink, can_new_and_del)
{
  TLink *p = new TLink(m, NULL, NULL);
  ASSERT_NO_THROW(delete p);
}

TEST(TText, can_create_text)
{ 
  ASSERT_NO_THROW(TText t);
}

TEST(TText, can_get_count)
{
  TText t;
  ASSERT_EQ(0,t.GetCount());
}

TEST(TText, can_get_first)
{
  TText t;
  ASSERT_NO_THROW(t.GetFirst());
}

TEST(TText, can_go_prev_link)
{
  TText t;
  ASSERT_EQ(t.GoPrevLink(), false);
}
/*
TEST(TText, can_set_curr)
{
  TText t;
  ASSERT_NO_THROW(t.SetCurr(m));
}

TEST(TText, can_go_next_link)
{
  TText t;
  ASSERT_EQ(t.GoNextLink(), false);
}

TEST(TText, can_go_down_link)
{
  TText t;
  ASSERT_EQ(t.GoDownLink(), false);
}


TEST(TText, exist_next)
{
  TText t;
  ASSERT_EQ(t.ExistNext(), false);
}

TEST(TText, exist_down)
{
  TText t;
  ASSERT_EQ(t.ExistDown(), false);
}

TEST(TText, can_mark)
{
  TText t;
  ASSERT_NO_THROW(t.MarkCurr());
}*/