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

      if (denominator != 0) 
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

void convolution1D(float arr_1[], float arr_2[], int m, int n, float result_same[])
{
    float yk[m + n - 1];

    // Initialize yk to zero
    for (int i = 0; i < m + n - 1; ++i) 
    {
        yk[i] = 0.0f;
    }

    // Perform convolution
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j)
        {
            yk[i + j] += arr_1[i] * arr_2[j];
        }
    }

    int start = (n - 1) / 2; 

    // Copy results to result_same
    for (int i = 0; i < m; ++i)
    {
        result_same[i] = yk[start + i]; // Ensure we are accessing within bounds
    }
}

void convolution2D(int ROW, int COLUMN, float arr_1[ROW][COLUMN], float arr_2[], int n, float result[ROW][COLUMN])
{
    float temp_row[COLUMN]; 
    float result_same[COLUMN]; 

    // Initialize temp_row and result_same to zero
    initializeArray1D(COLUMN, temp_row);
    initializeArray1D(COLUMN, result_same);

    for (int i = 0; i < ROW; ++i) 
    {
        // Copy the current row into temp_row
        for (int j = 0; j < COLUMN; ++j)
        {
            temp_row[j] = arr_1[i][j]; 
        }

        // Perform 1D convolution on the row
        convolution1D(temp_row, arr_2, COLUMN, n, result_same); 

        // Write the convolved row back to result
        for (int j = 0; j < COLUMN; ++j)
        {
            result[i][j] = result_same[j];
        }
    }
}

void initializeArray1D(int size, float arr[])
{
  for (int i = 0; i < size; ++i) 
  {
    arr[i] = 0.0f;
  }
}

void initializeArray2D(int ROW, int COLUMN, float arr[ROW][COLUMN])
{
  for (int i = 0; i < ROW; ++i) 
  {
    for (int j = 0; j < COLUMN; ++j) 
    {
      arr[i][j] = 0.0f;
    }
  }
}
