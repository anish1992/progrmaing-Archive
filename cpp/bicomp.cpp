////////////////////////////////////////////////////////////////////////
//
// Title:                bicomp.cpp
// Problem:        comprestion by letter
// Class:                 me
// Date:                  2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>

using namespace std;

int numComp (char a)    {
    
}

int comp(char* file)   {
    
    int fSize = 0, lNum = 0;
    char n;
    string fTemp "f.dat.temp", lTemp ="";
    
    ifstream ch (file, ios::in);
    if (ch) while (ch.get(n))size++;
    else return 1;
    ch.close();
    
    return 0;
}

int decomp(char* file) {
    
}

int main(int argc, char* argv[])  {
    
    char ch = 'y';
    char file[100];
    
    if (argc < 2)   {
        
        while (ch == 'y') {
            
            cout<<"to compress say 'y' \nto decompress say 'n'\n";
            cin>>ch;
            
            if (ch == 'y') {
                
                cout<<"enter a file name :\n";
                file[0] = '\0';
                scanf("%s", file);
                
                comp(file);
                
            }   else    {
                
                cout<<"enter a file name :\n";
                file[0] = '\0';
                scanf("%s", file);
                
                decomp(file);
            }
            
            cout<<"if you want to use program say 'y' :\n";
            cin>>ch;
        }
    }   else    {// phase is not raddy;
            cout<<"coming soon\n";
    }
    return 0;
}