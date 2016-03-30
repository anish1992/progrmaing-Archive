//binary surch
#include<iostream>   //   cin, cout
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;

char *space(char* file) {
    
    static char r[50];
    char *p = r;
    int i = 0;
    while (file[i] != '\0') {
        *p++ = file[i++];
        if (file[i] == ' ')   {
            *p++ = (char)92;
        }
        
    }
    
    return r;
}


int main()  {
  
    char a[50] = "my neme is anish\n";
    cout<<space(a)<<endl;
    
    return 0;
}