/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 01:14:13 PM IST
(ツ) While we try to teach our children all about life, our children teach us what life is all about.
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
 
const int N = 1e5 + 5, inf = 1e18;

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

// Default tasks
// Point assignment with range queries
struct segtree {
	int N;
	vector<node> st;
	void init(int n) {
		N = n;
		st.resize((N<<2)+2);
		build(1,1,N);
	}

	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.mn = min(left.mn, right.mn);
		ret.mx = max(left.mx, right.mx);
		ret.sum = left.sum + right.sum;
	}

	void build (int u, int L, int R) {
		if(L == R) {
			// Leaf value
			st[u] = node(0,0,0);
			return;
		}
		int M = (L + R)/2;
		build(u*2, L, M);
		build(u*2 + 1, M + 1, R);
		merge(st[u], st[u*2], st[u*2+1]);
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

	node query(int pos) { return pQuery(1, 1, N, pos); }

	node query(int l, int r) { return Query(1, 1, N, l, r); }

	void update(int pos, int val) { pUpdate(1, 1, N, pos, val); }
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;	++k;
	vector<int> a(n+1);
	vector<vector<int>> dp(n+1, vector<int> (k+1));
	vector<segtree> sumOfDPs(k+1);
	FOR (i,0,k) sumOfDPs[i].init(n);
	FOR (i,1,n) cin >> a[i];
	int answer = 0;
	FOR (i,1,n) {
		dp[i][1] = 1; 
		FOR (len,2,k) {
			dp[i][len] = sumOfDPs[len-1].query(1, a[i]-1).sum;
		}
		FOR (len,1,k) {
			sumOfDPs[len].update(a[i], dp[i][len]);
		}
		answer += dp[i][k];
	}
	cout << answer << '\n';
}
