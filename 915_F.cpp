/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 07 April 2021 10:46:32 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
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
const int N = 1e6 + 5;

int n, val[N];
std::vector<pair<int,int>> edges;

struct DSU 
{	
	int par[N], rank[N];
	void init() {
		FOR (i,1,n) {
			par[i] = i;
			rank[i] = 1;
		}
	}
	int find(int u) {
		if (par[u] == u) return par[u];
		return par[u] = find(par[u]);
	}
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		assert(u^v);
		if (rank[u] < rank[v]) swap(u, v);
		rank[u] += rank[v];
		par[v] = u;
		return true;
	}
	int get_size(int u) {
		return rank[find(u)];
	}
};

int perform(const vector<array<int,3>> &e) {
	DSU dsu;
	dsu.init();
	int ret = 0;
	for (auto [w, u, v] : e) {
		ret += w * dsu.get_size(u) * dsu.get_size(v);
		assert(dsu.unite(u, v));
	}
	return ret;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR (i,1,n) cin >> val[i];
	edges.resize(n-1);
	for (auto &[u, v] : edges) cin >> u >> v;

	vector<array<int,3>> set_min, set_max;
	for (const auto &[u, v] : edges) {
		set_min.push_back({min(val[u], val[v]), u, v});
		set_max.push_back({max(val[u], val[v]), u, v});
	}
	sort(ALL(set_min));
	reverse(ALL(set_min));
	sort(ALL(set_max));
	int ans = perform(set_max) - perform(set_min);
	cout << ans << '\n';
}
