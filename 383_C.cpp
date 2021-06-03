/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 06:11:26 PM IST
(ツ) Arriving at one point is the starting point to another.
*/
#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m, tim = 0;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> a(n), tin(n), tout(n), depth(n);
	vector<vector<int>> BIT (2, vector<int> (n+1));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;	--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	function<void(int,int,int)> dfs = [&](int u, int par, int d) {
		depth[u] = d;
		tin[u] = ++tim;
		for (int v : g[u]) if (v ^ par) dfs(v, u, d+1);
		tout[u] = tim;
	};
	dfs(0,0,0);
	auto update = [&](int which, int id, int add) {
		while (id <= n) {
			BIT[which][id] += add;
			id += id & -id;
		}
	};
	auto get = [&](int which, int id) {
		int ret = 0;
		while (id >= 1) {
			ret += BIT[which][id];
			id -= id & -id;
		}
		return ret;
	};
	while (m--) {
		int type;	cin >> type;
		if (type == 1) {
			int u, add;
			cin >> u >> add;	--u;
			int d = depth[u] % 2;
			update(d, tin[u], add);
			update(d, tout[u]+1, -add);
			update(d^1, tin[u], -add);
			update(d^1, tout[u]+1, add);
		} else {
			int u;	cin >> u;	--u;
			int d = depth[u] % 2;
			int answer = a[u] + get(d, tin[u]);
			cout << answer << '\n';
		}
	}
}
