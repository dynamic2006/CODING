#include <bits/stdc++.h>
using namespace std;

struct Cow
{
    long long milk;
};

bool cmp_cow(Cow& a, Cow& b){
    return (a.milk > b.milk);
}

struct Store
{
    long long max_gallons, cents_per_gallon;
};

bool cmp_store(Store& a, Store& b){
    return (a.cents_per_gallon > b.cents_per_gallon);
}

struct Neighbor
{
    long long rent;
};

bool cmp_neighbor(Neighbor& a, Neighbor& b){
    return (a.rent > b.rent);
}

int main()
{
    freopen("rental.in" , "r" , stdin);
    freopen("rental.out" , "w" , stdout);

    long long max_total = 0;
    long long n, m, r; cin >> n >> m >> r;
    vector<Cow> cows(n);
    vector<Store> stores(m);
    vector<Neighbor> neighbors(r);
    vector<long long> prefix_neighbors(r+1); prefix_neighbors[0] = 0;
    vector<long long> prefix_gallons(n+1); prefix_gallons[0] = 0;

    for(long long i=0; i<n; i++)
        cin >> cows[i].milk;
    for(long long i=0; i<m; i++)
        cin >> stores[i].max_gallons >> stores[i].cents_per_gallon;
    for(long long i=0; i<r; i++)
        cin >> neighbors[i].rent;

    sort(cows.begin() , cows.end(), cmp_cow);
    sort(stores.begin() , stores.end() , cmp_store);
    sort(neighbors.begin() , neighbors.end() , cmp_neighbor);

    for(long long i=1; i<=r; i++)
        prefix_neighbors[i] = prefix_neighbors[i-1] + neighbors[i-1].rent;
    for(long long i=1; i<=n; i++)
        prefix_gallons[i] = prefix_gallons[i-1] + cows[i-1].milk;

    long long to_rent = min(n,r); long long to_milk = min(m, n - min(n,r));
    bool fin = false;
    while(to_rent >= 0 && !fin){
        long long money_from_rent = prefix_neighbors[to_rent], milk_gallons = prefix_gallons[to_milk];
        long long total = money_from_rent; long long cur_store = 0;
        while (milk_gallons > 0 && cur_store < m){
            total += stores[cur_store].cents_per_gallon * min(milk_gallons, stores[cur_store].max_gallons);
            milk_gallons -= min(milk_gallons, stores[cur_store].max_gallons); cur_store++;
        }
        to_rent--; to_milk++;
        to_milk = min(to_milk, m);
        if(max_total > total){fin = true;}
        max_total = max(max_total, total);
    }

    cout << max_total;

}

/*
* Passes 8/10 test cases, times out on last two
* Time out may be due to extra for loops for prefix sum arrays
* Time out may also be due to nested while loops (although USACO sol also uses these)
* Try fixing while loops to make fewer passes when recoding
*/