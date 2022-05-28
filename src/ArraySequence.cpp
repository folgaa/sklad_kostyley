#include "ArraySequence.h"

template <typename T>
ArraySequence<T>::ArraySequence(T* Items1, int count) { //копирует элементы из переданного массива
    items = new DynamicArray<T>(Items1, count);
}

template <typename T>
ArraySequence<T>::ArraySequence(): items(new DynamicArray<T>(0)){ //создаёт пустой список
}

template <typename T>
ArraySequence<T>:: ArraySequence(ArraySequence<T> & array){
    items = array.items;
} //копирующий конструктор

template <typename T>
ArraySequence<T>::ArraySequence(ArraySequence&& other) noexcept{
    items = other.items;
    other.items = NULL;
}

template <typename T>
T & ArraySequence<T>::get_first() const{ //возвращает первый элемент в списке
    return this->items->get(0);
}

template <typename T>
T & ArraySequence<T>::get_last() const{ //возвращает последний элемент
    return this->items->get(this->items->capacity - 1);
}

template <typename T>
T & ArraySequence<T>::get(int index) const{ //возвращает элемент по индексу
    return  this->items->get(index);
}

template<class T>
ArraySequence<T> *ArraySequence<T>::get_subsequence(int startIndex, int endIndex) const {
    T new_items[endIndex - startIndex + 1];
    for(int i = startIndex; i <= endIndex; i++){
        new_items[i - startIndex] = this->items->Items[i];
    }
    ArraySequence<T>* SubSeq = new ArraySequence<T>(new_items, endIndex - startIndex + 1);
    return SubSeq;
}

template<class T>
int ArraySequence<T>::get_length() const {
     return this->items->get_size();
}

template<class T>
void ArraySequence<T>::append(T item) const {
    this->insert_at(item, this->items->capacity);
}

template<class T>
void ArraySequence<T>::prepend(T item) const {
    this->insert_at(item, 0);
}

template<class T>
void ArraySequence<T>::insert_at(T item, int index) const {
    this->items->resize(this->get_length() + 1);
    for(int i = this->get_length() + 1; i >= index; i --){
        this->items->Items[i] = this->items->Items[i - 1];
    }
    this->items->set(index, item);
}

template <typename T>
ArraySequence<T>& ArraySequence<T>::operator = (ArraySequence && other) noexcept{
    if(this != &other){
        delete[] items;
        items = other.items;
        other.items = NULL;
    }
    return *this;
}

//template <typename T>



/*template <class T> class ArraySequence{
private:
    DynamicArray<T>* items;

public:
    ArraySequence(T* Items, int count){ //копирует элементы из переданного массива
        return DynamicArray<T>(Items,count);
    }

    ArraySequence(){ //создаёт пустой список
        return DynamicArray<T>();
    }

    ArraySequence (DynamicArray<T> & array){} //копирующий конструктор

    T GetFirst(){ //возвращает первый элемент в списке
        return this->items->Get(0);
    }

    T GetLast(){ //возвращает последний элемент
        return this->items->Get(DynamicArray<T> :: size - 1);
    }

    T Get(int index){ //возвращает элемент по индексу
        return  this->items->Get(index);
    }

};
*/