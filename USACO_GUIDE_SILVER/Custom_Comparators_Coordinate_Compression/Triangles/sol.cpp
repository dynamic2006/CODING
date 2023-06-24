#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
const int MOD = 1e9 + 7;
const int MAX_C = 1e4;

struct Fence {
	int x;
	int y;
	// terminology: anchor point = vertex of the right angle in a right triangle
	// sum of heights of all triangles that use this fence as an anchor point
	long long heightsum;
	// sum of the bases of all triangles that use this fence as an anchor point
	long long basesum;
};

Fence fences[MAX_N];
// all possible x coordinates of the fences (+1 to account for 0)
vector<pair<int, int>> xcoords[2 * MAX_C + 1];
// all possible y coordinates of the fences
vector<pair<int, int>> ycoords[2 * MAX_C + 1];

int main() {
	freopen("triangles.in" , "r" , stdin);
    //freopen("triangles.out" , "w" , stdout);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> fences[i].x >> fences[i].y;
		// we add MAX_C to make all of our coordinates positive
		// so that we won't have negative indices
		xcoords[fences[i].x + MAX_C].push_back({fences[i].y, i});
		ycoords[fences[i].y + MAX_C].push_back({fences[i].x, i});
	}

	for (int i = 0; i <= 2 * MAX_C; i++) {
		if (xcoords[i].size() > 0) {
			// cur is the value of the current s_i
			long long curr = 0;
			// sort all y positions of all points w/ the same x pos
			sort(xcoords[i].begin(), xcoords[i].end());
			/*
			 * then we compute the value s_1 of this set:
			 * the sum of the heights of all the triangles that
			 * have their anchor point at (i, xcoords[i][0].first)
			 */
			for (int j = 1; j < xcoords[i].size(); j++) {
				curr += xcoords[i][j].first - xcoords[i][0].first;
			}
			fences[xcoords[i][0].second].heightsum = curr;
			// then we compute the rest of the s_i for this set
			for (int j = 1; j < xcoords[i].size(); j++) {
				curr += (2 * j - xcoords[i].size())
						* (xcoords[i][j].first - xcoords[i][j - 1].first);
				fences[xcoords[i][j].second].heightsum = curr;
			}
		}
	}

	// we do the sums of bases in exactly the same way
	for (int i = 0; i <= MAX_C * 2; i++) {
		if (ycoords[i].size() > 0) {
			long long curr = 0;
			sort(ycoords[i].begin(), ycoords[i].end());
			for (int j = 1; j < ycoords[i].size(); j++) {
				curr += ycoords[i][j].first - ycoords[i][0].first;
			}
			fences[ycoords[i][0].second].basesum = curr;
			for (int j = 1; j < ycoords[i].size(); j++) {
				curr += (2 * j - ycoords[i].size())
						* (ycoords[i][j].first - ycoords[i][j - 1].first);
				fences[ycoords[i][j].second].basesum = curr;
			}
		}
	}

	long long total_area = 0;
	for (int i = 0; i < n; i++) {
		if(i == 39999){cout << fences[i].heightsum << " " << fences[i].basesum << endl;}
		total_area += fences[i].heightsum * fences[i].basesum % MOD;
		total_area %= MOD;
	}
	cout << total_area << '\n';
}