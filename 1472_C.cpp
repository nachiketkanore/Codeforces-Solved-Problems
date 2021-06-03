/*
Author: Nachiket Kanore
Created: Monday 04 January 2021 08:20:18 PM IST
(ツ) Whoso loves, believes the impossible.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int N = 2e5 + 5, inf = 1e18;

int n, a[N];
std::vector<int> g[N];
bool vis[N];
int ans;

void dfs(int u, int par, int val) {
	cmax(ans, val);
	if (vis[u]) return;
	vis[u] = true;
	for (int v : g[u]) if (v != par) dfs(v, u, val + a[v]);
}

void solve() {
	cin >> n;
	
	g[0].clear();
	vis[0] = false;
	FOR (i,1,n) {
		cin >> a[i];
		g[i].clear();
		vis[i] = false;
	}

	FOR (i,1,n) {
		if (i + a[i] <= n) {
			g[i].push_back(i + a[i]);
		}
		g[0].push_back(i);
	}

	ans = 0;
	dfs(0, 0, 0);
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;	while (T--) solve();
}
