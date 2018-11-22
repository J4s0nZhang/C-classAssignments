#include <iostream>
#include "Prof.h"

using namespace std;

int Prof::copyName(char dest[], const char src[]) {
  int i = 0;
  while (src[i] != 0 && i < MAX_NAME_LENGTH) {
    dest[i] = src[i];
    ++i;
  }
  dest[i] = 0;
  return src[i];
}

void Prof::operator=(const Prof&p) {
  copyName(_firstName,p._firstName);
  copyName(_lastName,p._lastName);
  _dept = p._dept;
  _empID = p._empID;
  _hc = p._hc;
}

Prof::Prof() {
  _empID = -1;

}

Prof::~Prof() {
  _empID = -2;

}

Prof::Prof(const char* const firstName, const char* const lastName, const DEPARTMENT d, const int empID, const HAIR_COLOUR hc) {
  copyName(_firstName,firstName);
  copyName(_lastName,lastName);
  _dept = d;
  _empID = empID;
  _hc = hc;
}


std::ostream& operator<<(ostream& os, const Prof& p) {
  if (p._empID < -1) {
    cerr << "Trying to print deleted Prof; exiting" << endl;
    exit(-1);
  }
  if (p._empID == -1) {
    os << "Not-A-Prof";
    return os;
  }
  os << p._firstName << " " << p._lastName << " (" << p._empID << ")";
  return os;
}

///////////////////////////////////////////////////////////////////////////

int ProfList::insert(const Prof& p) {
  ProfList::ProfNode* pNewProf = new ProfList::ProfNode();
  pNewProf->_prof = p;
  pNewProf->_next = _first;
  _first = pNewProf;
  return 0;
}


//  const Prof& find(Prof::HAIR_COLOUR hc);
//  Prof*       remove(const int empId);
  
ProfList::ProfList() {
  _first = 0;
  _last = 0;
}


std::ostream& operator<<(ostream& os, const ProfList& p) {
  ProfList::ProfNode* pProfs = p._first;
  os << "[";
  while (pProfs) {
    os << "{" << pProfs->_prof << "}";
    if (pProfs->_next)
      os << "-->";
    pProfs = pProfs->_next;
  }
  os << "]";
  return os;
}






int main() {
  Prof p0;
  Prof p1("Paul","Ward",Prof::ECE,666,Prof::BROWN);
  Prof p2("Beelzebub","Jones",Prof::ECE,668,Prof::NONE);

  cout << "Prof p0: " << p0 << endl;
  cout << "Prof p1: " << p1 << endl;
  cout << "Prof p2: " << p2 << endl;

  ProfList pl;

  cout << "Prof List: " << pl << endl;

  pl.insert(p1);

  cout << "Prof List: " << pl << endl;

  pl.insert(p2);

  cout << "Prof List: " << pl << endl;

}
