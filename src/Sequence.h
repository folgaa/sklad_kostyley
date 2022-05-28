#ifndef LAB2_SEQUENCE_H
#define LAB2_SEQUENCE_H

template <class T> class Sequence{
public:
    virtual T & get_first() const = 0;
    virtual T & get_last() const = 0;
    virtual T & get(int index) const = 0;
    virtual Sequence<T>* get_subsequence(int startIndex, int endIndex) const = 0;
    virtual int get_length() const = 0;
    virtual void append(T item) const = 0;
    virtual void prepend(T item) const = 0;
    virtual void insert_at(T item, int index) const = 0;
    T & operator [] (int i);
};

template <typename T>
T & Sequence<T>::operator[](int i) {
    if(i < 0 || i >= this->get_length()){
        puts("Index out of range!");
        exit(1);
    }
    return this->get(i);
}
#endif //LAB2_SEQUENCE_H
