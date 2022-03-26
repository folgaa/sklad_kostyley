#include <stdio.h>
#include <stdlib.h>
#include "info.h"

info* Create_i(
        void (*get)(void*),
        void* (*sum)(void*, void*),
        void* (*mult)(void*, void*),
        void* (*minus)(void*)
        )
{
    struct info* inform = malloc(sizeof(info));
    inform->get = get;
    inform->sum = sum;
    inform->minus = minus;
    inform->mult = mult;
    return inform;
}

void Delete_i(info* inform){
    free(inform);
}



