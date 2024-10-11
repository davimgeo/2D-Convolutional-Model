#include <stdio.h>
#include "include/print.h"

#define ROW 2 
#define COLUMN 5

static void convolution1D(float arr_1[], float arr_2[], int m, int n, float yk[], float result_same[])
{
  for (int i = 0; i < m + n - 1; ++i) 
  {
    yk[i] = 0.0f; 
  }

  for (int i = 0; i < m; ++i) 
  {
    for (int j = 0; j < n; ++j)
    {
      yk[i + j] += arr_1[i] * arr_2[j];
    }
  }

  int start = (n - 1) / 2; 

  for (int i = 0; i < m; ++i)
  {
    result_same[i] = yk[start + i];
  }
}

int main(int argc, char *argv[])
{
  float input_signal_1D[] = {2.0f, 0.0f, 1.0f, 3.0f, 5.0f}; 
  float filter[] = {4.0f, 3.0f, 2.0f, 1.0f}; 

  int m = sizeof(input_signal_1D) / sizeof(input_signal_1D[0]); 
  int n = sizeof(filter) / sizeof(filter[0]); 

  float result_1D[m + n - 1]; 
  float result[COLUMN]; 
  
  convolution1D(input_signal_1D, filter, m, n, result_1D, result); 
  
  printf("Resultado da convolução completa:\n");
  print1D((float*)result_1D, m + n - 1); 

  printf("Resultado da convolução 'same':\n");
  print1D((float*)result, COLUMN); 
  
  return 0;
}

