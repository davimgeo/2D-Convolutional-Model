#include <math.h>
#include "../include/wavelet.h"

#define PI 3.141592653589

void ricker(double *arr, int Nt, double dt, int fmax)
{
    double t0 = 2 * PI / fmax;

    for (int i = 0; i < Nt; i++) 
    {
        double t = i * dt - t0;
        double arg = PI * fmax * t;
        double expression = (1.0 - 2.0 * arg * arg) * exp(-arg * arg);  // Corrigido
        arr[i] = expression;
    }
}

