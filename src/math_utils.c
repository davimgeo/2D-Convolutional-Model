#include "../include/math_utils.h"
#include "../include/print.h"
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

void convolution1D(float arr_1[], float arr_2[], int m, int n, float yk[])
{
  for (int i = 0; i < m + n - 1; ++i) {
    yk[i] = 0.0f; 
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      yk[i + j] += arr_1[i] * arr_2[j];
    }
  }
}

void initializeArray(int ROW, int COLUMN, float arr[ROW][COLUMN])
{
  for (int i = 0; i < ROW; ++i) 
  {
    for (int j = 0; j < COLUMN; ++j) 
    {
      arr[i][j] = 0.0f;
    }
  }
}
