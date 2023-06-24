#include <bits/stdc++.h>
using namespace std;

const int INF = (int) 1e9;
int maximum = -INF;

int op(int num1, int num2, int type)
{
    switch (type) {
		case 1:
			return num1 + num2;
		case 2:
			return num1 - num2;
		case 3:
			return num1 * num2;
		case 4: {
			// The divisor cannot be 0 and the quotient must be a whole number.
			if (num2 == 0 || num1 % num2) {
				return -INF;
			}
			return num1 / num2;
		}
	}
	return -INF;
}

void find(int a, int b, int c, int d)
{
    for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            for(int k=1; k<=4; k++)
            {
                int res1 = op(op(op(a,b,i) , c , j) , d , k);
                int res2 = op(op(a,b,i) , op(c,d,j) , k);
                if(res1 > res2 && res1 <= 24)
                    maximum = max(res1, maximum);
                else if(res2 <= 24)
                    maximum = max(res2, maximum);
            }
        }
    }
}

int main()
{
    freopen("twentyfour.in", "r" , stdin);
    freopen("twentyfour.out", "w" , stdout);
    int n; cin >> n;
    int temp;

    for(int i=0; i < n; i++)
    {
        vector<int> cards(4);
        for(int j=0; j<4; j++)
        {
            cin >> temp;
            cards[j] = temp;
        }
        sort(cards.begin() , cards.end());
        do
        {
            find(cards[0] , cards[1] , cards[2] , cards[3]);
        }while(next_permutation(cards.begin() , cards.end()));

        cout << maximum << endl;
        maximum = 0;
    }
}
