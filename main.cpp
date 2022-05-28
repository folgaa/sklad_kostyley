#include <iostream>
#include "src/Sequence.h"
#include "src/ArraySequence.h"
#include "src/LinkedListSequence.h"
#include "src/ArraySequence.cpp"
#include "src/LinkedListSequence.cpp"
#include "src/tests/test1.h"
#include "src/tests/test2.h"
#include "src/tests/test3.h"
#include "src/tests/test4.h"


using namespace std;

int main() {
    test1(); //DynamicArray
    test2(); //LinkedList
    test3(); //ArraySequence
    test4(); //LinkedListSequence
    return 0;
}
