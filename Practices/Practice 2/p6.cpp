#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    
    int i;
    queue<int> q;
    stack<int> s;

    for(i=0;i<10;i++){
        q.push(i);
    }

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
    cout << endl;
}