// Adam Rhodes
// CSCI 3080
// OLA3 - 30804
// Matrix Inverse - This program will calculate the inverse of a matrix no larger than 10x10 
// 10/16/2020

#include <iostream>
#include <cmath>
using namespace std;
 

int main()
{
    int matSize;
    float  multiplier;
    float matA[10][10];
    cout << "input row size\n";
    cin >> matSize;
    cout << "input the matrix to invert\n";

    //Read in matrix
    for (int i = 1; i <= matSize; i++)
    {
        for (int j=1; j <= matSize; j++)
            {
                cin >> matA[i][j];
            }
    }

    //Appending identity matrix to original matrix
    for (int i = 1; i <= matSize; i++)
    {
        for (int j = 1; j <= matSize; j++)
            {
                if(i==j)
                    {
                        matA[i][j+matSize] = 1;    
                    }
                else
                {
                    matA[i][j+matSize] = 0;    
                }
            }
    }

    //Inverse Matrix calculation using modified Gaussian Elimination
    for (int i = 1; i <= matSize; i++)
    {    
        for (int j = 1; j <= matSize; j++)
        {
            if ( i != j)
            {
            multiplier = matA[j][i]/matA[i][i];
            for (int k = 1; k <= 2*matSize; k++)
                {
                    matA[j][k] = matA[j][k] -  multiplier * matA[i][k];    
                }
            }
        }
        
    }

    for (int i=1; i <= matSize; i++)
    {
        for (int j = matSize + 1; j <= 2*matSize; j++)
        {
            matA[i][j] =round( matA[i][j]/matA[i][i]);    
        }    
    }

    //Print Inverse Matrix
    for (int i = 1; i <= matSize; i++)
    {
        for (int j = matSize + 1; j <= 2*matSize; j++)
            {
                cout << matA[i][j] << "   ";    
            }
            cout << endl;
    }
    return 0;
}

