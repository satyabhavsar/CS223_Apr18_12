#include<bits/stdc++.h>
#include<dirent.h>
#include "count_no_patterns.h"
using namespace std;

int  count_no_patterns()
{
    DIR*  dir;


    dir=opendir("/home/iitj/lptssplit/patterns/");
    dirent* pdir;
    int count=0;
    char filename[300];
    while (pdir = readdir(dir))
    {

        strcpy(filename, "/home/iitj/lptssplit/patterns/");
        strcat(filename, pdir->d_name);
        ifstream file;

        file.open(filename);

        if (file.is_open()&&pdir->d_name[0]!='.')
        {

            count++;
        }
        file.close();
    }
    closedir(dir);
    int count_patterns=count;

    return count;
}
