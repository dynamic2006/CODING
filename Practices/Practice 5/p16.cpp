#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define VECT_IT typename std::vector<T>::iterator

template <typename T>
class MyClass{
    public:
        MyClass(T* begin, int n){
            T* end = begin+n;

            while(begin != end){
                name.push_back(*begin);
                begin++;
            }
            sort(name.begin(), name.end());
        }

        void output() {
            VECT_IT it = name.begin();
            cout << *it++;
            for(; it != name.end(); it++){
                cout << "," << *it;
            }
            cout << endl;
        }
    
    private:
        vector<T> name;
};

int main() {
    string str[5] = {"Pineapple", "Strawberry", "Banana", "Apple", "Blackberry"};

    MyClass<string> mc(str,5);

    mc.output();
}