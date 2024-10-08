#include <math.h>
#include "../include/wavelet.h"

#define PI 3.141592653589

void ricker(float *arr, int Nt, double dt, int fmax)
{
    float t0 = 2 * PI / fmax;

    for (int i = 0; i < Nt; i++) 
    {
        float t = i * dt - t0;
        float arg = PI * fmax * t;
        float expression = (1.0 - 2.0 * arg * arg) * exp(-arg * arg); 
        arr[i] = expression;
    }
}

