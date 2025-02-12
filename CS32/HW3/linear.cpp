#include <iostream>
#include <cassert>
using namespace std;

bool somePredicate(double x)
{
    return x > 0;
}
    // Return true if the somePredicate function returns true for at
    // least one of the array elements; return false otherwise.
bool anyTrue(const double a[], int n)
{
    if(n<=0) return false;
    if(somePredicate(*a)) return true;
    return anyTrue(a+1, n-1);
}

    // Return the number of elements in the array for which the
    // somePredicate function returns true.
int countTrue(const double a[], int n)
{
    if(n<=0) return 0;
    return somePredicate(*a) + countTrue(a+1, n-1);
}

    // Return the subscript of the first element in the array for which
    // the somePredicate function returns true.  If there is no such
    // element, return -1.
int firstTrue(const double a[], int n)
{
    if(n<=0) return -1;
    if(somePredicate(*a)) return 0;

    int after = firstTrue(a+1, n-1);
    if(after == -1) return -1;
    return after+1;
}

    // Return the subscript of the smallest element in the array (i.e.,
    // return the smallest subscript m such that a[m] <= a[k] for all
    // k from 0 to n-1).  If the function is told that no doubles are to
    // be considered in the array, return -1.
int positionOfMinimum(const double a[], int n)
{
    if(n<=0) return -1;
    if(n == 1) return 0;

    int nextMinPos = positionOfMinimum(a+1, n-1);
    if(a[1+nextMinPos] < a[0]) return 1+nextMinPos;
    else return 0;

}

    // If all n1 elements of a1 appear in the n2 element array a2, in
    // the same order (though not necessarily consecutively), then
    // return true; otherwise (i.e., if the array a1 is not a
    // not-necessarily-contiguous subsequence of a2), return false.
    // (Of course, if a1 is empty (i.e., n1 is 0), return true.)
    // For example, if a2 is the 7 element array
    //    10 50 40 20 50 40 30
    // then the function should return true if a1 is
    //    50 20 30
    // or
    //    50 40 40
    // and it should return false if a1 is
    //    50 30 20
    // or
    //    10 20 20
bool isIn(const double a1[], int n1, const double a2[], int n2)
{
    if(n1 <= 0) return true;
    if(n2 <= 0) return false;

    if(*a2 == *a1) return isIn(a1+1, n1-1, a2+1, n2-1);
    return isIn(a1, n1, a2+1, n2-1);
}

int main()
{
    //reference arrays
    double ref1[] = {-1, 0, -4, 2, 3, -1, 8}; //7
    double ref2[] = {};
    double ref3[] = {-1, -1, -1};
    
    //anyTrue checks
    assert(anyTrue(ref1, 7));
    assert(!anyTrue(ref2, 0));
    assert(!anyTrue(ref1, -1) && !anyTrue(ref2, -1));
    assert(!anyTrue(ref3, 3) && !anyTrue(ref1, 0));
    
    //countTrue checks
    assert(countTrue(ref1, 0) == 0 && countTrue(ref1, 2) == 0);
    assert(countTrue(ref1, 4) == 1 && countTrue(ref1, 7) == 3);
    assert(countTrue(ref2, 0) == 0 && countTrue(ref2, -1) == 0);
    assert(countTrue(ref3, -1) == 0 && countTrue(ref3, 3) == 0);

    //firstTrue checks
    assert(firstTrue(ref1, 0) == -1 && firstTrue(ref1, -1) == -1);
    assert(firstTrue(ref1, 4) == 3 && firstTrue(ref1, 7) == 3);
    assert(firstTrue(ref2, 0) == -1 && firstTrue(ref2, -1) == -1);
    assert(firstTrue(ref3, 0) == -1 && firstTrue(ref3, 3) == -1);

    //positionOfMininum checks
    assert(positionOfMinimum(ref1, 0) == -1 && positionOfMinimum(ref1, -1) == -1);
    assert(positionOfMinimum(ref1, 2) == 0 && positionOfMinimum(ref1, 3) == 2);
    assert(positionOfMinimum(ref1, 7) == 2 && positionOfMinimum(ref1, 4) == 2);
    assert(positionOfMinimum(ref2, 0) == -1 && positionOfMinimum(ref2, -1) == -1);
    assert(positionOfMinimum(ref3, 0) == -1 && positionOfMinimum(ref3, 1) == 0);
    assert(positionOfMinimum(ref3, 2) == 0 && positionOfMinimum(ref3, 3) == 0);

    // isIn checks
    assert(isIn(ref2, 0, ref1, 7) && isIn(ref2, 0, ref1, 0));
    assert(isIn(ref2, 0, ref1, -1) && isIn(ref2, -1, ref1, -1));
    assert(isIn(ref3, 0, ref1, 7) && isIn(ref3, 1, ref1, 7));
    assert(isIn(ref3, 2, ref1, 7) && !isIn(ref3, 3, ref1, 7));

    cout << "PASSED ALL TESTCASES =D" << endl;

}