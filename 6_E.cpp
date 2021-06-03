/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 11:38:35 PM IST
(ツ) Without passion man is a mere latent force and possibility, like the flint which awaits the shock of the iron before it can give forth its spark.
*/
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1e5 + 5;

int n, h[N];

//can be used for Range min/max/gcd range query in O(1)
class sparseTable{
    public:
        int RMQ[20][N];
        int RMQ2[20][N];
        int floorlog[N];

        void precompute(int n)
        {
            for(int i=0;(1<<i)<N;i++)
            {
                for(int j=(1<<i);j<N && j<(1<<(i+1)); j++)
                    floorlog[j]=i;
            }

            for(int i=n;i>=1;i--)
            {
                RMQ[0][i]=h[i]; //leaf value
                RMQ2[0][i]=h[i]; //leaf value
                int mxj=floorlog[n-i+1]; //2^j <= n-i+1
                int pw=1;
                for(int j=1;j<=mxj;j++)
                {
                    RMQ[j][i]=min(RMQ[j-1][i], RMQ[j-1][i+pw]); //operation
                    RMQ2[j][i]=max(RMQ2[j-1][i], RMQ2[j-1][i+pw]); //operation
                    pw<<=1;
                }
            }   
        }

        int getMin(int L, int R)
        {
            int k=floorlog[R-L+1]; //2^k <= R-L+1
            return min(RMQ[k][L], RMQ[k][R - (1<<k) +1]); //operation
        }

        int getMax(int L, int R)
        {
            int k=floorlog[R-L+1]; //2^k <= R-L+1
            return max(RMQ2[k][L], RMQ2[k][R - (1<<k) +1]); //operation
        }
} T;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	T.precompute(n);
	int maxLen = -1;
	for (int i = 1; i <= n; i++) {
		int lo = i, hi = n;
		int best = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (T.getMax(i, mid) - T.getMin(i, mid) <= k) {
				best = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		if (~best) {
			maxLen = max(maxLen, best - i + 1);
		}
	}
	assert(~maxLen);
	vector<pair<int,int>> subarrays;
	for (int i = 1; i <= n; i++) {
		int j = i + maxLen - 1;
		if (j <= n) {
			if (T.getMax(i, j) - T.getMin(i, j) <= k) {
				subarrays.emplace_back(i, j);
			}
		}
	}
	cout << maxLen << ' ' << (int)subarrays.size() << '\n';
	for (auto [L, R] : subarrays) {
		cout << L << ' ' << R << '\n';
	}
}
