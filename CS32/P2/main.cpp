#include <iostream>
#include <cassert>
#include "Sequence.h"
using namespace std;

int main()
{
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
    cout << ":FIN" << endl;

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
    assert(!s1.get(0, x) && !s1.set(0,x) && x == def);//test get/set for empty list

    s1.insert(0,"A"); s1.insert(1,"B"); s1.insert(2,"C"); s1.insert(3,"D");
    s1.insert(3,"A"); s1.insert(0, "C"); s1.insert(2,"D");
    //s1 = {C, A, D, B, C, A, D}
    assert(s1.insert("D") == 2 && s1.erase(2)); //test insert for multiple occurences already existing
    assert(s1.find("D") == 2 && s1.find("C") == 0); //testing find for multiple target occurences
    assert(s1.find("") == -1 && s1.size() == 7); //test find for target not in list + empty string
    assert(s1.find("E") == -1 && s1.size() == 7); //test find for target greater than all list items
    
    Sequence s2;
    Sequence s3;

    s2.swap(s2); s3.swap(s3);
    assert(s2.size() == 0 && s3.size() == 0); //test swapping empty list with itself
    s2.swap(s3);
    assert(s2.size() == 0 && s3.size() == 0); //test swapping two empty lists
    s2.swap(s1);
    assert(s1.size() == 0 && s2.size() == 7); //test swapping empty and nonempty lists
    assert(s2.insert("D") == 2 && s1.insert("E") == 0 && s1.insert("E") == 0); //test insert after swap
    assert(s3.find("") == -1 && s3.find("A") == -1 && s3.find("E") == -1); //test find after swap + empty list
    s1.swap(s3);
    assert(s3.find("") == -1 && s3.find("A") == -1 && s3.find("E") == 0); //test find after swap + nonempty list
    assert(s1.size() == 0 && s3.size() == 2); //test swapping lists that have already been swapped >=1 times
    s1.swap(s2); s3.swap(s2);
    assert(s1.size() == 8 && s2.size() == 2 && s3.size() == 0); //test "unswapping" lists
    s1.swap(s1); s2.swap(s2); s3.swap(s3);
    assert(s1.size() == 8 && s2.size() == 2 && s3.size() == 0); //test swap list with itself + empty list
    s3.swap(s1);
    
    assert(s3.erase(2) && s3.get(2,x) && x == "D" && s3.get(1,x) && x == "A" && s3.size() == 7); //test erase after swap
    assert(s2.remove("A") == 0 && s2.remove("") == 0 && s2.remove("E") == 2 && s2.size() == 0); //test remove after swap
    assert(s2.insert("X") == 0 && s2.insert("X") == 0 && s2.insert("X") == 0); //test insert in empty list after swap
    assert(s2.set(0, "A") && s2.set(1, "D") && s2.set(2, "C") && !s2.set(3, "X")); //test set after swap
    s1.swap(s3);

    //s1 = {C, A, D, B, C, A, D}
    //s2 = {A, D, C}
    //s3 = {}
    //test get for each valid pos after swap
    for(int i=0; i<s1.size(); i++){
        s1.get(i,x);
        cout << "\""<< x  << "\"" << " ";
    }
    cout << ":FIN" << endl;

    for(int i=0; i<s2.size(); i++){
        s2.get(i,x);
        cout << "\""<< x  << "\"" << " ";
    }
    cout << ":FIN" << endl;

    for(int i=0; i<s3.size(); i++){
        s3.get(i,x);
        cout << "\""<< x  << "\"" << " ";
    }
    cout << ":FIN" << endl;

    Sequence sc(sc); //tests for copy constructor with itself as arg
    x = def;
    assert(sc.empty() && sc.size() == 0); //empty sequence
    assert(sc.insert(-1, "Bad Pos") == -1 && sc.size() == 0); //negative invalid pos
    assert(sc.insert(1, "Bad Pos") == -1 && sc.size() == 0); //invalid pos for insert
    assert(sc.insert("") == 0 && sc.size() == 1); //inserting empty string
    assert(sc.insert("ABC") == 1 && sc.size() == 2); //inserting a string
    assert(sc.insert("") == 0 && sc.insert("A") == 2); //check if inserts at lowest valid pos
    assert(sc.insert(1, "X") == 1 && sc.size() == 5); //check manual insert function

    //now sc = {"", "X", "", "A", "ABC"}
    //test get for each valid pos
    for(int i=0; i<s1.size(); i++){
        s1.get(i,x);
        cout << "\""<< x  << "\"" << " ";
    }
    cout << ":FIN" << endl;

    assert(sc.erase(3) && sc.size() == 4); //erase after cpy constructor
    assert(sc.remove("") == 2 && sc.size() == 2); //remove afer cpy constructor
    sc.get(0,x);
    sc.remove(x);
    assert(sc.size() == 1); //test get, remove operations
    assert(sc.erase(0) && sc.empty()); //test erase to 0 elements, test empty
    x = def;
    
    //test assignment operator
    //test assignment
    Sequence sa;

    sa = sa;
    assert(sa.size() == 0); //test assignment to itself

    sa = sc;
    assert(sa.size() == 0); //test assignment to empty Sequence
    assert(sa.insert("A") == 0 && sa.insert("B") == 1 && sa.insert("") == 0); //test insert after assignment
    assert(sa.size() == 3 && sc.size() == 0); //test that assignment deep copies correctly (sc size shouldnt change)
    
    sa = s1;
    assert(sa.size() == s1.size()); //test assignment to nonempty Sequence
    assert(sa.insert("A") == 0 && sa.insert("B") == 1 && sa.insert("") == 0); //test insert after assignment
    assert(sa.size() == 10 && s1.size() == 7); //test that assignment deep copies correctly (s1 size shouldnt change)

    sa = sa;
    assert(sa.size() == 10 && s1.size() == 7); //test assignment to itself (shouldnt affect previous assigned list)

    sa = s2;
    assert(sa.size() == s2.size()); //test assignment to smaller than current size Sequence
    assert(sa.insert("A") == 0 && sa.insert("B") == 2 && sa.insert("") == 0); //test insert after assignment
    assert(sa.size() == 6 && s2.size() == 3); //test that assignment deep copies correctly (s2 size shouldnt change)

    sa = s3;
    assert(sa.size() == s3.size()); //test assignment to different empty Sequence
    assert(sa.insert("A") == 0 && sa.insert("B") == 1 && sa.insert("") == 0); //test insert after assignment
    assert(sa.size() == 3 && s3.size() == 0); //test that assignment deep copies correctly (s3 size shouldnt change)

    //more copy constructor tests
    sa = s1; //test copying from assignment operated list (also switch s1 out for s2 and s3)
    Sequence sk(sa); //test copy constructor from other sequence
    //tests for regular copy constructor function
    assert(sk.size() == sa.size());
    sa.insert("A"); sa.insert("B"); sa.insert("");
    assert(sk.size() == sa.size() - 3); //test inserts into sa (shouldn't change sk)
    sk.insert("A"); sk.insert("B"); sk.insert("");//inserts into sk (shouldn't change sa)
    assert(sk.size() == sa.size()); //test inserts into sk (shouldn't change sa)

    //SEQUENCE ALGORITHM TESTS
    
    //s1 = {C, A, D, B, C, A, D}
    //s2 = {A, D, C}
    //s3 = {}

    //subsequence tests
    assert(subsequence(s1, s2) == -1); //test where s2 is a subset, but not subseq
    assert(subsequence(s1, s1) == 0 && subsequence(s2, s2) == 0); //test seq is subseq of itself
    assert(subsequence(s3, s3) == -1 && subsequence(s3, s2) == -1 && subsequence(s2, s3) == -1); //test for empty seq as arg
    
    Sequence s4; s4.insert(0, "C"); s4.insert(1, "A"); s4.insert("D");
    assert(subsequence(s1, s4) == 0); //test subseq where multiple occurences exist (should give earliest)
    s4.insert(0, "B");
    assert(subsequence(s1, s4) == 3); //test subseq at very end of seq
    s4.insert("E");
    assert(subsequence(s1, s4) == -1); //test subseq that extends past end of og seq
    s4 = s1;
    s4.insert("X");
    assert(subsequence(s1, s4) == -1); //test subseq that is longer than og seq

    //zipper tests

    Sequence a;
    Sequence b;
    a.insert(0,"s"); a.insert(0, "o"); a.insert(0, "c");
    b.insert(0, "r"); b.insert(0, "e"); b.insert(0, "t"); b.insert(0, "i"); b.insert(0,"l");
    Sequence ta = a;
    Sequence tb = b;
    Sequence res;
    zipper(ta,tb,ta); //test for res and ta are references to same sequence (aliasing test)
    for(int i=0; i<ta.size(); i++){
        ta.get(i,x); cout << x;
    }
    cout << endl;
    
    Sequence tc; //empty sequence
    zipper(tc, tc, tc); //all same + empty sequence + aliasing test
    assert(tc.size() == 0);
    zipper(ta, tc, tc); //empty sequence + aliasing test
    for(int i=0; i<ta.size(); i++){
        ta.get(i,x); cout << x;
    }
    cout << endl;
    for(int i=0; i<tc.size(); i++){
        tc.get(i,x); cout << x;
    }
    cout << endl;
    for(int i=0; i<tc.size(); i++){
        tc.get(i,x); cout << x;
    }
    cout << endl;
    
    ta = a;
    tb = b;
    zipper(ta, tc, tb); //test res is nonempty sequence (m<n)
    for(int i=0; i<ta.size(); i++){
        ta.get(i,x); cout << x;
    }
    cout << endl;
    for(int i=0; i<tc.size(); i++){
        tc.get(i,x); cout << x;
    }
    cout << endl;
    for(int i=0; i<tb.size(); i++){
        tb.get(i,x); cout << x;
    }
    cout << endl;

    ta = a; tb = b;
    zipper(tc, ta, tb); //same test, switched tc, ta order (m>n)
    cout << endl;
    for(int i=0; i<tc.size(); i++){
        tc.get(i,x); cout << x;
    }
    for(int i=0; i<ta.size(); i++){
        ta.get(i,x); cout << x;
    }
    cout << endl;
    for(int i=0; i<tb.size(); i++){
        tb.get(i,x); cout << x;
    }

    cout << endl;
    cout << "ALL TESTS PASSED" << endl;
}