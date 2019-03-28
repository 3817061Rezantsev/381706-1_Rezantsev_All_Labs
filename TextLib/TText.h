#pragma once
#include <iostream>
#include "TLink.h"
#include <stack>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <Windows.h>

class TText
{
  TLink*pFirst, *pCurr;
  std::stack<TLink*> st;
  int lvl;

public:
  TText() {}

  int gonxtlnk();
  int godwnlnk(); 
  int goprvlnk(); 
  void insnxtline(char*str); 
  void insnxtsection(char*str);
  void insdwnline(char*str); 
  void delnxt(); 
  void deldwn(); 
  void MarkCurr() { pCurr->flag = true; }

  TLink* cpyrec(TLink*tmp); 
  TLink* cpy(); 

  void reset();
  bool isend();
  void gonext();

  TLink*ReadRec(std::ifstream& file);
  void Read(char *fn);

  void View();
  void viewText(TLink *ptr);
  void Save(char* fn);
  void SaveText(TLink* tmp, std::ofstream& f);


};