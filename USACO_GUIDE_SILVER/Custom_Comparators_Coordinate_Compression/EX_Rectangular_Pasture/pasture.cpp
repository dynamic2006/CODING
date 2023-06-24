#include <bits/stdc++.h>
using namespace std;

//set up the 2D prefix_sum array
const int MAX_NUM = 2500;
int prefix_sum[MAX_NUM+1][MAX_NUM+1];

//making the Cow struct and comparision operators -- acts to store input as points
struct Cow{
    int x, y;
};

bool xcmp(Cow& a, Cow& b){
    return a.x < b.x;
}

bool ycmp(Cow& a, Cow& b){
    return a.y < b.y;
}

//gets the total number of cows within the passed in coords by using the prefix sum array
//see notes on 2D prefix sums
int get_total_cows(int x1, int y1, int x2, int y2){
    return prefix_sum[x2+1][y2+1] - prefix_sum[x2+1][y1] - prefix_sum[x1][y2+1] + prefix_sum[x1][y1];
}

int main(){
    //freopen("pasture.in" , "r" , stdin);

    //INPUT
    int n; cin >> n;
    vector<Cow> cows(n); //stores locations of all cows
    for(int i=0; i<n; i++){
        cin >> cows[i].x >> cows[i].y;
    }
    
    /*
    * COORDINATE COMPRESSION
    * this works because all x coords and y coords are distinct
    * note this is operating on the cows vector itself
    * so the data for the specific location of the cows is lost
    * replaced with relative location of cows -- more efficient
    * this gets rid of empty space gaps which reduces a 10^9 x 10^9 grid to a n x n grid
    * the n x n grid has at most 2500^2 space/time complexity
    */
    //coord compress the x coords -- map each one to an index from 1 to n
    sort(cows.begin() , cows.end() , xcmp);
    for(int i=0; i<n; i++) cows[i].x = i+1;
    //coord compress the y coords -- map each one to an index from 1 to n
    sort(cows.begin() , cows.end() , ycmp);
    for(int i=0; i<n; i++) cows[i].y = i+1;

    //2D PREFIX SUM
    //when a cow is present at a point, the prefix_sum is incremented by one at that point
    //so set all values in prefix_sum where a cow is present to 1
    for(int i=0; i<n; i++){
        prefix_sum[cows[i].x][cows[i].y] = 1;
    }
    //build prefix_sum 2D array using formula (see notes on 2D prefix sums)
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            prefix_sum[i][j] += prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i-1][j-1];
        }
    }

    /*
    * CALCULATE ANSWER
    * for some lower left cow and upper right cow
    * count all fences that lie within x coords defined by those two cows
    * fence may extend up or down to include higher or lower y coord cows
    * this works because all x coords and y coords are distinct
    * note that there are no repeats because the x coords are constrained
    * we can choose any of the higher cows (high) to expand to
    * we can also choose any of the lower cows (low) to expand to
    * so the number of subsets increases by high*low
    * iterate over all subsets of two cows
    */
    long long subsets = 0; //total subsets
    //nested for loop to get all combos of two cows
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int x1 = min(cows[i].x , cows[j].x) - 1; //get the lower x coord boundary
            int x2 = max(cows[i].x , cows[j].x) - 1; //get the upper x coord boundary
            //use the get_total_cows function to get high and low cows
            //then multiply these values together to get total new subsets
            subsets += get_total_cows(0,i,x1,j) * get_total_cows(x2, i, n-1, j);
        }
    }

    cout << subsets + 1 << endl; //add one for the empty subset
    
}