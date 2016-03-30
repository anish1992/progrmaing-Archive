////////////////////////////////////////////////////////////////////////
//
// Title:                master.cpp
// Problem:  master program for finding quadratic equation
// Class:                 csc 340
// Date:                  2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

char *AddStr(string a, string b, string c) {
    int i=0,j=0,k=0;
    static char buffer[50];// pointer buffer
    char *p = buffer;
    while(a[i] != '\0')*p++ = a[i++];  // copy
    while(b[j] != '\0')*p++ = b[j++];  // append
    *p++ = ' ';
    while(c[k] != '\0')*p++ = c[k++];  // append
    return buffer;
}

int main(void)  {
    
    // getting values and running program
    string abc, filename = "file.dat", result;
    cout<<"enter a b c\n";
    getline(cin, abc);
    cout<<"command :"<<AddStr("./engine ",abc, filename)<<endl;
    system(AddStr("./engine ",abc, filename));
    
    // reading results
    cout<<"the result is";
    ifstream my(filename, ios::in);
    getline(my, result);
    cout<<" "<<result;
    my.close();
    cout<<endl;
    
   	return 0;
}
