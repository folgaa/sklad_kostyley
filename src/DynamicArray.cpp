#include "DynamicArray.h"


template <typename T>
DynamicArray<T>::DynamicArray(T* Items1, int count){ //копирует элементы из переданного массива
    Items = new T[count];
    for(int i = 0; i < count; i++){
        Items[i] = Items1[i];//??
    }
    size = count;
    capacity = count;
}
template <typename T>
DynamicArray<T>:: DynamicArray(int size1){ //создаёт массив заданной длины
    Items = new T[size1];
    size = size1;
    capacity = 0;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &arr){ //конструктор копирования
    Items = new T[arr.size];
    for(int i = 0; i < size; i++){
        *(Items + sizeof(T) * i) = *(arr.Items + sizeof(T) * i);
    }
    size = arr.size;
    capacity = arr.capacity;
}

template <typename T>
T & DynamicArray<T>::get(int index){ //возвращает элемент по индексу
    if(index < 0 || index >= capacity){
        cout << "Index out of range!";
        exit(1);
    }
    if(capacity == 0){
        puts("Array is empty!");
    }
    return Items[index];
}

template <typename T>
int DynamicArray<T>::get_size(){ //возвращает размер массива(текущую заполненность)
    return capacity;
}

template <typename T>
void DynamicArray<T>::set(int index, T value){ //задаёт элемент по индексу
    if(index < 0 || index >= size){
        cout << "Index out of range!";
        return;
    }
    Items[index] = value;
        capacity++;
}

template <typename T>
void DynamicArray<T>::resize(int newsize){ //создаёт массив нового размера
    Items = (T*) realloc(Items, newsize * sizeof(T));
    size++;
}

/*template <class T> class DynamicArray{
public:

    int size;
    int capacity;
    T* Items;

    DynamicArray(T* Items1, int count){ //копирует элементы из переданного массива
        Items = new T[count];
        for(int i = 0; i < count; i++){
            *(Items + sizeof(T) * i) = *(Items1 + sizeof(T) * i);//??
        }
        size = count;
        capacity = count;
    }

    DynamicArray(int size1){ //создаёт массив заданной длины
        Items = new T[size1];
        size = size1;
        capacity = 0;
    }

    DynamicArray(const DynamicArray<T> &arr){ //конструктор копирования
        Items = new T[arr.size];
        for(int i = 0; i < size; i++){
            *(Items + sizeof(T) * i) = *(arr.Items + sizeof(T) * i);
        }
        size = arr.size;
        capacity = arr.capacity;
    }

    T Get(int index){ //возвращает элемент по индексу
        if(index < 0 || index >= capacity){
            cout << "Index out of range!";
            return;
        }
        if(capacity == 0){
            puts("Array is empty!");
        }
        return *(Items + sizeof(T) * index);
    }

    int GetSize(){ //возвращает размер массива
        return size;
    }

    void Set(int index, T value){ //задаёт элемент по индексу
        if(index < 0 || index >= capacity){
            cout << "Index out of range!";
            return;
        }
        Items + sizeof(T) * index = *value;
    }

    void Resize(int newsize){ //создаёт массив нового размера
        Items = (T*) realloc(Items, newsize * sizeof(T));
    }

};*/


