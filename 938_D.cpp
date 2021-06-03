/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 07 April 2021 09:50:34 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <set>
#include <cstring>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 2e5 + 5;

int n, m, dp[N];
vector<pair<int,int>> g[N];
multiset<pair<int,int>> Q;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR (i,1,m) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	FOR (i,1,n) {
		cin >> dp[i];
		Q.insert({dp[i], i});
	}
	while (!Q.empty()) {
		auto [dist, u] = *Q.begin();
		Q.erase(Q.begin());
		for (auto [v, w] : g[u]) {
			if (dp[v] > dp[u] + 2 * w) {
				Q.erase(Q.find({dp[v], v}));
				cmin(dp[v], dp[u] + 2 * w);
				Q.insert({dp[v], v});
			}
		}
	}
	FOR (i,1,n) cout << dp[i] << " \n"[i==n];
}
