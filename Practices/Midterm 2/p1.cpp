#include <iostream>
#include <vector>
using namespace std;

bool isQueue(const vector<int>& seq1, const vector<int>& seq2){
    for(int i=0; i<seq1.size(); i++){
        if(seq1[i] != seq2[i]){
            return false;
        }
    }
    return true;
}

bool isStack(const vector<int>& seq1, const vector<int>& seq2){
    for(int i=0; i<=(seq1.size())/2; i++){
        if(seq1[i] != seq2[seq2.size()-1-i]){
            return false;
        }
    }
    return true;
}

int main(){

    freopen("p1_input.in", "r", stdin);
    freopen("p1_output.out", "w", stdout);

    int numberOfValues;

    while(cin >> numberOfValues){
        vector<int> v1, v2;

        for(int i=0; i<numberOfValues; i++){
            int value;
            cin >> value;
            v1.push_back(value);
        }
        for(int i=0; i<numberOfValues; i++){
            int value;
            cin >> value;
            v2.push_back(value);
        }
        bool s = isStack(v1,v2);
        bool q = isQueue(v1, v2);

        if(s){
            if(q)
                cout << "Either a Stack or a Queue!" << endl;
            else
                cout << "This is a Stack!" << endl;
        }
        else{
            if(q)
                cout << "This is a Queue!" << endl;
            else
                cout << "Neither a Stack nor a Queue!" << endl;
        }
    }
}