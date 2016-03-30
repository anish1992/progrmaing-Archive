////////////////////////////////////////////////////////////////////////
//
// Title:               monte.cpp
// Problem:        banking program that edits client info
// Class:                  csc 340
// Date:                  2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<string>


using namespace std ;

struct client   {
    
    int account;
    char name[20];
    double balance;
} ;


int main()  {
    int n ,i = 0;
    char ans;
    
    cout << "Enter the details of 10 customers: \n"
         << "account number can not be '0' \n";
    
    client c[10];
    
    // client input
    ofstream os ("relative.txt", ios::out);
    for(i = 0 ; i < 10 ; i++ )  {
        
        cout << "\n\nCustomer " << i+1 << " : \n";
        
        cout << "Account number : ";
        cin >> c[i].account;
        os<<c[i].account<<' ';
        
        cout << "Name : ";
        scanf("%s", c[i].name);
        os<<c[i].name<<' ';
        
        cout << "Balance : ";
        cin >> c[i].balance;
        os<<c[i].balance<<'\n';
    }
    os.close();
    
    // Modify by 5% and update file
    do  {
        
        // account check
        ifstream is ("relative.txt", ios::in);
        while (i != n) {
            
            cout << "Enter acc no : ";
            cin >> n;
            
            for(i = 0 ; i < 10 ; i++ )  {
                
                if(c[i].account == n)   {
                    n = i;
                    break;
                }
            }
            
        }
        is.close();
        
        // change bal
        c[n].balance = (c[n].balance*105)/100.0;
        cout << "\n\n" << c[n].account
             << '\n' << c[n].name << endl
             << c[n].balance <<"\n\n";
        
        // update data file
        ofstream NewOs ("relative.txt", ios::out);
        for(i = 0 ; i < 10 ; i++ )  {
            
            NewOs<< c[i].account << ' '
                 << c[i].name << ' '
                 << c[i].balance << endl;
            
        }
        NewOs.close();
        
        cout << "Do want to modify anther account? (y/n) ";
        cin >> ans;
        
    }while( ans == 'y' || ans == 'Y' );
    
    
    cout<<"Thank you for using bank of anish\n";
    return 0 ;
}
