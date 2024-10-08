#include <stdio.h>

#define ROW 2 
#define COLUMN 3

static void convolution1D(float arr_1[], float arr_2[], int m, int n, float yk[])
{
  // Inicializa o resultado com zero
  for (int i = 0; i < m + n - 1; ++i) {
    yk[i] = 0.0f;  // Garante que o array é inicializado
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      yk[i + j] += arr_1[i] * arr_2[j];
    }
  }
}

void applyConvoInto2DArray(float input_signal[ROW][COLUMN], float filter[], 
                           int filter_size, float output[ROW][COLUMN])
{
  float temp[COLUMN];  
  for (int j = 0; j < COLUMN; ++j) 
  {
      for (int i = 0; i < ROW; ++i) 
      {
          temp[i] = input_signal[i][j];
      }
      
      float result[ROW + filter_size - 1]; 

      convolution1D(temp, filter, ROW, filter_size, result);

      for (int i = 0; i < ROW; ++i) 
      {
          output[i][j] = result[i];  
      }
  }
}

int main(int argc, char *argv[])
{
  float input_signal[ROW][COLUMN] = {
    {1.0f, 2.0f, 3.0f},
    {4.0f, 5.0f, 6.0f}
  };
  float filter[] = {4.0f, 3.0f, 2.0f, 1.0f};

  float result[ROW][COLUMN];

  applyConvoInto2DArray(input_signal, filter, 4, result);

  for (int i = 0; i < ROW; ++i) {
    for (int j = 0; j < COLUMN; ++j) {
      printf("%f ", result[i][j]);
    }
    printf("\n");
  }

  return 0;
}

