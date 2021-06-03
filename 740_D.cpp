/**
 *	Author: Nachiket Kanore
 *	Created: Saturday 29 May 2021 04:49:32 PM IST
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

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 2e5 + 5, LOG = 20;

int n, a[N], dep[N], par[LOG][N], ans[N], pref[N], parent[N];
vector<pair<int,int>> g[N];

void dfs1(int u = 1, int p = 1, int dist = 0) {
	dep[u] = dist;
	par[0][u] = p;
	FOR (d,1,LOG-1) {
		par[d][u] = par[d-1][par[d-1][u]];
	}
	for (auto [to, w] : g[u]) {
		if (p^to) {
			dfs1(to, u, dist + w);
		}
	}
}

void dfs2(int u = 1, int p = 1) {
	for (auto [to, w] : g[u]) {
		if (p^to) {
			dfs2(to, u);
			pref[u] += pref[to];
		}
	}
}

int32_t main() {
	cin >> n;
	FOR (i,1,n) cin >> a[i];
	FOR (i,2,n) {
		int p, w;
		cin >> p >> w;
		parent[i] = p;
		g[p].push_back(make_pair(i, w));
	}
	dfs1();
	auto good = [&](int u, int v) {
		return dep[u] - dep[v] <= a[u];
	};
	FOR (u,1,n) {
		int curr = u;
		for (int d = LOG-1; d >= 0; d--) {
			int v = par[d][curr];
			if (good(u, v)) {
				curr = v;
			}
		}
		see(curr, u);
		if (curr == u) continue;
		pref[parent[u]]++;
		curr = parent[curr];
		if (curr) pref[curr]--;
	}
	FOR (i,1,n) see(i, pref[i]);
	dfs2();
	FOR (i,1,n) cout << pref[i] << " \n"[i==n];
}
