#include <stdio.h>
#include "vector.h"
typedef struct info{
    void (*get)(void*);
    void* (*sum)(void*, void*);
    void* (*mult)(void*, void*);
    void* (*minus)(void*);
}info;


info* Create_i(
        void (*get)(void*),
        void* (*sum)(void*, void*),
        void* (*mult)(void*, void*),
        void* (*minus)(void*));

void Delete_i(info* inform);