/***********************************************************\
|  Program:  MonteCarlo.CPP                                 |
|  Problem:  Compute the integral of (x*x) from 3 to 6      |
|  Purpose:  Demo program for Monte Carlo methods           |
|  Author :  Jozo J. Dujmovic                               |
|  Date   :  5/15/1997                                      |
\***********************************************************/
#include <iostream>
#include <iomanip>
#include<math.h>
#include<time.h>
using namespace std;

double urn(void)
{
       return double(rand())/RAND_MAX;
}


int main()
{
   int i, n = 1000000, N=0;
 
   double x, y, integral, analytic = 63., error;
   
   for(i=0; i<n; i++)
   {  
      x=3.+3.*urn(); y=36.*urn(); 
      if(y <= (x*x)) N++;
   }

   integral = 3.*36.*double(N)/double(n);
   error = 100.*(integral - analytic)/analytic;
   cout << "\nIntegral of x*x from 3 to 6\n\n"
        << "Analytic result    = " << analytic
        << "\nMonte Carlo result = " << integral
        << "\nRelative error [%] = " << error
        << "\n\nERROR ANALYSIS\n\n"
        << " " << "N" << " " << "Integral"
        << " " << "Error [%]"
        << "\n----------------------------------\n";
   
   for(n=100; n<100000000; n*=100)
   {
     N=0; 
     for(i=0; i<n; i++)
     {  
        x=3.+3.*urn(); y=36.*urn(); 
        if(y <= (x*x)) N++;
     }
     integral = 3.*36.*double(N)/double(n);
     error = 100.*(integral - analytic)/analytic;
     cout << " " << n << " " << integral << " " << error << "\n";
   }
    
   cout << "\n\n";
   return 0;
}

