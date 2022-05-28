#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H

#include <iostream>
#include "Sequence.h"

using namespace std;

template <class T> class LinkedList {
private:
    class Data{
    public:
        T data;
        Data* next{NULL};

        Data(T Item): data(Item){}
    };

    Data* head{NULL};
    Data* tail{NULL};
    int size{0};

public:

    LinkedList(T* Items, int count);

    LinkedList(); //создаёт пустой список

    LinkedList (const LinkedList <T> & list);//копирующий конструктор

    T & get_first();

    T & get_last();

    T & get(int index);

    LinkedList<T>* get_sub_list(int StartIndex, int EndIndex);

    int get_length();

    void append(T Item);

    void prepend(T Item);

    void insert_at(T Item, int Index);

    LinkedList<T>* concat(LinkedList<T> *list);
};
#endif //LAB2_LINKEDLIST_H
