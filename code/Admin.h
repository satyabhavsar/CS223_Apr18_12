#ifndef _Admin_h
#define _Admin_h
#pragma once
#include "Design.h"
#include "Building.h"
#include<string>
class Customer;
class Application;
class Pattern;
class Design;
class Building;


///cover customer
void Cover_customer(Application p, Customer c, Admin a);

class Admin {

  char name[40];

  char pass[40];

  Building bl[10];

  Design da[40];

  public:
    Admin();
	
	 
  friend void Cover_customer(Application p, Customer c, Admin a);
  void write_to_file(Customer c) ;
  void login(char n[], char p[]);
  void show_all_buildings();
  int Display_history();
  

};

#endif
