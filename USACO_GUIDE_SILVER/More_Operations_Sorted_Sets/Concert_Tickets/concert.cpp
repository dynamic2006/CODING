#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("concert.in" , "r" , stdin);
    int n , m; cin >> n >> m;
    multiset<int> tickets;
    int ticket_price;
    for(int i=0; i<n; i++){
        cin >> ticket_price;
        tickets.insert(ticket_price);
    }

    int customer_price;
    multiset<int>::iterator it = tickets.begin();
    for(int i=0; i<m; i++){
        cin >> customer_price;
        it = tickets.upper_bound(customer_price);
        //if the ticket price strictly greater than max price is at beginning
        //since multiset tickets is sorted, there is no ticket for this customer
        if(it == tickets.begin()){
            cout << -1 << endl;
        }
        //otherwise, give them the ticket priced right underneath this one
        //guaranteed to be less than or equal to the max ticket price
        else{
            cout << *(--it) << endl;
            tickets.erase(it);
        }
    }

    return 0;


}