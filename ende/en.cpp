//temp sencription

#include<iostream>
#include<fstream>
#include<cstring>
#include<string.h>
#include<math.h>
using namespace std;

void crypto (int a, ostream& io, istream& is)  {
    
    int c='a', b='c';
    char n;
    
    while (is.get(n)) {
        
        srand(a);
        n ^= rand();
        srand(b);
        n ^= rand();
        srand(c);
        n ^= rand();
        
        io<<n;
        
    }

}

int num (char *q)   {
    
    int a = 0;
    a += ((int)q[0]-'0')*1000;
    a += ((int)q[1]-'0')*100;
    a += ((int)q[2]-'0')*10;
    a += ((int)q[3]-'0')*1;
    
    return a;
}

void final  (string file)    {
    
    char n;
    ifstream is (".out.dat", ios::in);
    ofstream io (file, ios::out);
    while (is.get(n)) {
        
        io<<n;
        
    }
    is.close();
    io.close();
    system("rm .out.dat");
}

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

int en (char *Wfile, char *q)   {
    
    int a;
    char a1, a2, a3, a4;
    string file = Wfile;
    file += ".txt";
    
    ifstream ch (Wfile, ios::in);
        if(!ch) return 1;
    ch.close();
    
    system(AddStr("mv ",Wfile,file));
    
    a1 = (char)((q[0]-'0'));
    a2 = (char)((q[1]-'0'));
    a3 = (char)((q[2]-'0'));
    a4 = (char)((q[3]-'0'));
    
    a = num(q);
    
    ifstream is (file, ios::in);
    ofstream io (".out.dat", ios::out);
    if (is) {
        io<<a1<<a2<<a3<<a4;
        
        crypto(a, io, is);
    }   else    {
        return 1;
    }
    is.close();
    io.close();
    
    final(file);
    system(AddStr("mv ",file,Wfile));
    delete a1, a2, a3, a4;
    delete a;
    return 0;
}

int de (char *Wfile, char *q)   {
    
    int a[4];
    int i = 0;
    int an;
    char n, n1;
    
    string file = Wfile;
    file += ".txt";
    
    ifstream ch (Wfile, ios::in);
    if(!ch) return 1;
    ch.close();
    
    system(AddStr("mv ",Wfile,file));
    
    ifstream is (file, ios::in);
    
    if (is.eof())return 1;
    
    while (i < 4) {
        is.get(n);
        a[i] = n;
        i++;
    }
    i = 0;
    
    while (i != 4) {
        if (i < 4) {
            n1 = (int)(q[i]-'0');
            if( n1 != a[i]) {
                system(AddStr("mv ",file,Wfile));
                return 1;
            }
            i++;
        }
    }
    
    an = num(q);
    
    ofstream io (".out.dat", ios::out);
    
    crypto(an, io, is);
    
    is.close();
    io.close();
    
    final(file);
    system(AddStr("mv ",file,Wfile));
    delete[] a;
    delete n, n1, an;
    return 0;
}

int main(int argc, char* argv[])  {
    
    char ch = 'y';
    char file[100], q[5];
    
    if (argc < 2)   {
        
        while (ch == 'y') {
            
            cout<<"to encrpt say 'y' \nto decropt say 'n'\n";
            cin>>ch;
        
            if (ch == 'y') {
                
                cout<<"enter a file name :\n";
                file[0] = '\0';
                scanf("%s", file);
                
                cout<<"enter an encription pin :\n";
                scanf("%s", q);
                if(en(file,q))cout<<"encription failed\n";
                else cout<<"encription done\n";
                
            }   else    {
                
                cout<<"enter a file name :\n";
                file[0] = '\0';
                scanf("%s", file);
                
                cout<<"enter a decription pin :\n";
                scanf("%s", q);
                if(de(file,q)) cout<<"decription failed\n";
                else cout<<"decription done\n";
                
            }
       
            cout<<"if you want to use program say 'y' :\n";
            cin>>ch;
        }
    }   else    {
        
        ofstream io2 (".log.dat", ios::out | ios::app);
        
        if (atof(argv[1])) {
            
            io2<<"en "<<argv[2]<<" "<<argv[3];
            ofstream io (".progress.dat", ios::out);
            if(en(argv[2],argv[3]))     {
                io<<"Encription failed\n";
                io2<<" encription failed\n";
                
            }   else    {
                io<<"Encription done\n";
                io2<<" encription done\n";
                
            }
            io.close();
            
        }   else    {
            
            io2<<"de "<<argv[2]<<" "<<argv[3];
            ofstream io1 (".progress.dat", ios::out);
            if(de(argv[2],argv[3])) {
                io1<<"Decription failed\n";
                io2<<" decription failed\n";
                
            }   else {
                io1<<"Decription done\n";
                io2<<" decription done\n";
                
            }
            io1.close();
        }
        io2.close();
    }
    return 0;
}