#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("books.in" , "r" , stdin);
    int n, t; cin >> n >> t;
    vector<int> reading_times(n);
    for(int i=0; i<n; i++){
        cin >> reading_times[i];
    }

    int left = 0, right = 0, total_time = 0, max_books = -1;
    while(left < n && right < n){
        while(right < n){
            total_time += reading_times[right++]; //added on [right], right is now right+1
            if(total_time > t){
                total_time -= reading_times[--right]; //removed [right+1-1], right+1 is now right
                break;
            }
        }
        //note that when the inner while loop ends, the "right" book is NOT included in the total books
        max_books = max(max_books , right - left); //exclude right, include left
        total_time -= reading_times[left++]; //remove [left], left is now left+1
        //note that the "left" book is removed, but left is incremented to left+1 at the END
        //so the "left" book IS INCLUDED in the total books (think about for the NEXT iteration of this while loop)
    }
    cout << max_books << endl;
}