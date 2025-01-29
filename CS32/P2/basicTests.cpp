#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test(const Sequence& uls)
{
    assert(uls.size() == 2);
    ItemType x = 999;
    assert(uls.get(0, x)  &&  x == 20);
    assert(uls.get(1, x)  &&  x == 10);
}

int main()
{
    Sequence s;
    assert(s.insert(0, 10) == 0);
    assert(s.insert(0, 20) == 0);
    test(s);
    cout << "Passed all tests" << endl;
}