#include <stdlib.h>
#include "float.h"
#include <stdio.h>

void* Sum_float(void* a1, void* a2){
    float *fa1 = (float*) a1,
          *fa2 = (float*) a2,
          *res = (float*) malloc(sizeof(float));
    *res = *fa1 + *fa2;
    return (void*)res;
}

void* Minus_float(void* a){
    float *b = (float*) malloc(sizeof(float));
    *b = -*((float *)a);
    return (void*)b;
}

void* Mult_float(void* a1, void* a2){
    float *fa1 = (float*)a1,
          *fa2 = (float*)a2,
          *res = (float*) malloc(sizeof(float));
    *res = *fa1 * *fa2;
    return (void*)res;
}

void Get_float(void* a){
    float b = *(float*)a;
    printf("%f ", b);
}


