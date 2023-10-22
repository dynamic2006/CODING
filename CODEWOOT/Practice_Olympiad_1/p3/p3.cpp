#include <bits/stdc++.h>
using namespace std;

int main() {

    //freopen("p3.in" , "r" , stdin);

    //keep a map for deletion order that maps index to word
    map<int, string> deletionOrder;
    //keep a map for current list that maps word to index
    map<string, int> currentList;

    int k, q; cin >> k >> q;
    long long index = 0, ans = 0;

    for(int i=0; i<q; i++){
        string word; cin >> word;
        //if the word is NOT currently in the list
        if(currentList.count(word) == 0){
            //if list is at max size
            if(currentList.size() == k){
                //then delete least recent word
                string leastRecentWord = deletionOrder.begin()->second;
                int deleteIndex = currentList[leastRecentWord];
                currentList.erase(leastRecentWord);
                deletionOrder.erase(deleteIndex);
            }
            //then add word into list
            currentList[word] = index;
            deletionOrder[index] = word;

            ans += 10;
        }
        //otherwise if the word IS currently in the list
        else {
            //update deletion order and current list
            int curIndex = currentList[word];
            deletionOrder.erase(curIndex);

            deletionOrder[index] = word;
            currentList[word] = index;

            ans += 1;
        }
        //cout << ans << endl;

        // for(auto x : deletionOrder){
        //     cout << x.first << " " << x.second << endl;
        // }
        // cout << endl;
        // for(auto x : currentList){
        //     cout << x.first << " " << x.second << endl;
        // }
        // cout << endl;
        // cout << endl;

        index++;
    }

    cout << ans << endl;

}