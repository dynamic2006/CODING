#include <iostream>
using namespace std;

void removeS(char* str)
{
    char* temp = str;
    while(*str != 0){
        if(*str != 'S' && *str != 's'){
            *temp = *str;
            temp++;
        }
        str++;
    }
    *temp = '\0';
}

int main()
{
    char msg[50] = "She'll blossom like a massless princess.";
    removeS(msg);
    cout << msg;  // prints   he'll bloom like a male prince.
}