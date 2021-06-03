/**
 *	Author: Nachiket Kanore
 *	Created: Saturday 01 May 2021 11:31:25 AM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <queue>
#include <cstring>
#include <chrono>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;
using namespace std::chrono;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

struct starter{
	high_resolution_clock::time_point t1, t2;
	starter() {
		ios::sync_with_stdio(0); cin.tie(0);
		t1 = high_resolution_clock::now();
	}
	~starter() {
		t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		cerr << "It took " << time_span.count() << " seconds.";
	}
} starter_;

const int inf = 1e18;
const int N = 5e5 + 5;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n+1);
	vector<int> depth(n+1);
	vector<int> vis(n+1);
	F0R (i,n-1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	depth[1] = 1;
	queue<int> Q;
	Q.push(1);
	while (sz(Q)) {
		int u = Q.front();
		Q.pop();
		vis[u] = 1;
		for (int v : g[u]) {
			if (!vis[v]) {
				depth[v] = depth[u] + 1;
				Q.push(v);
			}
		}
	}
	double ans = 0;
	FOR (i,1,n) ans += 1. / depth[i];
	printf("%0.12f\n", ans);
}

int32_t main() {
	solve();
}
