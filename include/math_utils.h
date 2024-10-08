#ifndef MATRIX_MULTIPLICATION_H
#define MATRIX_MULTIPLICATION_H

void elementWiseArrayMultiplication(int ROW, int COLUMN, float A[ROW][COLUMN], float B[ROW][COLUMN], float AB[ROW][COLUMN]);

void reflectivityMatrix(int ROW, int COLUMN, float arr[ROW][COLUMN]);


void applyConvoInto2DArray(int ROW, int COLUMN, float input_signal[ROW][COLUMN], float filter[], 
                           int filter_size, float output[ROW][COLUMN]);

#endif // !MATRIX_MULTIPLICATION_H
