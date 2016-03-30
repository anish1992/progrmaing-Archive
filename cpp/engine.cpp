////////////////////////////////////////////////////////////////////////
//
// Title:                engine.cpp
// Problem:    enigine that runs the quadratic equation
// Class:                  csc 340
// Date:                  2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
using namespace std;

int main(int argc, char* argv[])  {
    
    double a, b, c, x1, x2;
    string file;
    
    if (argc > 4) { // numbers and file
        
        // geting values
        a =atof(argv[1]);
        b =atof(argv[2]);
        c =atof(argv[3]);
        file =argv[4];
        
        // calculation and writing to file
        ofstream os(file, ios::out);
        if (a == 0 && b == 0)
            os<<"not a valid function\n";
        if (a == 0 && b != 0)
            os<<"X1 is "<< -(c/b) <<"\n";
        if ((b*b-4*a*c)>0)  {
            x2 = (b*b)-(4*a*c);
            x1 = -b+sqrt(x2);
            os<<"X1 is "<< x1 <<" and X2 is "<< x2 <<"\n";
        } else  {
            os<<"not a real root\n";
        }
        os.close();

    }
    else if (argc > 2) { // only numberd
        
        // geting values
        a =atof(argv[1]);
        b =atof(argv[2]);
        c =atof(argv[3]);
        
        // calculating and printing
        if (a == 0 && b == 0)
            cout<<"not a valid function\n";
        if (a == 0 && b != 0)
            cout<<"X1 is "<< -(c/b) <<endl;
        if ((b*b-4*a*c)>0)  {
            x2 = (b*b)-(4*a*c);
            x1 = -b+sqrt(x2);
            cout<<"X1 is "<< x1 <<" and X2 is "<< x2 <<endl;
        } else  {
            cout<<"not a real root\n";
        }
        
    }   else    { // no argument add
        
        // geting values
        cout<<"entre a b c  :\n";
        cin>> a >> b >> c;
        
        // calculating and printing
        if (a == 0 && b == 0)
            cout<<"not a valid function\n";
        if (a == 0 && b != 0)
            cout<<"X1 is "<< -(c/b) <<endl;
        if ((b*b-4*a*c)>0)  {
            x2 = (b*b)-(4*a*c);
            x1 = -b+sqrt(x2);
            cout<<"X1 is "<< x1 <<" and X2 is "<< x2 <<endl;
        } else  {
            cout<<"not a real root\n";
        }

    }
    
   	return 0;
}
