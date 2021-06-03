/*
Author: Nachiket Kanore
Created: Monday 08 March 2021 04:23:25 PM IST
(ツ) If the stars should appear but one night every thousand years how man would marvel and adore.
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

const int N = 1e5 + 5, LOG = 21;
int n, a[N], b[N], m;

class node {
public:
	static const int inf = 1e18;
	int sum;

	node(int _sum) {
		sum = _sum;
	}

	node() {
		sum = 0;
	}
};

struct segtree {
	int N;
	vector<node> st;
	vector<int> cLazy;

	void init(int n) {
		N = n;
		st.resize((N<<2)+2);
		cLazy.assign((N<<2)+2, false);
		build(1,1,N);
	}

	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.sum = left.sum + right.sum;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int u, int L, int R) {
		// Propagate down?
		if (L != R) {
			cLazy[u*2] ^= 1;
			cLazy[u*2 + 1] ^= 1;
		}

		st[u].sum = (R-L+1) - st[u].sum;
		cLazy[u] = 0;
	}

	void build (int u, int L, int R) {
		if(L == R) {
			// Leaf value
			st[u] = node(b[L]);
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

	void Update(int u, int L, int R, int i, int j) {
		if (cLazy[u])
			propagate(u, L, R);
		if (j<L || i>R)
			return;
		if (i<=L && R<=j) {
			// Default range update operation is :
			cLazy[u] = 1;
			propagate(u, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(u*2, L, M, i, j);
		Update(u*2 + 1, M + 1, R, i, j);
		merge(st[u], st[u*2], st[u*2 + 1]);
	}

	node query(int l, int r) { return Query(1, 1, N, l, r); }

	void update(int l, int r) { Update(1, 1, N, l, r); }
} T[LOG+1];


int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR (i,1,n) cin >> a[i];
	FOR (bit,0,LOG) {
		FOR (i,1,n) b[i] = a[i] >> bit & 1;
		T[bit].init(n);
	}
	cin >> m;
	while (m--) {
		int type, L, R, x;
		cin >> type >> L >> R;
		if (type == 1) {
			int ans = 0;
			FOR (bit,0,LOG) {
				ans += T[bit].query(L, R).sum * (1LL << bit);
			}
			cout << ans << '\n';
		} else {
			cin >> x;
			FOR (bit,0,LOG) {
				if (x >> bit & 1LL) {
					T[bit].update(L, R);
				}
			}
		}
	}
}