#include "TurnoutList.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    TurnoutList t;

    ItemType v = 10;
    // t.add(10);
    // t.add(-1);
    // t.add(0);
    // t.add(5);
    // t.add(21);
    // t.add(1800);
    assert(!t.remove(50));
    assert(!t.remove(-1));
    assert(!t.remove(0));
    cout << t.maximum() << " " << t.minimum() << endl;
    // for(int i=0; i<DEFAULT_MAX_ITEMS; i++) t.add(v);
    // cout << t.size() << endl;

    // assert(!t.add(v));


}