#include "../include/math_utils.h"
#include <stdio.h>

void elementWiseArrayMultiplication(int ROW, int COLUMN, float A[ROW][COLUMN], float B[ROW][COLUMN],float AB[ROW][COLUMN])
{
  for (int i = 0; i < ROW; ++i) 
  {
    for (int j = 0; j < COLUMN; ++j) 
    {
      AB[i][j] = A[i][j] * B[i][j];
    }
  }
}

// R = (Z2 - Z1) / (Z2 + Z1)
void reflectivityMatrix(int ROW, int COLUMN, float arr[ROW][COLUMN])
{
  for (int i = 0; i < ROW; ++i) 
  {
    for (int j = 0; j < COLUMN - 1; ++j) 
    {
      float numerator = arr[i][j + 1] - arr[i][j];
      float denominator = arr[i][j + 1] + arr[i][j];

      if (!(denominator)) 
      {
        arr[i][j] = numerator / denominator;
      }
      else 
      {
        arr[i][j] = 0.0f; 
      }
    }

    arr[i][COLUMN - 1] = 0.0f;
  }
}

