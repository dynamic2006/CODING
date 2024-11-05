#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int appendToAll(string a[], int n, string value)
{
    if(n < 0) return -1;
    for(int i=0; i<n; i++) a[i] += value;
    return n;
}

int lookup(const string a[], int n, string target)
{
    if(n < 0) return -1;
    for(int i=0; i<n; i++){
        if(a[i] == target) return i;
    }
    return -1;
}

int positionOfMax(const string a[], int n)
{
    if(n <= 0) return -1;
    int maxPos = 0;
    string curMax = a[0];
    for(int i=0; i<n; i++){
        if(a[i] > curMax){
            curMax = a[i];
            maxPos = i;
        }
    }
    return maxPos;
}

int rotateLeft(string a[], int n, int pos)
{
    if(n < 0 || pos >= n || pos < 0) return -1;
    string temp = a[pos];
    for(int i=pos; i<n-1; i++){
        a[i] = a[i+1];
    }
    a[n-1] = temp;
    return pos;
}

int countRuns(const string a[], int n)
{
    if(n<0) return -1;
    int count = 0;
    string prev = "";
    for(int i=0; i<n; i++){
        if(i==0 || a[i] != prev){
            prev = a[i];
            count++;
        }
    }
    return count;
}

int flip(string a[], int n)
{
    if(n<0) return -1;
    for(int i=0; i<n/2; i++){
        string temp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
    return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<0 || n2<0) return -1;
    int n = n1;
    if(n2 < n1) n = n2;

    for(int i=0; i<n; i++){
        if(a1[i] != a2[i]) return i;
    }
    return n;
}

//can probably be cleaned up and simplified
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<0 || n2<0 || n2 > n1) return -1;
    bool valid = true;
    for(int i=0; i<=n1-n2; i++){
        for(int j=0; j<n2; j++){
            if(a1[i+j] != a2[j]){
                valid = false;
                break;
            }
        }
        if(valid) return i;
        valid = true;
    }
    return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<0 || n2<0) return -1;
    for(int i=0; i<n1; i++){
        if(lookup(a2, n2, a1[i]) != -1) return i;
    }
    return -1;
}

int separate(string a[], int n, string separator)
{
    //two pointers
    //advance both until hit first value > separator
    //then just advance right, swapping and advancing left when needed
    //until right gets to end
    if(n<0) return -1;
    int l=0, r=0;
    while(r<n && a[r] < separator){
        l++; r++;
    }

    r++;
    while(r<n){
        if(a[r] < separator){
            string temp = a[l];
            a[l] = a[r];
            a[r] = temp;
            l++;
        }
        r++;
    }
    return l;

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

    //custom tests
    string s[5] = {"", "", " ", "", ""};
    cout << separate(s, 5, "") << endl;
    for(int i=0; i<5; i++) cout << s[i].size() << " ";
    cout << endl;

    cout << "All tests succeeded" << endl;
}

