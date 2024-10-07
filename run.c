#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/bin_file.h"
#include "include/wavelet.h"
#include "include/print.h"
#include "include/matrix_multiplication.h"

#define ROW 648
#define COLUMN 1150

#define NT 501
#define DT 0.001
#define FMAX 25

int main(int argc, char *argv[])
{
  const char* PATH_VP = "data/model_vp_2d.bin";
  const char* PATH_RHO = "data/model_rho_2d.bin";

  float* arr_vp = (float*)malloc(ROW * COLUMN * sizeof(float));
  float* arr_rho = (float*)malloc(ROW * COLUMN * sizeof(float));
  float* arr_result = (float*)malloc(ROW * COLUMN * sizeof(float));

  read2D(PATH_VP, arr_vp, sizeof(float), ROW, COLUMN);
  read2D(PATH_RHO, arr_rho, sizeof(float), ROW, COLUMN);

  elementWiseArrayMultiplication(arr_vp, arr_rho, arr_result, ROW, COLUMN);

  free(arr_vp);
  free(arr_rho);
  free(arr_result);

  return 0;
}

