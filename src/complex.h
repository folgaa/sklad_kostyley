#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdlib.h>
#include <stdio.h>

typedef struct complex{
    int real;
    int im;
}complex;

void* Sum_complex(void* a1, void* a2);
void* Mult_complex(void* a1, void* a2);
void* Minus_complex(void* a);
void Get_complex(void* b);

#endif