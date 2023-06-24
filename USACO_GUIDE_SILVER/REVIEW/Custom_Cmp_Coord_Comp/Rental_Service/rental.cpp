#include <bits/stdc++.h>
using namespace std;

struct Cow {
    long long milk, profit = 0;
    bool rental = false;
};

struct Order {
    long long gallons, unitPrice;
};

bool cmpCow (Cow& a, Cow& b){
    return a.milk > b.milk;
}

bool cmpOrder (Order& a, Order& b){
    return a.unitPrice > b.unitPrice;
}

int main(){
    
    freopen("rental.in" , "r" , stdin);
    freopen("rental.out" , "w" , stdout);

    //sort cows by increasing milk production
    //sort milk orders by increasing $/unit
    //sort rentals by increasing $$
    //put as many cows as possible to milk orders
    //calculate total $ as you add cows
    //if any cows left over, fill rentals in order

    //if cost can be increased by moving
    //a milk order cow to a rental
    //move the cow and continue -- cout max profit

    long long n, m, r; cin >> n >> m >> r;
    vector<Cow> cows(n);
    vector<long long> rentals(r);
    vector<Order> orders(m);
    for(long long i=0; i<n; i++){
        cin >> cows[i].milk;
        cows[i].profit = 0;
    }
    for(long long i=0; i<m; i++){
        cin >> orders[i].gallons >> orders[i].unitPrice;
    }
    for(long long i=0; i<r; i++) cin >> rentals[i];

    //sort cows, orders and rentals
    sort(cows.begin() , cows.end() , cmpCow);
    sort(orders.begin() , orders.end() , cmpOrder);
    sort(rentals.begin() , rentals.end() , greater<long long>());

    vector<Cow>::iterator curCow = cows.begin();
    vector<Order>::iterator curOrder = orders.begin();
    
    long long totalProfit = 0;

    //put cows for orders
    while(curCow != cows.end() && curOrder != orders.end()){
        if(curOrder->gallons > curCow->milk){
            //cout << curOrder->gallons << " " << curCow->milk << endl;
            //cout << curCow->profit << " " << totalProfit << endl;
            curCow->profit += (curCow->milk)*(curOrder->unitPrice);
            //cout << curCow->profit << " " << totalProfit << endl;
            totalProfit += curCow->profit;
            //cout << curCow->milk << " " << totalProfit << endl;
            curOrder->gallons -= curCow->milk;
            curCow->milk = 0; curCow++;
        }
        else {
            curCow->profit += (curOrder->gallons)*(curOrder->unitPrice);
            curCow->milk -= curOrder->gallons;
            curOrder->gallons = 0; curOrder++;
        }
    }

    // cout << curCow->milk << " " << curCow->profit << endl;
    // cout << totalProfit << endl;

    if(curOrder == orders.end() && curCow != cows.end() && curCow->milk != 0) {
        totalProfit += curCow->profit;
        curCow++;
    }

    //put the rest of the cows for rental
    vector<long long>::iterator curRental = rentals.begin();
    while(curCow != cows.end() && curRental != rentals.end()){
        curCow->rental = true; curCow++;
        //cout << *curRental << " ";
        totalProfit += *curRental; curRental++;
    }

    // cout << totalProfit << endl;
    // return 0;

    //now try switching order cows to rental cows and calculate the max profit
    for(long long i=n-1; i>=0; i--){
        if(cows[i].rental) continue;
        //cout << totalProfit << " ";
        //no more money can be earned since rentals are gone
        if(curRental == rentals.end()){
            cout << totalProfit << endl;
            return 0;
        }
        //cout << *curRental << " " << cows[i].profit << endl;
        long long newProfit = totalProfit - cows[i].profit + *curRental;
        //cout << i << " " << cows[i].profit << endl;
        //cout << *curRental << " " << newProfit << " " << totalProfit << endl;
        curRental++;

        //if profit goes down, then totalProfit is the most we can make overall
        if(newProfit < totalProfit){
            cout << totalProfit << endl;
            return 0;
        }
        else totalProfit = newProfit;
    }

}