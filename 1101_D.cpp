/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 10:17:55 PM IST
(ツ) You cannot change anything in your life with intention alone, which can become a watered-down, occasional hope that you'll get to tomorrow. Intention without action is useless.
*/
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 2e5 + 5;
int n, a[N], spf[N+1], answer, dist[N];
vector<pair<int,int>> G[N];
vector<int> GG[N];

int dfs(int u, int par = -1, int dep = 1) {
	dist[u] = dep;
	int farthest = u;
	for (int v : GG[u]) {
		if (v ^ par) {
			int next_farthest = dfs(v, u, dep+1);
			if (dist[next_farthest] > dist[farthest])
				farthest = next_farthest;
		}
	}
	return farthest;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 2; i <= N; i++) if (!spf[i]) {
		for (int j = i; j <= N; j += i)
			spf[j] = i;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 1) answer = 1;
	}
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v; --u, --v;
		int val = __gcd(a[u], a[v]);
		while (val > 1) {
			int p = spf[val];
			while (val % p == 0) val /= p;
			G[p].emplace_back(u, v);
		}
	}
	for (int p = 1; p < N; p++) {
		for (auto [u, v] : G[p]) {
			GG[u].push_back(v);
			GG[v].push_back(u);
			dist[u] = dist[v] = 0;
		}
		for (auto [u, v] : G[p]) {
			if (!dist[u]) 
				answer = max(answer, dist[dfs(dfs(u))]);
		}
		for (auto [u, v] : G[p]) {
			GG[u].clear();
			GG[v].clear();
		}
	}
	cout << answer << '\n';
}
