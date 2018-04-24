#ifndef _Building_h
#define __Building_h
#pragma once
#include "Design.h"
#include "Pattern.h"
class Customer;
class Application;
class Admin;
void Cover_customer(Application p, Customer c, Admin a);
class Building: public Design{

  int id;

  char bp[11][38];

  Pattern lp[4];

  Design d[4];

  public:
    void show();
    
    void show_patterns();
  

  friend Admin;

  friend void Cover_customer(Application p, Customer c, Admin a);

};

#endif
