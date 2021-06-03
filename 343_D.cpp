#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(mt_rng); }

template<int D, typename T> struct vec : public vector<vec<D - 1, T>> {
	static_assert(D >= 1, "Dimensions invalid");
	template<typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, const T& val = T()) : vector<T>(n, val) {} };

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int N = 5e5 + 5;

class node {
public:
	static const int inf = 1e9;
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
			lazy[u*2] = lazy[u];
			lazy[u*2 + 1] = lazy[u]; 
		}

		// Updating the range [L, R] with lazy[u]
		{
			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			st[u].sum = (R-L+1) * lazy[u];
			st[u].mx = lazy[u];
			st[u].mn = lazy[u];
		}
		cLazy[u] = 0;
		lazy[u] = 0;
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
};


int n;
vector<int> g[N];
int tin[N], tout[N], timer = 0;

void dfs(int u, int par) {
	tin[u] = ++timer;
	for (int v : g[u]) if (v ^ par) dfs(v, u);
	tout[u] = timer;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	FOR (i,1,n) {
		if (i > 1) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);	g[v].pb(u);
		}
	}

	dfs(1,1);

	segtree fill, empty;
	fill.init(n);
	empty.init(n);


	int Q;	cin >> Q;
	FOR(q,1,Q) {
		int T;	cin >> T;
		int u;	cin >> u;
		if (T == 1) {
			fill.update(tin[u], tout[u], q);
		} else if (T == 2) {
			empty.update(tin[u], q);
		} else {
			int whenRoot = fill.query(tin[u]).mx;
			int latestInSubtree = empty.query(tin[u], tout[u]).mx;
			if (whenRoot > latestInSubtree) cout << "1\n";
			else cout << "0\n";
		}
	}
}