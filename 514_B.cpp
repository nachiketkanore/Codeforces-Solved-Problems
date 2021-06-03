#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <map>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e3 + 3;

int num[N], den[N], par[N], comps;

int find(int u) {
	if (u == par[u])
		return u;
	par[u] = find(par[par[u]]);
	return par[u];
}

void unite(int u, int v) {
	u = find(u), v = find(v);
	if (u == v)
		return ;
	--comps;
	par[u] = v;
}

bool chk(int i, int j) {
	return (num[i] * den[j]) == (num[j] * den[i]);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, x0, y0;
	cin >> n >> x0 >> y0;

	FOR (i,1,n) {
		int x, y;
		cin >> x >> y;
		num[i] = x - x0;
		den[i] = y - y0;
		par[i] = i;
	}

	comps = n;

	FOR (i,1,n) FOR (j,i,n) if (chk(i, j)) unite(i, j);

	cout << comps;	
}