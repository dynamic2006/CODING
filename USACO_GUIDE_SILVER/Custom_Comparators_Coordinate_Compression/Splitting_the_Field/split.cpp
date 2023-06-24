#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//Cow struct + comparision operators for sorting by x or y coords
struct Cow {
    long x = 0, y = 0;
};

bool xcmp(const Cow &a, const Cow &b) {
    return a.x < b.x;
}

bool ycmp(const Cow &a, const Cow &b) {
    return a.y < b.y;
}

//Field struct -- represents one of the rectangles
struct Field {
    set<ll> xset;
    map<ll , ll> xmap; //needed for exclusions
    set<ll> yset;
    map<ll, ll> ymap; //needed for exclusions

    //simulates the inclusion of a point from a field
    //an operation that happens during the line sweep
    //new Cow to include has coords xnew and ynew
    void include(long xnew, long ynew) {
        xmap[xnew]++;
        xset.insert(xnew);

        ymap[ynew]++;
        yset.insert(ynew);
    }

    //simulates the exclusion of a point from a field
    //an operation that happens during the line sweep
    //the number of times that a coord is in the map
    //determines how many times that coord has to be excluded
    //before the coord is "fully" removed from the set
    //old Cow to exclude has coords xold and yold
    void exclude(long xold, long yold) {
        if (--xmap[xold] == 0)
            xset.erase(xold);

        if (--ymap[yold] == 0) {
            yset.erase(yold);
        }
    }

    //returns the area of the field
    long long area() {
        if (xset.empty() || yset.empty()) return 0;
        //rbegin() - begin() difference is the coord range of the set -- multiply xset and yset ranges for area
        return (*xset.rbegin() - *xset.begin()) * (*yset.rbegin() - *yset.begin()); 
    }
};

int main()
{
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    long n;
    cin >> n; 
    vector<Cow> cows(n);
    Field leftField, rightField, topField, bottomField; // left+right for x scan, top+bottom for y scan
    for (long i=0; i<n; i++) {
        cin >> cows[i].x >> cows[i].y;
        //initialize fields -- will start as one field containing all Cows for each scan
        rightField.include(cows[i].x, cows[i].y);
        topField.include(cows[i].x, cows[i].y);
    }
    long long oneFieldArea = rightField.area(); //area if only one field used    
    long long savedArea = -1; //amt of area saved by using two fields

    //this is the left to right x scan
    sort(cows.begin(), cows.end(), xcmp);
    for(long i=0; i<n; i++) {
        //go through each point, switching the rectangle it is in
        leftField.include(cows[i].x, cows[i].y);
        rightField.exclude(cows[i].x, cows[i].y);
        //incase the fields share an edge (which isn't allowed), skip
        if(*leftField.xset.rbegin() == *rightField.xset.begin()) continue;
        long long newArea = leftField.area() + rightField.area();
        long long diffArea = oneFieldArea - newArea;
        savedArea = max(savedArea , diffArea);
    }

    //this is the bottom to top y scan
    sort(cows.begin(), cows.end(), ycmp);
    for(long i=0; i<n; i++) {
        bottomField.include(cows[i].x, cows[i].y);
        topField.exclude(cows[i].x, cows[i].y);
        //incase the fields share an edge (which isn't allowed), skip
        if(*bottomField.yset.rbegin() == *topField.yset.begin()) continue;
        long long newArea = topField.area() + bottomField.area();
        long long diffArea = oneFieldArea - newArea;
        savedArea = max(savedArea , diffArea);
    }
    cout << savedArea << endl;
    return 0;
}

/*
SUMMARY
* use a scanning method to line sweep from left to right and top to bottom
* basic complete search all the possible 2 field configs
* over all of these configs, keep a running max of the total amt saved
* make sure to account for fields that share edges -- and skip over these configs
* NOTE this solution shows that naming vars well can greatly help readability later
* NOTE the helpful use of structs (esp Field struct) with methods to decrease complexity and increase abstraction
*/