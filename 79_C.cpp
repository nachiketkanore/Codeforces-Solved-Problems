/*
Author: Nachiket Kanore
Created: Friday 20 November 2020 03:48:58 PM IST
(ツ) Let your hook always be cast; in the pool where you least expect it, there will be a fish.
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
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5 + 5, inf = 1e18;

int n;
int bestUpto[N];

struct segtree{
	int *tree;

	void build(int u, int tl, int tr) {
		if (tl == tr)
			tree[u] = bestUpto[tl];
		else {
			int mid = (tl+tr) >> 1;
			build(2*u, tl, mid);
			build(2*u + 1, mid + 1, tr);
			tree[u] = min(tree[2*u], tree[2*u + 1]);
		}
	}

	void init(int nn) {
		tree = new int[nn * 4];
		build(1, 1, nn);
	}

	int getMin(int tl, int tr, int u, int ql, int qr) {
		if (tl > tr || ql > qr) return inf;
		if (tl == ql && tr == qr)	return tree[u];
		int mid = (tl+tr) >> 1;
		return min( getMin(tl, mid, 2*u, ql, min(mid, qr)),
					getMin(mid+1, tr, 2*u + 1, max(ql, mid+1), qr));
	}

} T;

int getMin(int L, int R) {
	assert(L <= R);
	return T.getMin(1, n, 1, L, R);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s;
	cin >> s;
	s = "@" + s;
	int m;
	cin >> m;

	vector<string> strs(m);
	for (auto& str : strs) 
		cin >> str;

	n = s.size()-1;

	for (int i = 1; i <= n; i++) {
		bestUpto[i] = inf;
		for (int j = 0; j < m; j++) {
			int len = sz(strs[j]);
			if (i+len-1 > n) continue;
			bool keep = true;
			for (int k = 0; k < len; k++)
				keep &= s[i+k] == strs[j][k];
			if (keep)
				bestUpto[i] = min(bestUpto[i], i+len-1);
		}
	}

	T.init(n);

	int bestLen = 0, start = 0;

	FOR (i,1,n) {
		int L = i;
		int R = -1;
		// finding the best R
		int lo = i, hi = n;
		while (lo <= hi) {
			int mid = (lo+hi) >> 1;
			int worst = getMin(L, mid);
			assert(worst >= L);
			if (worst > mid)
				R = mid, lo = mid+1;
			else
				hi = mid-1;
		}
		if (~R)
			if (bestLen < R-L+1)
				bestLen = R-L+1, start = L-1;
	}

	cout << bestLen << " " << start << "\n";
}
