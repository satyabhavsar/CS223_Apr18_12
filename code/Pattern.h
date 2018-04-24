#ifndef _Pattern_h
#define _Pattern_h
class Admin;
#include "Design.h"

class Pattern: public Design {

  
  int id;
  char lpt[11][38];

  public:

   void show();
  friend Admin;

};

#endif
