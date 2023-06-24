#include <iostream>
#include <string>
using namespace std;

void reversePrint2(string& str){
    for(int i=str.size()-1; i>=0; i--){
        cout << str[i];
    }
}

void reversePrint(string& str, int counter){
    if(counter <= str.size()){
        reversePrint(str, counter+1);
        cout << str[counter];
    }
}

int main() {
    string str = "1234567";

    reversePrint(str,0); cout << endl;

    reversePrint2(str); cout << endl;
}