#include <iostream>
#include <algorithm>
using namespace std;

bool isDoable(int jug1, int cap1, int jug2, int cap2, int target, int depth){
    if(jug1 == target || jug2 == target)
        return true;
    
    if(depth == 9) //our limit on the depth of a recursion
        return false;
    
    //Can it be solved by filling A first?
    if(isDoable(cap1,cap1,jug2,cap2,target,depth+1))
        return true;
    
    //Can it be solved by filling B first?
    if(isDoable(jug1,cap1,cap2,cap2,target,depth+1))
        return true;

    //Can it be solved by emptying A first?
    if(isDoable(0,cap1,jug2,cap2,target,depth+1))
        return true;
    
    //Can it be solved by emptying B first?
    if(isDoable(jug1,cap1,0,cap2,target,depth+1))
        return true;
    
    //Can it be solved by pouring from B to A first?
    int amt = min(cap1-jug1 , jug2);
    if(isDoable(jug1+amt , cap1 , jug2-amt , cap2 , target , depth+1))
        return true;
    
    //Can it be solved by pouring from A to B first?
    amt = min(cap2-jug2 , jug1);
    if(isDoable(jug1-amt , cap1 , jug2+amt , cap2 , target , depth+1))
        return true;
    
    //Nothing leads to a solution
    return false;
}

int main(){
    freopen("p4_input.in", "r", stdin);
    freopen("p4_output.out", "w", stdout);
    
    int jug1_capacity, jug2_capacity, target;
    while(cin >> jug1_capacity >> jug2_capacity >> target){
        // cout << jug1_capacity << endl;
        if(isDoable(0, jug1_capacity, 0, jug2_capacity, target, 0))
            cout << "This can be solved!" << endl;
        else
            cout << "This cannot be solved within 9 steps!" << endl;
    }
}