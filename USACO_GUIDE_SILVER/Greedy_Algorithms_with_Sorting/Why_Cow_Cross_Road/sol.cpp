#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int,int> pii;

multiset<int> chickens;
vector<pii> cows;
int C, N;

int main(void)
{
  freopen("helpcross.in" , "r" , stdin);

  cin >> C >> N;
  int x, y, total=0;
  for (int i=0; i<C; i++) { cin >> x; chickens.insert(x); }
  for (int i=0; i<N; i++) { cin >> x >> y; cows.push_back(pii(y,x)); }
  sort (cows.begin(), cows.end());
  for (int j=0; j<N; j++) {
    auto which_chicken = chickens.lower_bound(cows[j].second);
    if (which_chicken != chickens.end() && *which_chicken <= cows[j].first) {
        cout << *which_chicken << " ";
        total++;
        chickens.erase(which_chicken);
    }
  }
  cout << endl;
  cout << total << "\n";
  return 0;
}