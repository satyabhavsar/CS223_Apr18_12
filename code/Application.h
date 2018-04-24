#ifndef _Application_h
#define _Application_h
#include "Admin.h"
class Customer;
class Application;

class Application {
  public:
    void verify_login();
 
void Cover(Admin a);
  

  friend void Cover_customer(Application p, Customer c, Admin a);

};
#endif
