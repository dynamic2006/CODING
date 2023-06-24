#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
	int n, m; cin >> n >> m;
 
	vector<string> inputs(m);
	vector<char> outputs(m);
 
	// if tcPassed[i] is true, then the program we have generated
	// so far gives the right answer for the i'th test case.
	// if tcPassed is true for every test case we're given,
	// then we know that Elsie isn't lying.
	vector<bool> tcPassed(m, false);
 
	// Read in input
	for (int i = 0; i < m; i++) {
		cin >> inputs[i] >> outputs[i];
	}
 
	// Repeatedly add one more "if" statement to our program
	// until every test case gives the right answer
	while (true) {
		bool foundIfStatement = false;
 
		for (int bit = 0; bit < n; bit++) {
			if (foundIfStatement) break;
			for (int val = 0; val <= 1; val++) {
				if (foundIfStatement) break;
				for (int output = 0; output <= 1; output++) {
					if (foundIfStatement) break;
					// try the following if statement:
					// if (input[bit] == val) return output;
 
					bool consistent = true;
					bool atLeastOneInput = false;
					for (int tc = 0; tc < m; tc++) {
						// ignore test cases that are covered by
						// previous if statements
						if (tcPassed[tc]) continue;
 
						// check if inputs[tc] satisfies the if statement
						if (inputs[tc][bit] == '0' + val) {
							atLeastOneInput = true;
							// if the expected output for inputs[tc]
							// is not the same as `output`, then
							// the if statement we generated won't work
							if (outputs[tc] != '0' + output) {
								consistent = false;
							}
						}
					}
 
					// if this if statement works, mark all the inputs
					// that the if statement covers as passed
					if (consistent && atLeastOneInput) {
						foundIfStatement = true;
						for (int tc = 0; tc < m; tc++) {
							if (tcPassed[tc]) continue;
							if (inputs[tc][bit] == '0' + val) {
								tcPassed[tc] = true;
							}
						}
					}
				}
			}
		}
 
		if (!foundIfStatement) break;
	}
 
	// Check if every test case is passed
	bool ok = true;
	for (int i = 0; i < m; i++) {
		if (tcPassed[i] == false) {
			ok = false;
		}
	}
	if (ok) {
		cout << "OK" << endl;
	} else {
		cout << "LIE" << endl;
	}
}
 
int main() {
	int t; cin >> t;
	while (t--) solve();
 
	return 0;
}