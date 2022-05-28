#ifndef LAB2_DYNAMICARRAY_H
#define LAB2_DYNAMICARRAY_H

#include <iostream>
using namespace std;

template <class T> class DynamicArray{
public:

    int size;
    int capacity;
    T* Items;

    DynamicArray(T* Items1, int count);

    DynamicArray(int size1);

    DynamicArray(const DynamicArray<T> &arr);

    T & get(int index);

    int get_size();

    void set(int index, T value);

    void resize(int newsize);

};

#endif //LAB2_DYNAMICARRAY_H
