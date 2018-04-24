#ifndef _Design_h
#define __Design_h
#pragma once
class Admin;
class Design {

  int id;

  char des[11][38];

  public:
    virtual void show();
  friend Admin;

};

#endif
