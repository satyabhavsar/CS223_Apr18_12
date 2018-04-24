#include <iostream>
#include <fstream>
#include <string.h>
#include<cstring>
#include <cstdlib>
#include <stdio.h>

#include <iterator>
#include<dirent.h>
#include<unistd.h>
#include <limits>
#include <cstddef>
#include "Customer.h"

#include "Application.h"
#include "Admin.h"
class Application;


using namespace std;


void Cover_customer(Application p, Customer c, Admin a);
void Application::verify_login() {

    char username[40], password[40], no[40], po[40];

    int x = 0;

    char ch;

    for(;;) {
        if(x)
            break;
        else {



            cout <<
                 "\n                          Enter the username: ";
            cin.getline(username,40,'\n');

            string str = getpass("\n\n                          Enter the password: ");
            for (int i = 0; i < str.length(); i++)
                password[i] = str[i];
            password[str.length()]='\0';

            ifstream f;
            char retry;
            f.open("Admin_details.txt");

            f >> no;

            f >> po;

            x = !strcmp(no, username) && !strcmp(po, password);

            f.close();

            if (x == 0)

            {

                cout <<
                     "\n\n                          Incorrect username or password.\n\n                          Enter any character to retry.  ";
                cin>>retry;

                cin.clear();

                cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');


                

            }
        }
    }

    Admin a;

    a.login(username, password);
    system("clear");


    ( * this).Cover(a);

}

void Application::Cover(Admin a) {
    system("clear");
    
    int option;

    bool opt = false;

    cout << "\n                                         Choose the option : " << endl;

    cout <<
         "\n                          1. New User    2. Display user history   3. Exit" << endl;

    while (!opt) {
        cin >> option;
        if (cin.fail()) {
            cin.clear();

            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

        }
        system("clear");

        switch (option)

        {

        case 1:

        {

            opt = true;


            Customer c;

            c.Enter_details();

            Cover_customer( * this, c, a);
        }

        break;

        case 2:

label:  {
                opt = true;

                int found=a.Display_history();
                if(found) {
                    cout<<"\n                          Enter option.\n                           1. Home   2. Exit   ";
                    bool opt2=false;
                    int choice;
                    while(!opt2)
                    {
                        cin >> choice;


                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

                        }
                        switch (choice) {

                        case 1:
                        {   opt2 = true;
                            cin.clear();
                            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

                            ( * this).Cover(a);
                            break;
                        }
                        case 2:
                        {   opt2 = true;

                            exit(0);
                            break;
                        }

                        default:
                        {
                            cout << "\n\n                          Incorrect option. Enter again. :";
                        }

                        }
                    }
                }
                if (!found)

                {

                    cout << "\n                          The customer does not exist. ";

                    cout << "\n\n                          1.Retry      2. Exit ";
                    int choice;
                    bool opt3=false;
                    while (!opt3) {

                        cin >> choice;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
                        }
                        switch (choice) {

                        case 1:
                            opt3 = true;

                            goto label;
                            break;

                        case 2:
                            opt3 = true;

                            exit(0);
                            break;

                        default:
                            cout << "\n\n                          Incorrect option. Enter again. :";

                        }

                    }
                }
            }
            break;

        case 3:

        {   opt = true;

            exit(0);
        }

        break;

        default:

        {

            cout <<
                 "\n                          Incorrect option. Enter again.   ";

        }

        }

    }

}

