#include <iostream>
#include <string>
using namespace std;

class A{
    //need to include public so str can be accessed later
    public:
        string str;
};

class B{
    public:
        B(){
            a.str = "hello"; // assigns attribute a.str to "hello" when constructing
        }
        void output(){
            cout << a.str << endl;
        }
    private:
        A a; // a is a private attribute of class B
};
int main(){
    B b;
    b.output();
}