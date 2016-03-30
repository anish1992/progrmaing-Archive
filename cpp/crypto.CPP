////////////////////////////////////////////////////////////////////////
//
// Title:                crypto.cpp
// Problem:        encriping and decripting a file with seed key
// Class:                  csc 340
// Date:                  2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<fstream>

using namespace std;


int main()
{
    char  n,  keystring[100];
    char FitoEncr[100], NewFiCrypt[100];
    unsigned int psswd=0, number= rand() ;
    
    cout<<"Please, enter a secret key :";
    cin.getline(keystring, 100);
    
    for( int i=0;keystring[i]!='\0'; i++) // generating seed
        psswd=(psswd+number)*keystring[i];
    
    cout<<"password: "<<keystring<<endl;
    cout<<"seed password: "<<psswd<<endl;
    
    cout<<"please, enter the name of the input file: ";
    cin.getline(FitoEncr,20);
    
    cout<<"please, enter the name of the output file: ";
    cin.getline(NewFiCrypt,20);
    
    //ENCRYPTION
    cout<<endl<<endl;
    cout<<"ENCRYPTION"<<endl;
    ifstream IS (FitoEncr, ios::in);
    ofstream OS ("temp.txt", ios::out);
    while(IS.get(n))    {
        
        srand(psswd);// referece for encription
        n ^= rand();
        OS<<n;
        cout<<n;
        
    }
    IS.close();
    OS.close();
    cout<<endl<<endl;
    //
    //
    //
    //DECRYPTION
    ifstream IS1 ("temp.txt", ios::in);
    ofstream OS1 (NewFiCrypt, ios::out);
    cout<<"DECRYPTION"<<endl;
    while(IS1.get(n))   {
        
        srand(psswd);// referece for encription
        n ^= rand();
        OS1<<n;
        cout<<n;
        
    }
    IS1.close();
    OS1.close();
    cout<<endl;
    
    return 0;
}