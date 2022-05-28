#include "LinkedListSequence.h"

template <typename T>
LinkedListSequence<T>::LinkedListSequence(T* Items, int count): items2(new LinkedList<T>(Items, count)){ //копирует элементы из переданного массива
}

template <typename T>
LinkedListSequence<T>::LinkedListSequence(): items2(new LinkedList<T>()) //создаёт пустой список
{}

template <typename T>
LinkedListSequence<T>::LinkedListSequence(LinkedListSequence<T> & array){
    items2 = array.items2;
} //копирующий конструктор

template <typename T>
T & LinkedListSequence<T>::get_first() const { //первый элемент
    return this->items2->get_first();
}

template <typename T>
T & LinkedListSequence<T>::get_last() const{ //последний элемент
    return this->items2->get_last();
}

template <typename T>
T  & LinkedListSequence<T>::get(int index) const{ //возвращает элемент по индексу
    return  this->items2->get(index);
}

template<class T>
LinkedListSequence<T> *LinkedListSequence<T>::get_subsequence(int startIndex, int endIndex) const {
    T new_items[endIndex - startIndex + 1];
    for(int i = 0; i < endIndex - startIndex + 1; i++){
        new_items[i] = this->items2->get(i + startIndex);
    }
    LinkedListSequence<T>* SubSeq = new LinkedListSequence<T>(new_items, endIndex - startIndex + 1);
    return SubSeq;
}

template<class T>
int LinkedListSequence<T>::get_length() const {
    return this->items2->get_length();
}

template<class T>
void LinkedListSequence<T>::append(T item) const {
    this->items2->append(item);
}

template<class T>
void LinkedListSequence<T>::prepend(T item) const {
    this->items2->prepend(item);
}

template<class T>
void LinkedListSequence<T>::insert_at(T item, int index) const {
    this->items2->insert_at(item, index);
}

template <typename T>
LinkedListSequence<T>::LinkedListSequence(LinkedListSequence&& other) noexcept{
    items2 = other.items2;
    other.items2 = NULL;
}

template <typename T>
LinkedListSequence<T>& LinkedListSequence<T>::operator = (LinkedListSequence && other) noexcept{
    if(this != &other){
        delete[] items2;
        items2 = other.items;
        other.items = NULL;
    }
    return *this;
}

