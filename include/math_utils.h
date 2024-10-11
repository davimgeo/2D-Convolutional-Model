#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

void elementWiseArrayMultiplication(int ROW, int COLUMN, float A[ROW][COLUMN], float B[ROW][COLUMN], float AB[ROW][COLUMN]);

void reflectivityMatrix(int ROW, int COLUMN, float arr[ROW][COLUMN]);

void convolution1D(float arr_1[], float arr_2[], int m, int n, float result[]);

void convolution2D(int ROW, int COLUMN, float arr_1[ROW][COLUMN], float arr_2[], int n, float result[ROW][COLUMN]);

void initializeArray1D(int size, float arr[]);

void initializeArray2D(int ROW, int COLUMN, float arr[ROW][COLUMN]);

#endif // !MATRIX_MULTIPLICATION_H
