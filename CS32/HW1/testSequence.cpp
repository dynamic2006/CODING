#include "Sequence.h"
#include <iostream>
#include <cassert>
using namespace std;

void test(const Sequence& uls)
{
    assert(uls.size() == 2);
    ItemType x = 999;
    assert(uls.get(0, x) && x == 20);
    assert(uls.get(1, x) && x == 10);
}

int main()
{
    Sequence s;
    s.insert(0, 10);
    s.insert(0, 20);
    test(s);
    cout << "Passed all tests" << endl;
}

// #include "Sequence.h"
// #include <iostream>
// #include <cassert>
// using namespace std;

// int main()
// {
//     Sequence s;
//     assert(s.empty());
//     ItemType x = "arepa";
//     assert( !s.get(68, x)  &&  x == "arepa"); // x unchanged by get failure
//     assert(s.find("laobing") == -1);
//     assert(s.insert("laobing") == 0);
//     assert(s.size() == 1  &&  s.find("laobing") == 0);
//     assert(s.get(0, x)  &&  x == "laobing");
//     cout << "Passed all tests" << endl;
// }

// #include "Sequence.h"
// #include <iostream>
// #include <cassert>
// using namespace std;

// int main()
// {
//     Sequence s;
//     assert(s.empty());
//     ItemType x = 97;
//     assert( !s.get(68, x)  &&  x == 97); // x unchanged by get failure
//     assert(s.find(42) == -1);
//     assert(s.insert(42) == 0);
//     assert(s.size() == 1  &&  s.find(42) == 0);
//     assert(s.get(0, x)  &&  x == 42);
//     cout << "Passed all tests" << endl;
// }

// #include "Sequence.h"
// #include <iostream>
// #include <cassert>
// using namespace std;

// int main()
// {
//     Sequence s;
//     s.insert(0, "dosa");
//     s.insert(1, "pita");
//     s.insert(2, "");
//     s.insert(3, "matzo");
//     assert(s.find("") == 2);
//     s.remove("dosa");
//     assert(s.size() == 3  &&  s.find("pita") == 0  &&  s.find("") == 1  &&
//     s.find("matzo") == 2);
//     cout << "ALL TESTS PASSED" << endl;
// }

// #include "Sequence.h"
// #include <iostream>
// #include <cassert>
// using namespace std;

// int main()
// {
//     Sequence s;
//     assert(s.empty());
//     ItemType x = "arepa";
//     assert( !s.get(68, x)  &&  x == "arepa"); // x unchanged by get failure
//     assert(s.find("laobing") == -1);
//     assert(s.insert("laobing") == 0);
//     assert(s.size() == 1  &&  s.find("laobing") == 0);
//     assert(s.get(0, x)  &&  x == "laobing");
//     cout << "Passed all tests" << endl;
// }