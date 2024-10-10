#include <stdio.h>
#include "include/bin_file.h"
#include "include/print.h"
#include "include/math_utils.h"
#include "include/wavelet.h"

#define ROW 648
#define COLUMN 1150

#define NT 501
#define DT 0.001
#define FMAX 25

float arr_vp[ROW][COLUMN];
float arr_rho[ROW][COLUMN]; 
float arr_result[ROW][COLUMN];
float convolved_arr[ROW][COLUMN];

int main(int argc, char *argv[])
{
  const char* PATH_VP = "data/model_vp_2d.bin";
  const char* PATH_RHO = "data/model_rho_2d.bin";

  read2D(PATH_VP, (float*)arr_vp, sizeof(float), ROW, COLUMN);
  read2D(PATH_RHO, (float*)arr_rho, sizeof(float), ROW, COLUMN);

  elementWiseArrayMultiplication(ROW, COLUMN, arr_vp, arr_rho, arr_result);
  reflectivityMatrix(ROW, COLUMN, arr_result);

  float ricker_arr[NT];

  ricker((float*)ricker_arr, NT, DT, FMAX);

  /*write2D("data/conv.bin", (float*)convolved_arr, sizeof(float), ROW, COLUMN);*/

  return 0;
}

