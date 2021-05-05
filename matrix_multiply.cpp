// Adam Rhodes
// CSCI 3080
// OLA3 - 30803
// Matrix Multiply - This program will add, subtract, multiply and 
// boolean multiply matrices. 
// 10/2/2020

#include <iostream>
using namespace std;

void add_matrices(int A[10][10], int B[10][10], int R, int C);
void subtract_matrices(int A[10][10], int B[10][10], int R, int C);
void multiply_matrices(int A[10][10], int B[10][10], int R, int C);
void bool_multiply(int A[10][10], int B[10][10], int R, int C);

int main()
{
    int matrix_A[10][10]; // 10x10 matrixA
    int matrix_B[10][10]; // 10x10 matrixB
    int matrix_C[10][10]; // 10x10 matrixC
    int rowsA, colsA, rowsB, colsB; //number of rows and columns for A and B
    char user_choice; // users choice of operation

    cout << "input the row size and col size of A\n";
    cin >> rowsA;
    cin >> colsA;
    cout << "input matrix A\n";

    for(int i=0; i<rowsA; i++) // Reads in matrix A
        {
            for(int j=0; j<colsA; j++)
               {
                    cin >> matrix_A[i][j];    
               }
        }
        
    cout << "input the row size and col size of B\n";
    cin >> rowsB;
    cin >> colsB;
    cout << "input matrix B\n";
    for (int i = 0; i < rowsB; i++){ // Reads in matrix B
        for(int j = 0; j < colsB; j++){
            cin >>  matrix_B[i][j];
            }
        }    

    cout << "Choose your operation: A for add\nS for subtract\nM for multiply\nB for boolean multiply\n";
    cin >> user_choice;

// Switch to activate matrix operation function based on user input
    switch (user_choice)
    {
        case 'A':
            if ((rowsA != rowsB) || (colsA != colsB))
            {
                cout << "invalid input. Matrices must be of equal size of addition\n";
                exit(0);    
            }
            else
            {
                add_matrices(matrix_A, matrix_B, rowsA, colsA);
            }
        break;
        
        case 'S':
            if ((rowsA != rowsB) || (colsA != colsB))
            {
                cout << "invalid input. Matrices must be of equal size for subtraction\n";    
            }
            else
            {
                subtract_matrices(matrix_A, matrix_B, rowsA, colsA);
            }
        break;

        case 'M':
            if (colsA != rowsB)
            {
                cout << "invalid input. Matrix A column must equal matrix B row to multiply matrices.\n";    
            }
            else
            {
                multiply_matrices(matrix_A, matrix_B, rowsA, colsA);
            }
        break;

        case 'B':
            if (colsA != rowsB)
            {
                cout << "invalid input. Matrix A column must equal matrix B row to multiply matrices.\n";    
            }
            else
            {
                bool_multiply(matrix_A, matrix_B, rowsA, colsA);
            }
        break;
        
        default:
            cout << "invalid choice selection. Please enter A, S, M or B.\n";   
    }
    return 0;
}

// Function that adds two matrices together
void add_matrices(int A[10][10], int B[10][10], int R, int C)
{
    cout << "The answer is: \n";
    int matrix_C[10][10];
    for(int i = 0; i < R; i++)
        {
        for(int j = 0; j < C; j++)
            {
                    matrix_C[i][j] = A[i][j] + B[i][j];
                    cout << matrix_C[i][j] << " ";
            }
        cout << endl;
        }
}

// Function that subtracts matrix B from matrix A
void subtract_matrices(int A[10][10], int B[10][10], int R, int C)
{   
    cout << "The answer is: \n";
    int matrix_C[10][10];
    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
            {
            matrix_C[i][j] = A[i][j] - B[i][j];
            cout << matrix_C[i][j] << " ";    
            }
        cout << endl;    
        }    
}

// Function that perform matrix multiplication
void multiply_matrices(int A[10][10], int B[10][10], int R, int C)
{
    cout << "The answer is: \n";
    int matrix_C[10][10];
    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
            {
            matrix_C[i][j] = 0;
            for (int k = 0; k < C; k++)
                {
                matrix_C[i][j] += A[i][k] * B[k][j];  
                }
            }
        }
    for (int i =0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            {
                cout << matrix_C[i][j] << " ";    
            }
            cout << endl;
    }
}

// Function performs boolean matrix multipication
void bool_multiply(int A[10][10], int B[10][10], int R, int C)
{
    cout << "The answer is: \n";
    int matrix_C[10][10];
    for (int i = 0; i < R; i++)
        {
        for (int j = 0; j < C; j++)
            {
            bool c_index = false;
            for (int k = 0; k < C; k++)
                {
                c_index |= A[i][k] * B[k][j];
                if (c_index)
                    break;  
                }
                matrix_C[i][j] = c_index;
            }
        }
    for (int i =0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            {
                cout << matrix_C[i][j] << " ";    
            }
            cout << endl;
    }
}

