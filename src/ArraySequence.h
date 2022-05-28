#ifndef LAB2_ARRAYSEQUENCE_H
#define LAB2_ARRAYSEQUENCE_H

#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include "Sequence.h"

using namespace std;

template <class T> class ArraySequence: public Sequence<T>{
private:
    DynamicArray<T>* items;

public:
    ArraySequence(T* Items, int count);

    ArraySequence<T> *get_subsequence(int startIndex, int endIndex) const override;

    int get_length() const override;

    void append(T item) const override;

    void prepend(T item) const override;

    void insert_at(T item, int index) const override;

    ArraySequence();

    ArraySequence (ArraySequence<T> & array);

    ArraySequence(ArraySequence&& other) noexcept;

    T & get_first() const override;

    T & get_last() const override;

    T & get(int index) const override;

    ArraySequence& operator = (ArraySequence && other) noexcept;
};

#endif //LAB2_ARRAYSEQUENCE_H
