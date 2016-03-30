/*******************************************************************\
|  Program:  StringPointer.cpp                                      |
|  Problem:  String operations using pointers                       |
|  Purpose:  Demo for pointer operations                            |
|  Author :  Jozo Dujmovic                                          |
|  Date   :  3/23/2012                                              |
\*******************************************************************/

#include <iostream>     // include standard I/O routines
#include <iomanip>
using namespace std;    // allow access to all names of the std namespace

const char *s = "\"String with 27 characters\"";

int StrLen(char *s)
{
     char *p = s;
     while(*p++); //  p is incremented also for '\0'
     return p-s-1;
}

void StrCopy1(char *s, char *t)
{
     for(int n=0; t[n]=s[n]; n++);
}

void StrCopy2(char *s, char *t)
{
     while(*t++ = *s++);  // incrementing pointers
}

int main( )       
{  int i;
   char t[40], u[40];
   cout << s << " has " << StrLen(s) << " characters" << endl;
   cout << "String has " << StrLen("string") << " characters" << endl;
   cout << "Empty string has " << StrLen("") << " characters" 
        << "\n\nCopy using array indexing\n";

   StrCopy1(s,t);
   cout << t << "\n\nCopy using pointers\n";

   StrCopy2(t,u);
   cout << u << "\n\nDisplay 27 caracters using indexing\n";
   
   for(i=0; i<27; i++) cout << s[i]; 
   cout << "\n\nDisplay 27 caracters using pointers\n";
   for(i=0; i<27; i++) cout << *(s+i);
   cout << "\n\nDisplay string starting from various positions\n";
   for(i=0; i<27; i++) cout << s+i << endl;
   
   cout << endl; system("pause");
   return 0;           // return the exit code 0 to the OS
}

