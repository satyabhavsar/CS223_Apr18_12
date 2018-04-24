#include "Customer.h"

#include "Design.h"
#include<bits/stdc++.h>

using namespace std;

void Customer::SetDesign(Design x) {

    dc = x;

}
void Customer::Enter_details()	{
    int valid = 0, valid_cn = 0;
    cin.clear();

    cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

    cout << "\n                          Enter the name : ";

    while (!valid)

    {
        valid = 1;

        cin.getline(name,40,'\n');


        for (int i = 0; name[i] != '\0'; i++)

        {

            if (!isalpha(name[i])&&name[i]!=' ')

            {

                valid = 0;

                cout <<
                     "\n                          Invalid name. Name should contain only alphabets. Re-enter.";

                break;

            }

        }

    }

    cout << "\n                          Enter the contact no : ";

    while (!valid_cn)

    {
        valid_cn = 1;

        cin.getline(contact_no,20,'\n');

        int len = 0;

        for (int i = 0; contact_no[i] != '\0'; i++)

        {
            len++;

            if (!isdigit(contact_no[i]))

            {

                valid_cn = 0;

                cout <<
                     "\n                          Invalid Contact number. Contact number should contain only numbers without space. Re-enter.";

                break;

            }

        }

        if (len>16||len<7 && valid_cn)

        {

            valid_cn = 0;

            cout <<
                 "\n                          Invalid contact number. Contact number length must be between 7-16. Re-enter";

        }

    }

}
