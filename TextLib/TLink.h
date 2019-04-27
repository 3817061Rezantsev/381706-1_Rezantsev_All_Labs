#pragma once

class TLink;
class TMem
{
public:
  TLink* pFirst;
  TLink* pFree;
  TLink* pLast;
};

class TText;
class TLink
{
protected:
  TLink *pNext, *pDown;
  bool flag;
  char str[80];
public:
  bool GetFlag() { return flag; }
  TLink* GetNext() { return pNext; }
  TLink* GetDown() { return pDown; }
  void SetFlag(bool f) { flag = f; }
  void SetNext(TLink *pN) { pNext = pN; }
  void SetDown(TLink *pD) { pDown = pD; }
  TLink(char* s = 0, TLink *pN = 0, TLink * pD = 0);
  void SetLine(char* s);
  char* GetLine();
  static TMem mem;
  static void InitMem(size_t s);
  static void MemClear(TText& t);
  static int PrintFree(TText& t);
  void* operator new(size_t s);
  void operator delete(void* p);
  ~TLink();
};

