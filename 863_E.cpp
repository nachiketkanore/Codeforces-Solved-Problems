/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 02:42:09 PM IST
(ツ) When we seek to discover the best in others, we somehow bring out the best in ourselves.
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

class node {
public:
	static const int inf = 1e18;
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

struct segtree {
	int N;
	vector<node> st;
	vector<bool> cLazy;
	vector<int> lazy;

	void init(int n) {
		N = n;
		st.resize((N<<2)+2);
		cLazy.assign((N<<2)+2, false);
		lazy.assign((N<<2)+2, 0);
		build(1,1,N);
	}

	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = left.sum + right.sum;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int u, int L, int R) {
		// Propagate down?
		if (L != R) {
			cLazy[u*2] = 1;
			cLazy[u*2 + 1] = 1;

			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			lazy[u*2] += lazy[u];
			lazy[u*2 + 1] += lazy[u]; 
		}

		// Updating the range [L, R] with lazy[u]
		{
			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			st[u].sum += (R-L+1) * lazy[u];
			st[u].mx += lazy[u];
			st[u].mn += lazy[u];
		}
		cLazy[u] = 0;
		lazy[u] = 0;
	}

	void build (int u, int L, int R) {
		if(L == R) {
			// Leaf value
			st[u] = node(0, 0, 0);
			return;
		}
		int M = (L + R)/2;
		build(u*2, L, M);
		build(u*2 + 1, M + 1, R);
		merge(st[u], st[u*2], st[u*2+1]);
	}

	node Query(int u, int L, int R, int i, int j) {
		if(cLazy[u])
			propagate(u, L, R);
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
		if(cLazy[u])
			propagate(u, L, R);
		if(L == R)
			return st[u];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(u*2, L, M, pos);
		else
			return pQuery(u*2 + 1, M + 1, R, pos);
	}	

	void Update(int u, int L, int R, int i, int j, int val) {
		if (cLazy[u])
			propagate(u, L, R);
		if (j<L || i>R)
			return;
		if (i<=L && R<=j) {
			// Default range update operation is :
			// adding val to all elements in range [...]
			cLazy[u] = 1;
			lazy[u] = val;
			propagate(u, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(u*2, L, M, i, j, val);
		Update(u*2 + 1, M + 1, R, i, j, val);
		merge(st[u], st[u*2], st[u*2 + 1]);
	}

	void pUpdate(int u, int L, int R, int pos, int val) {
		if(cLazy[u])
			propagate(u, L, R);
		if(L == R) {
			cLazy[u] = 1;
			lazy[u] = val;
			propagate(u, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(u*2, L, M, pos, val);
		else
			pUpdate(u*2 + 1, M + 1, R, pos, val);
		merge(st[u], st[u*2], st[u*2 + 1]);
	}

	node query(int pos) { return pQuery(1, 1, N, pos); }

	node query(int l, int r) { return Query(1, 1, N, l, r); }

	void update(int pos, int val) { pUpdate(1, 1, N, pos, val); }

	void update(int l, int r, int val) { Update(1, 1, N, l, r, val); }
} T;


int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;	cin >> n;
	vector<int> L(n), R(n);
	vector<int> all;
	for (int i = 0; i < n; i++) {
		cin >> L[i] >> R[i];
		all.push_back(L[i]);
		all.push_back(R[i]);
		all.push_back(R[i]+1);
	}
	T.init(1000000);
	sort(ALL(all));
	vector<int> nall;
	for (int x : all) if (nall.empty() || nall.back() != x) nall.push_back(x);
	all = nall;
	for (int i = 0; i < n; i++) {
		L[i] = lower_bound(ALL(all), L[i])- all.begin() + 1;
		R[i] = lower_bound(ALL(all), R[i])- all.begin() + 1;
		T.update(L[i], R[i], 1);
	}
	for (int i = 0; i < n; i++) {
		int howMany = T.query(L[i], R[i]).mn;
		if (howMany > 1) {
			cout << i+1 << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}
