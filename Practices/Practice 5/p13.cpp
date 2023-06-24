#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    vector<list<int>> vec;
    list<int> list01, list02;

    for(int i=0;i<3;i++){
        list01.push_back(i);
    }

    for(int i=0;i<10;i++){
        list02.push_back(i+3);
    }

    vec.push_back(list01);
    vec.push_back(list02);

    vector<list<int>>::iterator vec_it = vec.begin();

    while(vec_it != vec.end()){
        list<int>::iterator list_it = vec_it->begin();

        while(list_it != vec_it->end()){
            cout << *list_it << " ";
            list_it++;
        }
        vec_it++;

        cout << endl;
    }
}