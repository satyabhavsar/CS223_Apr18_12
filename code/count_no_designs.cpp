#include<bits/stdc++.h>
#include<dirent.h>
#include "count_no_designs.h"
using namespace std;

int count_no_designs()
{
   DIR*  dir;
      
     
      dir=opendir("/home/iitj/lptssplit/designs/");
      dirent* pdir;
     int count=0;
     char filename[300];
       while (pdir = readdir(dir))
    {
        strcpy(filename,"/home/iitj/lptssplit/designs/");
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

   int count_designs=count;
return count;

}
