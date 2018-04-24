#ifndef _Customer_h
#define __Customer_h
#pragma once
#include "Design.h"
class Admin;
//#include "Admin.h"

class Customer {

  char name[40];

  char contact_no[20];

  Design dc;

  public:
    void Enter_details();

 void SetDesign(Design x);
  
  friend Admin;

};

#endif
