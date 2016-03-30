////////////////////////////////////////////////////////////////////////
//
// Title:                str.cpp
// Problem:   appending strings on to a dynamic string
// Class:                 csc 340
// Date:                 04/24/2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

void print(char *a, int num )    {
    // printer of dynamic array string
    for(int j = 0; j<=num ; j++)
        cout <<*(a+j);

}

char* append(char *a, string b, int i)  {
    int j = 0;
    // copying real string to dynamic array string
    while (b[j] != '\0') {
        //cout<<i<<" from in "<<endl;
        *(a+i) = b[j];
        //cout<<*(a+i)<<endl;
        i++;
        j++;
    }
    
    return a;
}

int main()  {
    
    int i = 10; // random place holder for dynamicness
    char* data = new char[i];
    string a1 = "hi, ", a2 = "my ", a3 = "name ", a4= "is ", a5 = "anish\n";
    
    cout<<"transfering :"<<a1<<endl;
    data = append(data,a1,strlen(data));
    i = strlen(data); // counting char's in string
    cout<<"transfering :"<<a2<<endl;
    data = append(data,a2,strlen(data));
    i = strlen(data); // counting char's in string
    cout<<"transfering :"<<a3<<endl;
    data = append(data,a3,i);
    i = strlen(data); // counting char's in string
    cout<<"transfering :"<<a4<<endl;
    data = append(data,a4,i);
    i = strlen(data); // counting char's in string
    cout<<"transfering :"<<a5<<endl;
    data = append(data,a5,i);
    i = strlen(data); // counting char's in string
    
    print(data,strlen(data));
    
   	return 0;
}
