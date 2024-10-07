#include "../include/matrix_multiplication.h"

void elementWiseArrayMultiplication(float* A, float* B, float* AB,int ROW, int COLUMN)
{
  for (int i = 0; i < ROW * COLUMN; ++i) 
  {
    AB[i] = A[i] * B[i];
  }
}


