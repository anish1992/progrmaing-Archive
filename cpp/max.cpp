////////////////////////////////////////////////////////////////////////
//
// Title:                max.cpp
// Problem:        matric multiplication
// Class:                 csc 340
// Date:                  2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include <iomanip>

using namespace std;

typedef int matrix[4][4];

void set (int M[][4], int row, int col) {
    
    int i = 0, j = 0;
    for(; i<row; j = 0, i++)
        for(; j<col; j++)
            M[i][j]= rand()%100; // 0 <= rand() <= RAND_MAX;
        
}

void showmat (int M[][4], int row, int col) {
    
    int i = 0,j = 0;
    cout << "\n\nMatrix:";
    for(; i<row; j = 0, i++)
        for(cout << '\n'; j<col; j++)
            cout <<"\t"<<M[i][j];
    cout<<endl;
}

void mult (int A[][4], int B[][4], int C[][4], int row, int col) {
    
    int i,j,k;
    for(i=0; i<row; i++)
        for(j=0; j<row; j++)
            for(C[i][j]=k=0; k<row; k++)
                C[i][j] += A[i][k]*B[k][j];
    
}

int main()  {
    
    const int row = 4, col = 4;
    int A[row][col], B[row][col], C[row][col];
    set(A,row,col);
    showmat(A,row,col);
    set(B,row,col);
    showmat(B,row,col);
    mult(A,B,C,row,col);
    showmat(C,row,col);
    
   	return 0;
}
