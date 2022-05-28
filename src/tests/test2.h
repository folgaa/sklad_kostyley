#ifndef LAB2_TEST2_H
#define LAB2_TEST2_H

#include "../LinkedList.h"

int test2(){
    puts("~~LinkedList_test~~");
    int items[5] = {1,2,3,4,5};
    LinkedList<int> a(items,5);
    cout << "first el: " << a.get_first() << endl;
    cout << "last el: " << a.get_last() << endl;
    for(int i = 0; i < a.get_length(); i++){
        cout << a.get(i);
    }
    cout << endl;

    LinkedList<int>* b = a.get_sub_list(1, 4);
    for(int i = 0; i < b->get_length(); i++){
        cout << b->get(i);
    }
    cout << endl;

    a.append(0);
    a.prepend(0);
    a.insert_at(0, 3);
    for(int i = 0; i < a.get_length(); i++){
        cout << a.get(i);
    }
    cout << endl;

    LinkedList<int>* c = a.concat(b);
    for(int i = 0; i < c->get_length(); i++){
        cout << c->get(i);
    }
    cout << endl;

    return 0;
}

#endif //LAB2_TEST2_H
