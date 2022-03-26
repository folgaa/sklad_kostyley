#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

vector* Create(void* x, void* y, void* z){
    vector* new_vector = malloc(sizeof(vector));
    new_vector->x = x;
    new_vector->y = y;
    new_vector->z = z;
    return new_vector;
}

void Delete_vector(vector* vect){
    free(vect);
}

