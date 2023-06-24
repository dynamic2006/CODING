#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("apartments.in" , "r" , stdin);

    int n, m, k; cin >> n >> m >> k;
    vector<int> applicants(n) , apartment_sizes(m);
    for(int i=0; i<n; i++){
        cin >> applicants[i];
    }
    for(int i=0; i<m; i++){
        cin >> apartment_sizes[i];
    }
    sort(applicants.begin() , applicants.end());
    sort(apartment_sizes.begin() , apartment_sizes.end());

    int cur_applicant = 0, cur_apartment = 0, total_sold_apartments = 0;
    while(cur_applicant < n && cur_apartment < m){
        if(apartment_sizes[cur_apartment] + k < applicants[cur_applicant])
            cur_apartment++;
        else if(applicants[cur_applicant] + k < apartment_sizes[cur_apartment])
            cur_applicant++;
        else{
            cur_apartment++; cur_applicant++;
            total_sold_apartments++;
        }
    }
    cout << total_sold_apartments << endl;

}