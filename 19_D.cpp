/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 16 March 2021 05:14:44 PM IST
**/

#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2")

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <cstring>

#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define FOR(i,R) for(int i = 0; i < (R); ++i)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 2e5 + 5, inf = 2e9;
int n, x[N], y[N];
char query[N];
vector<int> allx, unallx;
set<int> y_coordinates[N<<2];

class node {
public:
	static const int inf = 2e9;
	int mn, mx, sum;

	node(int _mn, int _mx, int _sum) {
		mn = _mn;
		mx = _mx;
		sum = _sum;
	}

	node() {
		mn = inf;
		mx = -inf;
		sum = 0;
	}
};

// Default tasks
// Point assignment with range queries
struct segtree {
	int N;
	vector<node> st;
	void init(int n) {
		N = n;
		st.resize((N<<2)+2);
	}

	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = left.sum + right.sum;
	}

	node Query(int u, int L, int R, int i, int j) {
		if(j<L || i>R)
			return node();
		if(i<=L && R<=j)
			return st[u];
		int M = (L + R)/2;
		node left = Query(u*2, L, M, i, j);
		node right = Query(u*2 + 1, M + 1, R, i, j);
		node ret;
		merge(ret, left, right);
		return ret;
	}

	node pQuery(int u, int L, int R, int pos) {
		if(L == R)
			return st[u];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(u*2, L, M, pos);
		else
			return pQuery(u*2 + 1, M + 1, R, pos);
	}	

	void pUpdate(int u, int L, int R, int pos, int val) {
		if(L == R) {
			// Point update
			// Update leaf value
			st[u] = node(val, val, val);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(u*2, L, M, pos, val);
		else
			pUpdate(u*2 + 1, M + 1, R, pos, val);
		merge(st[u], st[u*2], st[u*2 + 1]);
	}

	pair<int,int> get_best(int u, int tl, int tr, int ql, int asky) {
		if (tr < ql || st[u].mx <= asky) return {-1, -1};
		if (tl == tr) {
			auto it = y_coordinates[tl].upper_bound(asky);
			assert(it != y_coordinates[tl].end());
			return {tl, *it};
		}
		int mid = (tl + tr) >> 1;
		auto left = get_best(2*u, tl, mid, ql, asky);
		if (~left.first) return left;
		return get_best(2*u + 1, mid+1, tr, ql, asky);
	}

	node query(int pos) { return pQuery(1, 1, N, pos); }

	node query(int l, int r) { return Query(1, 1, N, l, r); }

	void update(int pos, int val) { pUpdate(1, 1, N, pos, val); }

	pair<int,int> descent(int l, int asky) { return get_best(1, 1, N, l, asky); }
} T;

void compress_x() {
	FOR (i,n) allx.push_back(x[i]);
	sort(ALL(allx));
	for (int xx : allx) {
		if (unallx.empty() || unallx.back() != xx) {
			unallx.push_back(xx);
		}
	}
	FOR (i,n) x[i] = lower_bound(ALL(unallx), x[i]) - unallx.begin() + 1;
	FOR (i,n) assert(1 <= x[i] && x[i] <= N);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	T.init(N);
	cin >> n;
	FOR (i,n) {
		string type;
		cin >> type >> x[i] >> y[i];
		query[i] = type[0];
	}
	compress_x();
	FOR (i,n) {
		if (query[i] == 'a') {
			y_coordinates[x[i]].insert(y[i]);
			T.update(x[i], *y_coordinates[x[i]].rbegin());
		} else if (query[i] == 'r') {
			y_coordinates[x[i]].erase(y[i]);
			if (y_coordinates[x[i]].empty())
				T.update(x[i], -1);
			else
				T.update(x[i], *y_coordinates[x[i]].rbegin());
		} else {
			int lo = x[i] + 1;
			auto [best_x, best_y] = T.descent(lo, y[i]);
			if (~best_x) {
				assert(~best_y);
				cout << unallx[best_x-1] << ' ' << best_y << '\n';;
			} else cout << "-1\n";
		}
	}
}
