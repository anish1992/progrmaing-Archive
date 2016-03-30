////////////////////////////////////////////////////////////////////////
//
// Title:                max2.cpp
// Problem:        matric multiplication
// Class:                  csc 340
// Date:                  2014
// Author:            Anish Kumaramagalam
//
///////////////////////////////////////////////////////////////////////

#include<iostream>
#include <iomanip>

using namespace std;

void showmat (int *(*M), int row, int col) {
    
    int i = 0,j = 0;
    cout << "\n\nMatrix:";
    for(; i<row; j = 0, i++)
        for(cout << '\n'; j<col; j++)
            cout <<"\t"<<*(*(M+i)+j);
    cout<<endl;
}

int** set (int *(*M), int row, int col) {
    
    int i, j = 0;
    M = new int*[row];
    for (i = 0; i < row; ++i)
        M[i] = new int[col];
    
    for(i = 0; i<row;j = 0, i++)
        for(; j<col; j++)
            *(*(M+i)+j) = rand()%100; // 0 <= rand() <= RAND_MAX;
    
    return M;
}

int** mult (int *(*A), int *(*B), int *(*C), int row, int col) {
    
    int i,j,k;
    C = new int*[row];
    for (i = 0; i < row; ++i)
        C[i] = new int[col];
    
    for(i=0; i<row; i++)
        for(j=0; j<row; j++)
            for(C[i][j]=k=0; k<row; k++)
                *(*(C+i)+j)+= *(*(A+i)+k) * *(*(B+k)+j);
    
    return C;
}

int main()  {
    
    const int row = 4, col = 4;
    int **A, **B, **C;
    
    A = set(A,row,col);
    showmat(A,row,col);
    B = set(B,row,col);
    showmat(B,row,col);
    C = mult(A,B,C,row,col);
    showmat(C,row,col);
    
   	return 0;
}
