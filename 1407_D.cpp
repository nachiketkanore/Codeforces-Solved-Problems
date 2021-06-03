#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 3e5 + 5, inf = 1e18;

int n, h[N];
vector<int> g[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	FOR(i,1,n)	cin >> h[i];	

	stack<int> stk;

	for (int i = n; i >= 1; i--) {	// next >=
		while (!stk.empty() && h[stk.top()] < h[i])
			stk.pop();
		if (stk.size())
			g[i].push_back(stk.top());
		stk.push(i);
	}

	while (!stk.empty()) stk.pop();

	for (int i = n; i >= 1; i--) {	// next <= 
		while (!stk.empty() && h[stk.top()] > h[i])
			stk.pop();
		if (stk.size())
			g[i].push_back(stk.top());
		stk.push(i);
	}

	while (!stk.empty()) stk.pop();

	for (int i = 1; i <= n; i++) {	// prev >=
		while (!stk.empty() && h[stk.top()] < h[i])
			stk.pop();
		if (stk.size())
			g[stk.top()].push_back(i);
		stk.push(i);
	}

	while (!stk.empty()) stk.pop();

	for (int i = 1; i <= n; i++) {	// prev <= 
		while (!stk.empty() && h[stk.top()] > h[i])
			stk.pop();
		if (stk.size())
			g[stk.top()].push_back(i);
		stk.push(i);
	}

	vector<int> dp(n + 1, inf);
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int to : g[i]) {
			dp[to] = min(dp[to], 1 + dp[i]);
		}
	}
	cout << dp[n];
}