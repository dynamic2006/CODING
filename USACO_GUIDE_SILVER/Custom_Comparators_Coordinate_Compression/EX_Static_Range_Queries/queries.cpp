#include <bits/stdc++.h>
using namespace std;

typedef long long ll; //TYPEDEF (like an abbreviation)

//defined globally so that getCompressedIndex function can access it
//the set is ordered and has no duplicates, so it helps with the coord compression
//use find() to get the compressed index of an element in the set
vector<int> indices;

//STRUCTS -- one for updates and one for queries
struct Update{
    int l, r, val;
};

struct Query{
    int l, r;
};

//gets the index of element in the vector indices
//uses lower_bound to get iterator to element, then subtract begin()
//this way you get the difference which is the index of element
int getCompressedIndex(int element){
    return lower_bound(indices.begin() , indices.end() , element) - indices.begin();
}

int main(){

    //FAST INPUT / OUTPUT
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("queries.in" , "r" , stdin);

    //DEFINE LOCALS
    //an interval is the space between two index values
    int n, q; cin >> n >> q;
    vector<Query> queries(q); //holds query indices
    vector<Update> updates(n); //holds update indices and value
    //note 2*(n+q) used for size since at most, each of n update and q queries has 2 unique indices --> 2*(n+q) elements
    vector<ll> diff_array(2*(n+q)); //difference_array[i] = the difference of the values between intervals i-1 and i
    vector<ll> interval_value(2*(n+q)); interval_value[0] = 0; //interval_value[i] = the value of interval i
    vector<int> interval_lengths(2*(n+q)); interval_lengths[0] = 0; //width[i] is the length of interval i
    vector<ll> prefix_sums(2*(n+q)); prefix_sums[0] = 0; //prefix_sums[i] = prefix sum of the sums of intervals up to i

    //INPUT
    int l, r, v;
    for(int i=0; i<n; i++){
        cin >> l >> r >> v;
        indices.push_back(l);
        indices.push_back(r);
        updates[i].l = l; updates[i].r = r;
        updates[i].val = v;
    }
    for(int i=0; i<q; i++){
        cin >> l >> r;
        indices.push_back(l);
        indices.push_back(r);
        queries[i].l = l; queries[i].r = r;
    }

    //COORDINATE COMPRESSION
    sort(indices.begin() , indices.end()); //sort the vector of indices
    //this uses unique to get rid of duplicate index values in the vector
    //unique returns an iterator to the element after the last element that isn't removed
    //so we must erase the rest of the elements from this iterator to the end()
    indices.erase(unique(indices.begin(), indices.end()), indices.end());

    for(int i=0; i<n; i++){
        //build compressed difference array, stores the change in values from one interval to the next
        //note that only the compressed values of update indexes are accessed
        //so some values in diff_array are untouched -- left as zero
        //diff_array is used to build the interval_value vector later on
        //similar to Haybale_Stacking presub array in the Intro to Prefix Sums module
        diff_array[getCompressedIndex(updates[i].l) + 1] += updates[i].val; //increment left index by val
        diff_array[getCompressedIndex(updates[i].r) + 1] -= updates[i].val; //decrement right index by val
    }
    for(int i = 0; i < indices.size() - 1; i++){
        //get length of each interval by finding difference of consecutive indices
        //note indices has both update and query indices -- all of them are used for intervals
        interval_lengths[i+1] = indices[i+1] - indices[i];
    }
    for(int i=1; i < indices.size(); i++){
        //acts as a prefix sum but for the interval values (see 1D prefix sum notes)
        //note some diff_array values are zero, so the interval_value doesn't change for those
        //for example, query indexes were not used when building the diff_array
        //so diff_array[i] = 0 where i is a compressed index for a query index
        //and the interval values are equal for the two intervals with the query index as an endpoint
        //diff_array was compressed with respect to intervals, so we can just do:
        interval_value[i] = interval_value[i-1] + diff_array[i]; //similar to a prefix sum
    }
    //fill 1D prefix sum array
    for(int i=1; i<indices.size(); i++){
        //for the sum of the values of an interval, multiply the interval's length and value
        //then apply the prefix sum formula (see 1D prefix sum notes)
        prefix_sums[i] = prefix_sums[i-1] + interval_value[i] * interval_lengths[i];
    }

    //ANSWER QUERIES
    for(int i=0; i<q; i++){
        //get range query by applying prefix sum (see 1D prefix sum notes)
        cout << prefix_sums[getCompressedIndex(queries[i].r)] - prefix_sums[getCompressedIndex(queries[i].l)] << endl;
    }

}