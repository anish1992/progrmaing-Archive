////////////////////////////////////////////////////////////////////////
//
// Title:               monte.cpp
// Problem:        program finds integral of e^x from 0 to 1
// Class:                  csc 340
// Date:                  2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include<math.h>
#include<time.h>
using namespace std;

double urn()    {
    return double(rand())/RAND_MAX;
}

int main()  {
    
    int i, n = 1000000, N=0;
    double x, y, integral, intTrap, intOrignal = (exp (1)-1), errorMonti,errorTrap ;
    
    for(i=0; i<n; i++)  {
        
        x=urn();y=exp (1)*urn();
        if(y <=  (exp(x))) N++;
    
    }// finding number of points under the curve
    
    integral = exp (1)*double(N)/double(n);//finding intagral
    intTrap = 0.5*(exp(0)+exp(1));// unsing trp
    errorMonti = 100.*(integral - intOrignal)/intOrignal;
    errorTrap = 100.*(intTrap - intOrignal)/intOrignal;
    cout << "\nIntegral of e^x from 0 to 1"
    << "\nwith monti carlo "<< integral
    <<"\nerror % in monti carlo "<< errorMonti
    <<"\nwith trapizodal "<< intTrap
    <<"\nerror % in trapizodal "<< errorTrap
    <<endl;
    
    
    return 0;
}
