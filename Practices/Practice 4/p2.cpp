#include <iostream>
using namespace std;

void foo2(int a[], int count){
    if(count == 2){
        for(int i=0;i<2;i++){
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for(int i=0;i<4;i++){
        a[count] = i;
        foo2(a,count+1);
    }
}

int main() {
    int a[3];
    foo2(a,0);
}