#include <stdlib.h>
#include "complex.h"

void* Sum_complex(void* va1, void* va2){
    complex* sum = (complex*) malloc(sizeof(complex));
    complex* a1 = (complex*)va1;
    complex* a2 = (complex*)va2;
    sum->real = a1->real + a2->real;
    sum->im = a1->im + a2->im;
    return (void*)sum;
}

void* Minus_complex(void* va){
    complex* a = (complex*)va;
    a->real = -(a->real);
    a->im = -(a->im);
    return (void*)a;
}

void* Mult_complex(void* va1, void* va2){
    complex* a1 = (complex*)va1;
    complex* a2 = (complex*)va2;
    complex* mult = (complex*) malloc(sizeof(complex));
    mult->real = a1->real * a2->real - a1->im * a2->im;
    mult->im = a1->im * a2->real + a1->real * a2->im;
    return mult;
}

void Get_complex(void* b){
    complex* a = (complex*)b;
    if(a->im >= 0){
        printf("%d + %di ", a->real, a->im);
    }
    if(a->im < 0){
        printf("%d - %di ", a->real, a->im);
    }
}

