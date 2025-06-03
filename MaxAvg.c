#include "MaxAvg.h"
#include <stdio.h>
#include <math.h> 

double maxArray(double a[], int size) {
    if (size == 0) return NAN; 

    double max = a[0]; 
    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
    
}



double avgArray(double a[], int size) {
    if (size == 0) return NAN; 

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += a[i];
    }
    return sum / size;
}