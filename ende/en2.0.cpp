//ende 2.0

#include<iostream>
#include<fstream>
#include<cstring>
#include<string.h>
#include<math.h>
using namespace std;

char *space(string file) {
    
    static char r[50];
    char *p = r;
    int i = 0;
    while (file[i] != '\0') {
        *p++ = file[i++];
        if (file[i] == ' ' && file[i-1] != (char)92)
            *p++ = (char)92;
    }
    return r;
}

void crypto (int size, string q, ostream& io, istream& is)  {
    
    char n;
    while (is.get(n)) {
        for (int i = 0; i<= size; i++) {
            srand(q[i]);
            n ^= rand();
        }
        io<<n;
    }
}

// rewriting the original file
void final(string file)    {
    
    char n;
    ifstream is (".out.dat", ios::in);
    ofstream io (file, ios::out);
    while (is.get(n)) io<<n;
    is.close();
    io.close();
    system("rm .out.dat");
}

// adding strings
char *AddStr(string a, string b, string c) {
    
    if (a[0] != '\0')AddStr("\0","","");
    int i=0,j=0,k=0;
    static char buffer[150];// pointer buffer
    char *p = buffer;
    while(a[i] != '\0')*p++ = a[i++];  // copy
    while(b[j] != '\0')*p++ = b[j++];  // append
    *p++ = ' ';
    while(c[k] != '\0')*p++ = c[k++];  // append
    return buffer;
}

// enctiption main
int en (string Wfile, string q)   {

    int size = 0, r = 0, i = 0;
    string file = Wfile;
    file += ".txt";
    
    ifstream ch (Wfile, ios::in);
    if(!ch) return 2;
    ch.close();
    
    system(AddStr("mv ",Wfile,file));
    
    while (q[size] != '\0') size++;
    
    ifstream is (file, ios::in);
    ofstream io (".out.dat", ios::out);
    if (is) {
        io<<(char)size;
        io<<' ';
        for (int i = 0; i<size; i++)
            io<<(char)(q[i]-'0');
        crypto(size, q, io, is);
    }   else    {
        cout<<"file not open\n";
        return 1;
    }
    is.close();
    io.close();
    
    final(file);
    system(AddStr("mv ", file, Wfile));
    return 0;
}

int de (string Wfile, string q)   {

    char a[50];// correct pass
    int i = 0, size = 0, r = 0;// size
    char n;// char
    string file = Wfile;
    file += ".txt";
    
    //file exists
    ifstream ch (Wfile, ios::in);
    if(!ch) return 2;
    ch.close();
    
    system(AddStr("mv ",Wfile,file));
    ifstream is (file, ios::in);
    
    //isEmpty
    if (is.eof())return 1;
    
    is.get(n);
    size = ((int)n);//num
    is.get(n);
    if(n != ' ')  {
        size = (size*10)+((int)n);
        is.get(n);
    }
    //get correct pass
    while (i < size) {
        is.get(n);
        a[i] = n;
        i++;
    }
    i = 0;
    
    //pass chack
    while (i < size) {
        if (i < size) {
            n = (char)(q[i]-'0');
            if(n != a[i]) {
                system(AddStr("mv ", file, Wfile));
                cout<<"bad pass\n";
                return 1;
            }
            i++;
        }
    }
    i = 0;
    
    ofstream io (".out.dat", ios::out);
    crypto(size, q, io, is);
    is.close();
    io.close();
    
    final(file);
    system(AddStr("mv ", file, Wfile));
    return 0;
}

int main(int argc, char* argv[])  {
    
    char ch = 'y';
    string file, Nfile, q;
    int r = 0;
    
    if (argc < 2)   {
        
        while (ch == 'y') {
            
            cout<<"to encrpt say 'y' \nto decropt say 'n'\n";
            cin>>ch;
            file = "";Nfile = "";q = "";
        
            if (ch == 'y') {
                
                cout<<"enter a file name :\n";
                cin>> file;
                while (file[r] != '\0') {
                    if (file[r] == ' ') Nfile[r] = '_';
                    else Nfile[r] = file[r];
                    r++;
                }
                r = 0;
                system(AddStr("mv ",space(file),Nfile));
                cout<<"enter an encription pass :\n";
                cin>> q;
                r = en(Nfile,q);
                if(r == 2) cout<<"file dose not exist\n";
                else if (r == 1) cout<<"encription failed\n";
                else cout<<"encription done\n";
                
            }   else    {
                
                cout<<"enter a file name :\n";
                cin>> file;
                while (file[r] != '\0') {
                    if (file[r] == ' ') Nfile[r] = '_';
                    else Nfile[r] = file[r];
                    r++;
                }
                r = 0;
                system(AddStr("mv ",space(file),Nfile));
                cout<<"enter a decription pass :\n";
                cin>> q;
                r = de(Nfile,q);
                if(r == 2) cout<<"file dose not exist\n";
                else if (r == 1) cout<<"decription failed\n";
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
            r = en(argv[2],argv[3]);
            if(r == 2) {
                io<<"file dose not exist\n";
                io2<<" file dose not exist\n";
            }
            else if( r == 1)     {
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
            r =de(argv[2],argv[3]);
            if(r == 2) {
                io1<<"file dose not exist\n";
                io2<<" file dose not exist\n";
            }
            else if(r == 1) {
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