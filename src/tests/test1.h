#ifndef LAB2_TEST1_H
#define LAB2_TEST1_H

#include "../DynamicArray.h"

int test1(){
    puts("~~DynamicArray_test~~");
    int items[5] = {1, 2, 3, 4, 5};
    DynamicArray<int> a(items, 5);
    for(int i = 0; i < a.get_size(); i++){
        cout << a.get(i);
    }
    cout << endl;

    DynamicArray<int> b(items, 5);
    b.resize(6);
    b.set(5, 6);
    for(int i = 0; i < b.get_size(); i++){
        cout << b.get(i);
    }
    cout << endl;

    return 0;
}

#endif //LAB2_TEST1_H
