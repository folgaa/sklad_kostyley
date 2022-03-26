#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector{
    void* x;
    void* y;
    void* z;
} vector;

vector* Create(void* x, void* y, void* z);

void Delete_vector(vector* vect);

#endif