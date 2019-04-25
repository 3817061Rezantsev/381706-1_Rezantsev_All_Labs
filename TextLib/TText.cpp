#include "TText.h"

TText::TText()
{
  pCurr = NULL;
  pFirst = NULL;
  st = new stack<TLink*>;
  level = 0;
  CountLink = 0;
}
bool TText::GoNextLink()
{
  if (this->pCurr->GetNext() != NULL)
  {
    st->push(this->pCurr);
    pCurr = this->pCurr->GetNext();
    return true;
  }
  return false;
}
bool TText::GoDownLink()
{
  if (this->pCurr->GetDown() != NULL)
  {
    st->push(this->pCurr);
    pCurr = this->pCurr->GetDown();
    return true;
  }
  return false;
}

bool TText::GoPrevLink()
{
  if (!st->empty())
  {
    pCurr = st->top();
    st->pop();
    return true;
  }
  return false;
}
bool TText::ExistNext()
{
  if (this->pCurr->GetNext() != NULL)
    return true;
  return false;
}
bool TText::ExistDown()
{
  if (this->pCurr->GetDown() != NULL)
    return true;
  return false;
}

void TText::insNextLine(char* s)
{
  TLink *p = new TLink(s, pCurr->GetNext(), NULL);
  pCurr->SetNext(p);
  CountLink++;

}
void TText::insNextSection(char* s)
{
  TLink *p = new TLink(s, NULL, pCurr->GetNext());
  pCurr->SetNext(p);
  CountLink++;

}
void TText::insDownLine(char* s)
{
  TLink *p = new TLink(s, pCurr->GetDown(), NULL);
  pCurr->SetDown(p);
  CountLink++;
}
void TText::insDownSection(char* s)
{
  TLink *p = new TLink(s, NULL, pCurr->GetDown());
  pCurr->SetDown(p);
  CountLink++;
}
void TText::DelNext()
{
  TLink *p = pCurr->GetNext();
  if (p != NULL)
  {
    pCurr->SetNext(p->GetNext());
    delete p;
    if (p->GetDown() == NULL)
      CountLink--;
    else
    {
      CountLink = 0;
      for (Reset(); !IsEnd(); GoNext())
        CountLink++;
    }
  }
}
void TText::DelDown()
{
  TLink *p = pCurr->GetDown();
  if (p != NULL)
  {
    pCurr->SetDown(p->GetNext());
    delete p;
    CountLink--;
  }
}
TLink* TText::ReadRec(ifstream& file)
{
  char buf[80];
  TLink* tmp, *first;
  first = NULL;
  tmp = NULL;
  while (!file.eof())
  {
    file.getline(buf, 80, '\n');
    if (buf[0] == '}')
      break;
    else
    {
      if (buf[0] == '{')
        tmp->SetDown(ReadRec(file));
      else
      {
        if (first == NULL)
        {
          first = new TLink(buf);
          CountLink++;
          tmp = first;
        }
        else
        {
          tmp->SetNext(new TLink(buf));
          CountLink++;
          tmp = tmp->GetNext();
        }
      }
    }
  }
  return first;
}
void TText::Read(char* fn)
{
  ifstream ifs(fn);
  pFirst = ReadRec(ifs);
  pCurr = pFirst;
}
void TText::PrintText(TLink* tmp)
{
  if (tmp != NULL)
  {
    for (int i = 0; i < level; i++)
      cout << " ";
    cout << tmp->GetLine() << endl;
    level++;
    PrintText(tmp->GetDown());
    level--;
    PrintText(tmp->GetNext());
  }
}
void TText::Print()
{
  level = 0;
  PrintText(pFirst);
  pCurr = pFirst;
}
void TText::SaveText(TLink* tmp, ofstream& f)
{
  f << tmp->GetLine() << '\n';
  if (tmp->GetDown() != NULL)
  {
    f << "{\n";
    SaveText(tmp->GetDown(), f);
    f << "}\n";
  }
  if (tmp->GetNext() != NULL)
    SaveText(tmp->GetNext(), f);
}
void TText::Save(char* fn)
{
  ofstream ofs(fn, ios::in);
  if (ofs.is_open())
  {
    SaveText(pFirst, ofs);
    ofs.close();
  }
}
void TText::Reset()
{
  while (!st->empty())
  {
    st->pop();
  }
  pCurr = pFirst;
  st->push(pCurr);
  if (pFirst->GetNext() != NULL)
    st->push(pFirst->GetNext());
  if (pFirst->GetDown() != NULL)
    st->push(pFirst->GetDown());

}

bool TText::IsEnd()
{
  if (st->empty())
    return true;
  return false;
}

void TText::GoNext()
{
  pCurr = st->top();
  st->pop();
  if (pCurr != pFirst)
  {
    if (pCurr->GetNext() != NULL)
      st->push(pCurr->GetNext());
    if (pCurr->GetDown() != NULL)
      st->push(pCurr->GetDown());
  }
}
TText::~TText()
{
}
