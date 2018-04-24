
#include <iostream> 
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <stdio.h> 
//#include <conio.h>
#include <limits> 
#include <cstddef>

#include "Admin.h"
#include "Customer.h"
#include "Application.h"
#include "Building.h"
#include "Design.h"
#include "Pattern.h"
int count_no_buildings();
int count_no_patterns();
int count_no_designs();
void Cover_customer(Application p, Customer c, Admin a);

using namespace std;



int
main() {

  Application q;

  q.verify_login();

}
