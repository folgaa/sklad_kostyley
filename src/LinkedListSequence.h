#ifndef LAB2_LINKEDLISTSEQUENCE_H
#define LAB2_LINKEDLISTSEQUENCE_H

#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Sequence.h"

template <class T> class LinkedListSequence: public Sequence<T>{
private:
    LinkedList<T>* items2;

public:
    LinkedListSequence(T* Items, int count); //копирует элементы из переданного массива

    LinkedListSequence(); //создаёт пустой список

    LinkedListSequence(LinkedListSequence<T> & array); //копирующий конструктор

    T & get_first() const override;

    T & get_last() const override;

    T  & get(int index) const override;

    LinkedListSequence<T> *get_subsequence(int startIndex, int endIndex) const override;

    int get_length() const override;

    void append(T item) const override;

    void prepend(T item) const override;

    void insert_at(T item, int index) const override;

    LinkedListSequence(LinkedListSequence&& other) noexcept;

    LinkedListSequence<T>& operator = (LinkedListSequence && other) noexcept;
};

#endif //LAB2_LINKEDLISTSEQUENCE_H
