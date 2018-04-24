#include "Pattern.h"
#include "Design.h"
#include<bits/stdc++.h>
using namespace std;
void Pattern::show() {
      cout << id << endl;
      for (int i = 0; i < 11; i++)

      {
        cout << "                          ";

        for (int j = 0; j < 37; j++)

          cout << lpt[i][j];

        cout << "\n";

      }
    }
