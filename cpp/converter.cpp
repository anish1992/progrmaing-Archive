////////////////////////////////////////////////////////////////////////
//(annace)002/store
// Title:                converter.cpp
// Problem:   store data into a file then search for it using filters
// Class:                  -
// Date:                  2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>

using namespace std;

string out(string a)   {
    string re = "syatem.out.println";
    
    return re;
}

string in(string a)   {
    string re = "";
    
    return re;
}

// library conversion
string lib(string a)    {
    int i = 8;
    sting temp == "";
    //if()
    return "// lib "+a ;
}// end of library import

// comparing strings " " == " "
int comp(string a,string b) {
    int i = 0, j = 1;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            j--;
            break;
        }
        else if (a[i] == '\0' && b[i] != '\0'||
                 a[i] != '\0' && b[i] == '\0')  {
            j--;
            break;
        }
        i++;
    }
    
    return j;
} // end of comparing string


string proFunc(string a)    {
    
    string new1 = "";
    int i = -1;
    ofstream txt1 ("file.dat", ios::out);
    while (a[i] != '\0')    {
        
        
        if (comp(new1,"int"))    {
            
            txt1<<"int "<< new1 <<endl;
        }
        
        if (comp(new1,"string"))    {
            
            txt1<<"string "<< new1 <<endl;
        }
        if (comp(new1,"cout<<"))    {
            
            return out(a);
        }
        if (comp(new1,"cin>>"))    {
            
            return in(a);
        } else {
            if (a[i] != ' ')new1 += a[i];
        }


        
        
    }
    txt1.close();
    
    return new1;//coppy full line;
}

string dot (int i, string a)   {
    
    string b = "";
    while (a[i] != '\0')    {
        b += a[i];
        if(a[i] != '.') {
            b+=".java";
        }
        i++;
    }
    
    return b;
}

/*comments*/
int longcom(int com, string a)  {
    
    int i =0;
    while (a[i] != '\0' )    {
        
        if (a[i] == '/' && a[i+1] == '/*') {
            return 0;
        }
        i++;
    }
    
    return 1;
}
/* end of comments*/

void write (string a, string file)   {
    
    ofstream txt2 (file+".java", ios::out | ios::app);
    txt2 << a <<'\n';
    txt2.close();
}


int main()  {

    int com =0, incl =0, scanner =1;
    string file = "", data = "", newf = "";
    cout<<"Enter a file name\n";
    cin>> file;
    newf = dot(0,file);
    
    ifstream txt (file, ios::in);
    while (getline(txt, data)) {
        
        if (data[0] == '#')        {
            write(lib(data),newf);
            incl++;
        }
        else if (data[0] == '/' && data[1] == '/') write(data,newf); //comments
        else if (comp("using namespace std;", data)) continue;
        else if (comp("int main()  {", data))    { // main
            
            write("class "+newf+"\t{\n",newf);
            write("\tpublic static void main(String[] args)\t{\n",newf);
            if (scanner)    {
                write("Scanner input = new Scanner(System.in)",newf);
            }
        }
        else if ((data[0] == '*' && data[1] == '/') || com)   { /* comments */
            
            com = longcom(com, data);
            write(data,newf);
        }
        else {
            write(proFunc(),newf);
        }
        
    }
    txt.close();

   	return 0;
}
