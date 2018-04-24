#include<bits/stdc++.h>
#include "Application.h"
#include "Customer.h"
#include "Admin.h"
#include "count_no_buildings.h"
#include "count_no_patterns.h"
#include "count_no_designs.h"

using namespace std;

void
Cover_customer(Application p, Customer c, Admin a) {
    system("clear");

    int buil_no, pattern_no, option;
    int count_building=count_no_buildings();

    a.show_all_buildings();
    cout << "\n                          Select the building type: \n";

    cin >> buil_no;

    while (buil_no < 1 || buil_no > count_building || cin.fail())

    {
        cin.clear();

        cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

        cout << "\n                          Incorrect option. Enter again. :";

        cin >> buil_no;

    }

    buil_no = buil_no - 1;
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
    system("clear");

    a.bl[buil_no].show_patterns();
    cout << "\n                          Select the lighting pattern: \n";

    cin >> pattern_no;

    while (pattern_no < 1 || pattern_no > 4 || cin.fail())

    {
        cin.clear();

        cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

        cout << "\n                          Incorrect option. Enter again. :";

        cin >> pattern_no;

    }

    pattern_no = pattern_no - 1;
    cin.clear();
    cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
    system("clear");
   
    cout << "\n                          The simulated light pattern on building : \n";

    a.da[buil_no * 4 + pattern_no].show();

    cout << "\n                          1.Confirm   2.Home page  3.Back ";

    bool opt = false;

    while (!opt) {
        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
        }

        switch (option)

        {

        case 1:

        {
            char ch;
            opt = true;
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

            c.SetDesign(a.da[buil_no * 4 + pattern_no]);

            a.write_to_file(c);

            cout << "\n                          Lighting pattern confirmed.Press any key to continue.\n";
            cin>>ch;
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
            p.Cover(a);
        }

        break;

        case 2:

        {
            opt = true;
            system("clear");
            cin.clear();
            cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

         
            p.Cover(a);
        }

        break;
        case 3:
        {
            opt=true;
            system("clear");

            Cover_customer(p, c, a);
        }
        break;
        default:

        {

            cout <<
                 "\n                          Incorrect option. Choose again. \n";

        }

        break;

        }

    }

}
