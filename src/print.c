#include <stdio.h>
#include <stdlib.h>

void print2D(float* arr, int ROW, int COLUMN)
{
    for (int i = 0; i < ROW; ++i) 
    {
        for (int j = 0; j < COLUMN; ++j) 
        {
            printf("%f ", arr[i * COLUMN + j]);
        }
        printf("\n");  
    }
}

void print1D(float* arr, int size)
{
    for (int i = 0; i < size; ++i) 
    {
        printf("%f ", arr[i]);
    }
    printf("\n"); 
}

