/*
Author: Nachiket Kanore
Created: Thursday 22 October 2020 03:15:12 PM IST
(ツ) Silence is a fence around wisdom.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1002, inf = 1e18;

int n, m, u[N], v[N];
std::vector<pair<int,int>> g[N];
int minDist[N][N];

void dijkstra(int s) {

	minDist[s][s] = 0;
	set<pair<int,int>> Q;
	Q.insert({0, s});

	while (!Q.empty()) {
		int curr = Q.begin()->second;
		Q.erase(Q.begin());

		for (auto [to, len] : g[curr]) {
			if (minDist[s][curr] + len < minDist[s][to]) {
				Q.erase({minDist[s][to], to});
				minDist[s][to] = minDist[s][curr] + len;
				Q.insert({minDist[s][to], to});
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int Q;
	cin >> n >> m >> Q;

	FOR (i,1,m) {
		cin >> u[i] >> v[i];
		int w;
		cin >> w;
		g[u[i]].push_back({v[i], w});
		g[v[i]].push_back({u[i], w});
	}

	FOR(i,1,n) {
		FOR(j,1,n) {
			minDist[i][j] = inf;
		}
	}

	FOR (i,1,n) {
		dijkstra(i);
	}

	FOR (i,1,n) FOR (j,1,n) {
		assert(minDist[i][j] == minDist[j][i]);
	}

	vector<pair<int,int>> queries;

	int ans = 0;

	FOR (i,1,Q) {
		int a, b;
		cin >> a >> b;
		ans += minDist[a][b];
		queries.push_back({a, b});
	}

	FOR (i,1,m) {
		int from = u[i], to = v[i];
		int cost = 0;

		for (auto [a, b] : queries) {
			int new_min = minDist[a][b];
			new_min = min(new_min, minDist[a][from] + minDist[to][b]);
			new_min = min(new_min, minDist[a][to] + minDist[b][from]);

			cost += new_min;
		}

		ans = min(ans, cost);
	}

	cout << ans << "\n";
}
