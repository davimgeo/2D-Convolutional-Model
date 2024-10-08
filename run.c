#include <stdio.h>
#include "include/bin_file.h"
#include "include/print.h"
#include "include/math_utils.h"

#define ROW 648
#define COLUMN 1150

float arr_vp[ROW][COLUMN];
float arr_rho[ROW][COLUMN]; 
float arr_result[ROW][COLUMN];

int main(int argc, char *argv[])
{
  const char* PATH_VP = "data/model_vp_2d.bin";
  const char* PATH_RHO = "data/model_rho_2d.bin";

  read2D(PATH_VP, (float*)arr_vp, sizeof(float), ROW, COLUMN);
  read2D(PATH_RHO, (float*)arr_rho, sizeof(float), ROW, COLUMN);

  elementWiseArrayMultiplication(ROW, COLUMN, arr_vp, arr_rho, arr_result);

  reflectivityMatrix(ROW, COLUMN, arr_result);

  write2D("data/test.bin", (float*)arr_result, sizeof(float), ROW, COLUMN);

  /*print2D((float*)arr_result, ROW, COLUMN);*/

  return 0;
}

