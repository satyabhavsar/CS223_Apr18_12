#include "Design.h"
#include<bits/stdc++.h>

using namespace std;

void Design::show() {

      for (int i = 0; i < 11; i++)

      {
        cout << "                          ";

        for (int j = 0; j < 37; j++)

          cout << des[i][j];

        cout << "\n";

      }

    }
