#include <iostream>
using namespace std;

void mystrcpy(char* str1, char* str2){
    
    while(*str2 != '\0'){
        *str1++ = *str2++;
    }
    *str1 = '\0';
}

int main() {
    char str1[15] = "C++fhgfhgfhgf";
    char str2[15] = "Pointers";

    cout << str1 << "----------" << str2 << endl;
    mystrcpy(str1, str2); // cpy from str2 t ostr
    cout << str1 << "----------" << str2 << endl;
}