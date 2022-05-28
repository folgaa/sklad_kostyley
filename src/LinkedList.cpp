#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList(T* Items, int count): size(count){ //копирует элементы из переданного массива
    Data* tmp = NULL;
    Data* prev = new Data(Items[0]);
    this->head = prev;

    for(int i = 1; i < count; i++){
        tmp = new Data(Items[i]);
        prev->next = tmp;
        prev = tmp;
    }
    this->tail = tmp;
}

template <typename T>
LinkedList<T>::LinkedList(){} //создаёт пустой список

template <typename T>
LinkedList<T>::LinkedList(const LinkedList <T> & list){
    head = list.head;
    tail = list.tail;
    size = list.size;
}//копирующий конструктор

template <typename T>
T & LinkedList<T>::get_first() { //первый элемент
    if(this == NULL){
        puts("Linked list is empty!");
        exit(2);
    }
    return this->head->data;
}

template <typename T>
T & LinkedList<T>::get_last() { //последний элемент
    if(this == NULL){
        puts("Linked list is empty!");
        exit(2);
    }
    return this->tail->data;
}

template <typename T>
T & LinkedList<T>::get(int index) { //элемент по индексу
    if(index < 0 || index >= size){
        puts("Index out of range!");
        exit(1);
    }
    Data* tmp = this->head;
    for(int i = 0; i < index; i++){
        tmp = tmp->next;
    }
    return tmp->data;
}

template <typename T>
LinkedList<T>* LinkedList<T>::get_sub_list(int StartIndex, int EndIndex) { //список из заданных элементов
    if (StartIndex < 0 || StartIndex >= size || EndIndex < 0 || EndIndex >= size){
        puts("Index out of range!");
        return 0;
    }
    T Items[EndIndex - StartIndex + 1];
    for(int i = StartIndex; i <= EndIndex; i++){
        Items[i - StartIndex] = get(i);
    }
    LinkedList<T>* SubList = new LinkedList<T>(Items, EndIndex - StartIndex + 1);
    return SubList;
}

template <typename T>
int LinkedList<T>::get_length() { //размер
    return size;
}

template <typename T>
void LinkedList<T>::append(T Item) { //вставка в конец
    Data* tmp = new Data(Item);
    this->tail->next = tmp;
    this->tail = tmp;
    size++;
}

template <typename T>
void LinkedList<T>::prepend(T Item) { //вставка в начало
    Data* tmp = new Data(Item);
    tmp->next = this->head;
    this->head = tmp;
    size++;
}

template <typename T>
void LinkedList<T>::insert_at(T Item, int Index) { //вставка по индексу
    if(Index < 0 || Index >= size){
        puts("Index out of range!");
        return;
    }
    if(Index == 0){
        prepend(Item);
    }
    if(Index == size - 1){
        append(Item);
    }
    Data* NewEl = new Data(Item);
    Data* ptr = this->head;
    Data* prev = ptr;
    for(int i = 0; i < Index; i++){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NewEl;
    NewEl->next = ptr;
    size++;
}

template <typename T>
LinkedList<T>* LinkedList<T>::concat(LinkedList<T> *list) { //сцепляет списки
    this->tail->next = list->head;
    this->tail = list->tail;
    size = this->size + list->size;
    return this;
}
