#include <bits/stdc++.h>
using namespace std;

int n, m, total_erased;
vector<string> test_cases; vector<int> outputs;

string recurse(const int cur_bit, const int desired_bit_num, const int desired_output){
    if(total_erased == m){
        return "OK";
    }

    if(cur_bit == n){
        return "LIE";
        // bool has_one = false, has_zero = false;
        // for(int i=0; i<n; i++){
        //     if(outputs[i] == 0)
        //         has_zero = true;
        //     if(outputs[i] == 1)
        //         has_one = true;
        //     if(has_zero && has_one)
        //         return "LIE";
        // }
        // return "OK";
    }

    bool valid_if_statement = true, found_one_index = false;
    
    for(int i=0; i<m; i++){
        if(outputs[i] == -1) continue;
        if(test_cases[i][cur_bit] == '0' + desired_bit_num){
            found_one_index = true;
            if(outputs[i] != desired_output){
                valid_if_statement = false;
            }
        }
    }

    if(!valid_if_statement || !found_one_index){
        if(desired_bit_num == 1 && desired_output == 1){
            return recurse(cur_bit + 1, 0, 0);
        }
        else if(desired_bit_num == 1){
            return recurse(cur_bit, 1, 1);
        }
        else if(desired_output == 1){
            return recurse(cur_bit, 1, 0);
        }
        else{
            return recurse(cur_bit, 0, 1);
        }
    }

    for(int i=0; i<m; i++){
        if(test_cases[i][cur_bit] == '0' + desired_bit_num && outputs[i] != -1){
            outputs[i] = -1; total_erased++;
        }
    }
    // cout << cur_bit << " " << desired_bit_num << " " << desired_output << endl;
    // cout << "TOTAL ERASED " << total_erased << endl;

    return recurse(0, 0, 0);
}

void solve(){
    string test_case; int output;

    test_cases.clear(); outputs.clear(); total_erased = 0;

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> test_case >> output;
        test_cases.push_back(test_case);
        outputs.push_back(output);
    }

    cout << recurse(0, 0, 0) << endl;
}

int main(){
    //freopen("p3.in" , "r" , stdin);
    
    int t; cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
}

/*
* ALRIGHT HERES THE IMPORTANT SHIT
* read the problem carefully -- bits can be checked in MORE THAN ONE if statement
* so the recursion can "backtrack" can start from cur_bit = 0 again when a valid if statement is found
*/