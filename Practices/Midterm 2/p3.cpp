#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Base{
    public:
        Base(string nm): name(nm){}
        string getName() const {return name;}
        virtual void printName() const {cout << "Base " << name << endl;}

    private:
        string name;
};

class Derived : public Base{
    public:
        Derived(string nm): Base("Doctor " + nm){}
        virtual void printName() const {cout << "Derived " << getName() << endl;}
};

void printAll(const vector<Base*>& vec){
    for(int i=0; i!=vec.size(); i++){
        (vec[i])->printName();
    }
};

int main(){

    vector<Base*> v;
    v.push_back(new Base("Homer Simpson"));
    v.push_back(new Derived("Beverly Crusher"));
    v.push_back(new Derived("Who"));
    printAll(v);
    for(int i=0; i<3; i++){
        delete v[i];
    }
}