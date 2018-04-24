#include "Building.h"
#include "Pattern.h"

#include<bits/stdc++.h>
using namespace std;

void Building::show_patterns() {

    for (int i = 0; i < 4; i++)

    {
        cout << "\n";
        lp[i].show();
    }
}
void Building:: show()	{
    cout << id << endl;
    for (int i = 0; i < 11; i++)

    {
        cout << "                          ";

        for (int j = 0; j < 37; j++)

        {

            cout << bp[i][j];

        }
        cout << "\n";

    }
}
