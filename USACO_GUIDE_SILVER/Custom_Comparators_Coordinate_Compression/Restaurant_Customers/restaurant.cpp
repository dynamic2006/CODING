#include <bits/stdc++.h>
using namespace std;

class Time {
public:
  int t, i;
  Time(int t, int i) {
    this->t = t;
    this->i = i;
  }
  ~Time() { cout << "destructed"; }
};

bool cmp(const Time *x, const Time *y) { return x->t < y->t; }

int main() {
  int n, arrival, leave;
  cin >> n;
  vector<Time*> times;
  for (int i = 0; i < n; i++) {
    cin >> arrival >> leave;
    Time *a = new Time(arrival, 1);
    Time *b = new Time(leave, -1);
    times.push_back(a);
    times.push_back(b);
  }
  sort(times.begin(), times.end(), cmp);

  int cur = 0;
  int max_ppl = 0;
  for (Time *x : times) {
    cur += (x->i);
    max_ppl = max(cur, max_ppl);
  }
  cout << max_ppl;
}

// Lol getting back into c++ is lowkey kinda hard
// anyways
// relearning how to do pointer stuffs
// note that &reference and *pointer can be used interchangeably... i think...
// see you in the next one!