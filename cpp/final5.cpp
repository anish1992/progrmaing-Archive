// sort arrry

#include<iostream>
using namespace std;

int main()  {
    
    int a[10] = {10,4,3,5,1,7,8,6,9,2};
    int num = sizeof(a)/sizeof(*a), temp;
    for (int i= 0; i < sizeof(a)/sizeof(*a); i++)
        cout<<a[i]<<' ';
    cout<<endl;

    for (int i = 0; i < sizeof(a)/sizeof(*a)-1; i++) {
        
        
        for (int j = i + 1; j < sizeof(a)/sizeof(*a);j++)
            if (a[i] > a[j])   {
                
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        for (int i= 0; i < sizeof(a)/sizeof(*a); i++)
            cout<<a[i]<<' ';
        cout<<endl;

    }
    
    for (int i= 0; i < sizeof(a)/sizeof(*a); i++)
        cout<<a[i]<<' ';
    
    cout<<endl;
    
    return 0;
}