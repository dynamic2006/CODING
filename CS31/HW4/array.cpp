#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//appends string value to each string in array a
int appendToAll(string a[], int n, string value)
{
    if(n < 0) return -1; //invalid size
    for(int i=0; i<n; i++) a[i] += value;
    return n;
}

//returns pos of first appearance of string target in string array a
int lookup(const string a[], int n, string target)
{
    if(n < 0) return -1; //invalid size
    for(int i=0; i<n; i++){
        if(a[i] == target) return i;
    }
    return -1;
}

//returns positions of max element in string array a
int positionOfMax(const string a[], int n)
{
    if(n <= 0) return -1; //ionvalid size
    int maxPos = 0;
    string curMax = a[0];
    for(int i=0; i<n; i++){
        //only update if strictly greater than
        if(a[i] > curMax){
            curMax = a[i];
            maxPos = i;
        }
    }
    return maxPos;
}

//rotates elements in arrays to left
//cycle starts from pos and goes to end of visible array
int rotateLeft(string a[], int n, int pos)
{
    if(n < 0 || pos >= n || pos < 0) return -1; //invalid args
    string temp = a[pos];
    //shift each element after pos left by one
    for(int i=pos; i<n-1; i++){
        a[i] = a[i+1];
    }
    a[n-1] = temp;
    return pos;
}

//counts number of consecutive runs in array a
int countRuns(const string a[], int n)
{
    if(n<0) return -1; //invalid arg
    int count = 0;
    string prev = "";
    for(int i=0; i<n; i++){
        if(i==0 || a[i] != prev){
            prev = a[i]; //to track if same as previous element
            count++; //counter
        }
    }
    return count;
}


//reverses (flips) visible array a
int flip(string a[], int n)
{
    if(n<0) return -1; //invalid
    //only need to iterate over first n/2 elements
    //for each, swap with corresponding element on right side of array
    for(int i=0; i<n/2; i++){
        //swap
        string temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
    return n;
}

//finds first pos where elements in a1 and a2 differ
int differ(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<0 || n2<0) return -1; //invalid
    //n is min of n1 and n2
    int n = n1;
    if(n2 < n1) n = n2;

    for(int i=0; i<n; i++){
        //if different, return pos i
        if(a1[i] != a2[i]) return i;
    }
    return n;
}

//finds starting pos where a2 is a subsequence of a1, if possible
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<0 || n2<0 || n2 > n1) return -1; //invalid cases
    bool valid = true; //tracks if currently a valid subsequence or not
    //start subseq at pos i in a1
    for(int i=0; i<=n1-n2; i++){
        //start subseq always from pos 0 in a2
        for(int j=0; j<n2; j++){
            //a2[j] corresponds to a1[i+j]
            if(a1[i+j] != a2[j]){
                valid = false;
                break;
            }
        }
        if(valid) return i;
        valid = true; //reset for next iteration
    }
    return -1;
}

//looks up first element in a1 that is present in a2 and returns its pos in a1
int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<0 || n2<0) return -1; //invalid
    //try each element in a1
    for(int i=0; i<n1; i++){
        //can use lookup as a helper function
        if(lookup(a2, n2, a1[i]) != -1) return i;
    }
    return -1;
}

//separates based on boundary
int separate(string a[], int n, string separator)
{
    //two pointers
    //advance both until hit first value > separator
    //then just advance right, swapping and advancing left when needed
    //until right gets to end

    if(n<0) return -1; //invalid
    int l=0, r=0; //ptrs

    //advance both while you haven't hit something >separator
    while(r<n && a[r] < separator){
        l++; r++;
    }

    //if a[r] < separator
    //could have situation where separator is left on high end

    //if a[r] <= separator
    //could have situation where separator is placed before <separator

    r++; //ensure r>l for swapping
    while(r<n){
        if(a[r] < separator){
            //swap if needed
            string temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++; //l is tracking first value >= separator
        }
        r++; //increment r
    }

    int ans = l; // store this for return value

    //repeat to set l to track first value > separator
    r = l;
    while(r<n && a[r] == separator){
        l++; r++;
    }

    //now make sure all elements > separator come after separator
    while(r<n){
        if(a[r] == separator){
            //swap if needed
            string temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++; //l is now tracking first value > separator
        }
        r++;
    }

    return ans;

}

int main()
{
    string h[7] = { "melania", "kamala", "donald", "tim", "", "doug", "jd" };
    assert(lookup(h, 7, "doug") == 5);
    assert(lookup(h, 7, "donald") == 2);
    assert(lookup(h, 2, "donald") == -1);
    assert(positionOfMax(h, 7) == 3);

    string g[4] = { "melania", "kamala", "jd", "usha" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "melania?" && g[3] == "usha?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "jd?" && g[3] == "kamala?");

    string e[4] = { "donald", "tim", "", "doug" };
    assert(subsequence(h, 7, e, 4) == 2);

    string d[5] = { "kamala", "kamala", "kamala", "tim", "tim" };
    assert(countRuns(d, 5) == 2);

    string f[3] = { "jd", "donald", "gwen" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "gwen" && f[2] == "jd");

    assert(separate(h, 7, "jd") == 3);

    string people2[4] = { "jill", "tim", "jd", "joe" };
    int y = separate(people2, 4, "joe");  //  returns 2
    cout << y << endl;
    for(int i=0; i<4; i++) cout << people2[i] << " ";
    cout << endl;

    //custom tests
    string arr1[5] = {"", "", " ", "  ", ""};
    string arr2[5] = {" ", "", "cat", "dog", "bird"};
    string arr3[5] = {"a", "b", "c", "d", "e"};
    string arr4[5] = {"abc", "abc", "abc", "ab", "a"};
    string arr5[0] = {};
    string arr6[1] = {""};
    string arr7[1] = {" "};

    //appendToAll tests
    // assert(appendToAll(arr1, 4, "") == 4 && arr1[0].size() == 0 && arr1[3].size() == 2); //string array has spaces and empty string elements
    // assert(appendToAll(arr1, 3, " ") == 3 && arr1[0].size() == 1 && arr1[3].size() == 2); //appending space to array with spaces and empty string elements
    // assert(appendToAll(arr5, 0, "a") == 0 && appendToAll(arr7, 0, "a") == 0); //n equals zero + arr is empty test
    // assert(appendToAll(arr3, 0, "x") == 0 && appendToAll(arr3, -1, "x") == -1 && arr3[0] == "a"); //n equals zero and n<0 with normal array test
    // assert(appendToAll(arr3, 3, "x") == 3 && arr3[0] == "ax" && arr3[3] == "d"); //check to make sure only first n values are changed
    //lookup tests
    // assert(lookup(arr1, 0, "") == -1 && lookup(arr1, 5, "") == 0); //lookup with n=0 and with empty string
    // assert(lookup(arr2, 1, "") == -1 && lookup(arr2, 5, "  ") == -1); //lookups with values not in visible array
    // assert(lookup(arr4, 5, "a") == 4 && lookup(arr4, 5, "abc") == 0); //check if first exact match is returned
    // assert(lookup(arr5, 0, "") == -1); // empty array check
    // assert(lookup(arr6, -1, "") == -1); //n<0 check
    //positionOfMax tests
    // assert(positionOfMax(arr1, 2) == 0 && positionOfMax(arr1, 5) == 3); //arr has empty strings and spaces
    // assert(positionOfMax(arr2, 0) == -1); //no elements considered (n=0)
    // assert(positionOfMax(arr3, 4) == 3 && positionOfMax(arr3, 5) == 4); //only first n elements visible check
    // assert(positionOfMax(arr5, 0) == -1); //array is empty
    // assert(positionOfMax(arr6, -2) == -1); //n<0
    //rotateLeft tests
    // assert(rotateLeft(arr1, 5, 2) == 2 && arr1[2] == "  " && arr1[4] == " "); //rotating with empty string and spaces in arr
    // assert(rotateLeft(arr1, 3, 1) == 1 && arr1[1] == " " && arr1[2] == "" && arr1[3] == "  "); //only first n elements visible check
    // assert(rotateLeft(arr3, 0, 0) == -1 && rotateLeft(arr3, 1, 0) == 0 && arr3[0] == "a"); //pos is equal to n and n=1 check
    // assert(rotateLeft(arr5, 0, 0) == -1 && rotateLeft(arr5, 0, -1) == -1); //arr is empty check
    // assert(rotateLeft(arr4, -1, -1) == -1 && rotateLeft(arr4, -2, 0) == -1); //n<0 check
    //countRuns tests
    // assert(countRuns(arr1, 4) == 3 && countRuns(arr1, 5) == 4); //arr has empty string and spaces check
    // assert(countRuns(arr2, 0) == 0); //n=0 check -- no visible items
    // assert(countRuns(arr4, 2) == 1 && countRuns(arr4, 5) == 3); //consecutive duplicates
    // assert(countRuns(arr5, 0) == 0); //empty array
    // assert(countRuns(arr6, 1) == 1); //only one element in array
    //flip tests
    // assert(flip(arr1, 5) == 5 && arr1[0] == "" && arr1[1] == "  "); //array with empty strings and spaces
    // assert(flip(arr3, 5) == 5 && arr3[0] == "e" && arr3[4] == "a"); //completely reverse normal array
    // assert(flip(arr3, -1) == -1); //n<0 check
    // assert(flip(arr5, 0) == 0); //empty array n=0
    // assert(flip(arr6, 1) == 1 && arr6[0] == ""); //array with only one element
    //differ tests
    // assert(differ(arr2, 5, arr3, 5) == 0); //difference at first pos (0)
    // assert(differ(arr3, 5, arr3, 5) == 5); //a1 is the same as a2
    // assert(differ(arr3, 3, arr4, 3) == 0); //arrays have shared element "a", but not same pos
    // assert(differ(arr3, 5, arr5, 0) == 0); //second array is empty
    // assert(differ(arr6, -1, arr6, 0) == -1); //n1<0
    //subsequence tests
    // assert(subsequence(arr3, 5, arr4, 1) == -1); //different n ranges
    // assert(subsequence(arr3, 5, arr3, 5) == 0); //a1=a2
    // assert(subsequence(arr4, 1, arr3, 1) == -1 && subsequence(arr4, 5, arr3, 1) == 4); //found subsequence for normal input
    // assert(subsequence(arr3, 5, arr3, 0) == 0 && subsequence(arr1, 0, arr3, 0) == 0); //n1 and/or n2 are zero
    // assert(subsequence(arr5, 0, arr6, 1) == -1); //n2>n1
    //lookupAny tests
    // assert(lookupAny(arr3, 5, arr2, 5) == -1); //arrays share no matching elements
    // assert(lookupAny(arr3, 5, arr4, 5) == 0 && lookupAny(arr4, 5, arr3, 5) == 4); //changing order of arrays
    // assert(lookupAny(arr3, 5, arr5, 0) == -1); //second array is empty
    // assert(lookupAny(arr1, 5, arr6, 1) == 0); //empty string element check
    // assert(lookupAny(arr1, 2, arr7, 1) == -1 && lookupAny(arr1, 5, arr7, 1) == 2); //check if only first n elements visible
    //separate tests
    // assert(separate(arr1, 5, " ") == 3 && arr1[2] == "" && arr1[3] == " " && arr1[4] == "  "); //arr contains empty strings and spaces
    // assert(separate(arr4, 5, "ab") == 1 && arr4[0] == "a" && arr4[2] == "abc"); //arr contains the separator
    // assert(separate(arr5, 0, "") == 0); //arr is empty
    // assert(separate(arr5, -1, " ") == -1); //n<0 is invalid
    // assert(separate(arr7, 1, "") == 0 && separate(arr7, 1, "  ") == 1); //arr only has one element

    string arr[12] = {"b", "d", "c", "a", "f", "a", "b", "e", "c", "c", "d", "e"};
    cout << separate(arr, 12, "b") << endl;
    for(int i=0; i<12; i++) cout << arr[i] << " ";
    cout << endl;
    // cout << separate(arr, 12, "c") << endl;
    // for(int i=0; i<12; i++) cout << arr[i] << " ";
    // cout << endl;
    


    cout << "All tests succeeded" << endl;
}

