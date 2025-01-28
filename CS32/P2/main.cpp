#include <iostream>
#include <cassert>
#include "Sequence.h"
using namespace std;

int main()
{
    //official testcases
    
    //tests where ItemType is type alias for std::string
    Sequence s1; ItemType def = "default";
    ItemType x = def;
    assert(s1.empty() && s1.size() == 0); //empty sequence
    assert(s1.insert(-1, "Bad Pos") == -1 && s1.size() == 0); //negative invalid pos
    assert(s1.insert(1, "Bad Pos") == -1 && s1.size() == 0); //invalid pos for insert
    assert(s1.insert("") == 0 && s1.size() == 1); //inserting empty string
    assert(s1.insert("ABC") == 1 && s1.size() == 2); //inserting a string
    assert(s1.insert("") == 0 && s1.insert("A") == 2); //check if inserts at lowest valid pos
    assert(s1.insert(1, "X") == 1 && s1.size() == 5); //check manual insert function

    //now s1 = {"", "X", "", "A", "ABC"}
    //test get for each valid pos
    for(int i=0; i<s1.size(); i++){
        s1.get(i,x);
        cout << "\""<< x  << "\"" << " ";
    }
    cout << endl;

    x = def;
    assert(!s1.get(-1, x) && !s1.get(s1.size(), x) && x == def);//test get for invalid pos
    assert(s1.set(1, "") && s1.get(1, x) && x == ""); //test set for empty string
    assert(!s1.set(-1, "Bad Pos") && !s1.set(s1.size(), "Bad Pos") && s1.size() == 5); //test set for invalid pos
    assert(!s1.erase(-1) && !s1.erase(s1.size())); //test erase for nonvalid pos

    x = def;
    assert(s1.erase(0) && s1.get(0,x) && x == ""); //test erase for empty string + first element
    assert(s1.erase(s1.size()-1) && s1.get(s1.size()-1, x) && x == "A"); //test erase for last element
    assert(s1.remove("") == 2 && s1.size() == 1); //test remove for empty string + multiple copies
    assert(s1.remove("A") == 1 && s1.empty() && s1.size() == 0); //test remove for normal string
    assert(s1.remove("") == 0 && s1.size() == 0); //test remove for empty list

    x = def;
    assert(!s1.get(0, x) && s1.set(0,x) && x == def);//test get/set for empty list

    s1.insert(0,"A"); s1.insert(1,"B"); s1.insert(2,"C"); s1.insert(3,"D");
    s1.insert(3,"A"); s1.insert(0, "C"); s1.insert(2,"D");
    //s1 = {C, A, D, B, C, A, D}
    assert(s1.insert("D") == 2 && s1.erase(2)); //test insert for multiple occurences already existing
    assert(s1.find("D") == 2 && s1.find("C") == 0); //testing find for multiple target occurences
    


    // assert(s.empty());
    // assert(s.size() == 0);
    
    // assert(s.insert(v) == 0); //5
    // assert(s.insert(2,10) == -1 && s.size() == 1); //5
    // assert(s.insert(s.size(), 7) == 1 && s.size() == 2); //5 7
    // assert(s.insert(-2) == 0 && s.size() == 3); // -2 5 7
    // assert(s.insert(6) == 2 && s.size() == 4); // -2 5 6 7
    // assert(s.insert(6) == 2 && s.size() == 5); // -2 5 6 6 7
    // assert(s.insert(6) == 2 && s.size() == 6); // -2 5 6 6 6 7
    // assert(!s.erase(-1) && s.size() == 6);
    // assert(s.erase(3) && s.size() == 5); // -2 5 6 6 7
    // assert(s.remove(6) == 2 && s.size() == 3); // -2 5 7

    // s.insert(6); s.insert(6); s.insert(6); // -2 5 6 6 6 7
    // assert(!s.get(s.size(), v) && v == 5);
    // assert(s.get(4, v) && v == 6 && s.size() == 6);
    // assert(s.set(4, 8) && s.get(4,v) && v==8);
    // assert(s.set(4,6) && s.get(4,v) && v==6);

    // for(int i=0; i<s.size(); i++){
    //     ItemType curVal = 0;
    //     s.get(i, curVal); cout << curVal << " ";
    // }

    cout << endl;
    cout << "ALL TESTS PASSED" << endl;
}