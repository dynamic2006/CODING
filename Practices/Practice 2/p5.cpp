#include <iostream>
#include <string>
#include <stack> //stack means last in first out (LIFO)

using namespace std;

int main() {

    string str;
    cout << "Please enter a string: ";
    cin >> str;
    int i, len = str.size(); //gives back actual size of string without \0

    stack<char> s;

    for(i=0; i<len/2; i++){ //note it increments i by 1 on the last turn, so if len = 5, when this exits i=3
        s.push(str[i]);
    }

    if(len % 2 == 1){
        i++; // skip to next char -- the middle char is always the same as itself
    }

    for(; i<len; i++){
        if(s.top() != str[i]){
            break;
        }
        s.pop();
    }

    if(i == len){
        cout << str << " is a palindrome." << endl;
    }
    else{
        cout << str << " is NOT a palindrome." << endl;
    }
}