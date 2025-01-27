#include <iostream>
#include <cassert>
#include "Sequence.h"
using namespace std;

int main()
{
    ItemType v = 5;
    Sequence s;
    assert(s.empty());
    assert(s.size() == 0);
    
    assert(s.insert(v) == 0);
    cout << "ALL TESTS PASSED" << endl;
}