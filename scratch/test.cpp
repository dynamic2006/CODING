#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i = 0,value = 0;
    for( i = 0 ; i < 5 ; i++ ){
        cout << "cases ";
        switch( i ) {
        case 1: 
            value = i + 1;
            cout << "1:" << i << " ";
        case 2: 
            value = value - 1;
            cout << "2:" << i << " ";
        case 3: 
            value = value + 1;
            cout << "3:" << i << " ";
        case 4: 
            value = value + 2;
            cout << "4:" << i << " ";
        case 5:
            cout << "5:" << i << " ";
            value = value - 1;
        default: 
            cout << "default:" << i << " ";
            value = value + 1;
        }
        cout << "applied" << endl;
        cout << value << endl;
    }
    cout << value << endl;
} 