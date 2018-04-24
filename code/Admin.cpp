#include "Admin.h"
#include "Customer.h"
#include "Building.h"
#include "Design.h"
#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <string>
#include "count_no_buildings.h"
#include "count_no_patterns.h"
#include "count_no_designs.h"
using namespace std;

int count_building=count_no_buildings();
int count_design=count_no_designs();
int count_pattern=count_no_patterns();

Admin::Admin() {

    strcpy(name, "none");

    strcpy(pass, "not");
    
    for( int i=1; i<=count_building; i++)
    {   char filename[300]="";
        strcpy(filename,"/home/iitj/lptssplit/buildings/");

        string in=to_string(i);
        char indx[in.size()+1];
        for(int w=0; w<in.size(); w++)
            indx[w]=in[w];
        indx[in.size()]='\0';
        strcat(filename,"building");
        strcat(filename,indx);
        strcat(filename,".txt");



        ifstream file;
        file.open(filename);
        file>>bl[i-1].id;
        for (int r = 0; r < 11; r++)
        {
            for (int j = 0; j < 37; j++)

                file >> bl[i-1].bp[r][j];
        }
        file.close();
    }




    for( int i=1; i<=count_design; i++)
    {   char filename2[300]="";
        strcpy(filename2,"/home/iitj/lptssplit/designs/");
        string in=to_string(i);
        char indx[in.size()+1];
        for(int w=0; w<in.size(); w++)
            indx[w]=in[w];
        indx[in.size()]='\0';
        strcat(filename2,"design");
        strcat(filename2,indx);
        strcat(filename2,".txt");

        ifstream file;
        file.open(filename2);
        file>>da[i-1].id;
        for (int r = 0; r < 11; r++)

        {   for (int j = 0; j < 37; j++)

                file >> da[i-1].des[r][j];
        }
        file.close();
    }


    for( int i=1; i<=count_pattern; i++)
    {
        for(int j=1; j<=4; j++) {
            char filename3[300]="";
            strcpy(filename3,"/home/iitj/lptssplit/patterns/");
            string in1=to_string(i);
            char indxi[in1.size()+1];
            for(int w=0; w<in1.size(); w++)
                indxi[w]=in1[w];
            indxi[in1.size()]='\0';
            string in=to_string(j);
            char indxj[in.size()+1];
            for(int w=0; w<in.size(); w++)
                indxj[w]=in[w];
            indxj[in.size()]='\0';
            strcat(filename3,"pattern");
            strcat(filename3,indxi);
            strcat(filename3,"_");
            strcat(filename3,indxj);
            strcat(filename3,".txt");
            ifstream  file;
            file.open(filename3);
            file>>bl[i-1].lp[j-1].id;
            for (int r = 0; r < 11; r++)

                for (int col = 0; col < 37; col++)

                    file >> bl[i-1].lp[j-1].lpt[r][col];
            file.close();
        }

    }


}



void Admin:: write_to_file(Customer c) {
    
    ofstream f;

    f.open("Customer_details.dat", ios::out|ios::app);

    f.write((char * ) & c, sizeof(c));

}

void Admin::login(char n[], char p[]) {

    strcpy(name, n);

    strcpy(pass, p);

}
void Admin::show_all_buildings() {

    for (int i = 0; i < count_building; i++)

    {

        bl[i].show();

        cout << "\n\n";

    }
}
int Admin::Display_history() {
    system("clear");

    int found = 0;

    Customer w;

    char c_name[40], c_contact_no[40];

    int choice;

    bool opt = false;
    cin.clear();

    cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');


    cout << "\n                          Enter Customer name: ";

    cin.getline(c_name,40,'\n');
    cout << "\n\n                          Enter contact number: ";

    cin.getline(c_contact_no,40,'\n');

    ifstream file;

    file.open("Customer_details.dat", ios:: in );


    while (file.read((char * ) & w, sizeof(w)))

    {

        if (!strcmp(w.name, c_name) && !strcmp(w.contact_no, c_contact_no))

        {
            found = 1;

            cout << "\n                          The design for requested customer is :\n";

            w.dc.show();

        }

    }



    return found;

}



