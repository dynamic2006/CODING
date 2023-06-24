#include <bits/stdc++.h>
using namespace std;

struct Cow
{
    int id, x, y; int blame = 0; string dir; bool stopped = false;
    Cow(int id, int x, int y, string dir){
        this->id = id; this->x = x; this->y = y; this->dir = dir;
    }
};

bool cmp(Cow& a, Cow& b){
    if(a.dir == "E")
        return (a.y < b.y);
    return (a.x < b.x);
}

bool sorter(Cow& a, Cow& b){
    return(a.id > b.id);
}

int main()
{
    //freopen("stuck_rut.in" , "r" , stdin);
    
    int n; cin >> n;
    vector<Cow> n_cows;
    vector<Cow> e_cows;
    string d; int start_x, start_y;
    for(int i=0; i<n; i++){
        cin >> d >> start_x >> start_y;
        Cow cur_cow = Cow(i, start_x, start_y, d);
        if(d == "E"){e_cows.push_back(cur_cow);}
        else{n_cows.push_back(cur_cow);}
    }

    sort(n_cows.begin() , n_cows.end() , cmp);
    sort(e_cows.begin() , e_cows.end() , cmp);

    for(Cow& north_cow : n_cows){
        if(north_cow.stopped){continue;}
        for(Cow& east_cow : e_cows){
            if(east_cow.stopped){continue;}
            int x_diff = north_cow.x - east_cow.x;
            int y_diff = east_cow.y - north_cow.y;
            if(x_diff > 0 && y_diff > 0){
                if(x_diff > y_diff){north_cow.blame += east_cow.blame + 1; east_cow.stopped = true;} //north cow stops east cow
                else if(x_diff < y_diff){east_cow.blame += north_cow.blame + 1; north_cow.stopped = true; break;} //east cow stops north cow
            }
        }
    }

    sort(n_cows.begin() , n_cows.end() , sorter);
    sort(e_cows.begin() , e_cows.end() , sorter);

    for(int i=0; i<n; i++){
        if(n_cows[n_cows.size() - 1].id == i){cout << n_cows[n_cows.size() - 1].blame << endl; n_cows.pop_back();}
        else{cout << e_cows[e_cows.size() - 1].blame << endl; e_cows.pop_back();}
    }
}