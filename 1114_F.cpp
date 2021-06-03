/*
Author: Nachiket Kanore
Created: Monday 08 March 2021 01:13:53 PM IST
(ツ) Wherever a man turns he can find someone who needs him.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <bitset>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
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

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 4e5 + 5, mod = 1e9 + 7;
int n, q, a[N], val_mask[301];
vector<int> primes;

int power(int a, int b, int mod){
    int ret = 1;
    a %= mod;
    while(b > 0){
        if(b % 2)
            ret = ret * a % mod;
        b /= 2;
        a = a * a % mod;
    }
    return ret;
}

class node {
public:
	static const int inf = 1e18;
	int prod, primes_mask;

	node(int prod_, int primes_mask_) {
		prod = prod_;
		primes_mask = primes_mask_;
	}

	node() {
		prod = 1;
		primes_mask = 0;
	}
};

struct segtree {
	int N;
	vector<node> st;
	vector<bool> cLazy;
	vector<node> lazy;

	void init(int n) {
		N = n;
		st.resize((N<<2)+2);
		cLazy.assign((N<<2)+2, false);
		lazy.resize((N<<2)+1);
		build(1,1,N);
	}

	//Write reqd merge functions
	void merge(node &ret, node &left, node &right) {
		ret.prod = (left.prod * right.prod) % mod;
		ret.primes_mask = left.primes_mask | right.primes_mask;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int u, int L, int R) {
		// Propagate down?
		if (L != R) {
			cLazy[u*2] = 1;
			cLazy[u*2 + 1] = 1;

			// Default range update operation is :
			// adding lazy[u] to all elements in range [...]
			lazy[u*2].prod = lazy[u*2].prod * lazy[u].prod % mod;
			lazy[u*2].primes_mask |= lazy[u].primes_mask;
			lazy[u*2 + 1].prod = lazy[u*2 + 1].prod * lazy[u].prod % mod;
			lazy[u*2 + 1].primes_mask |= lazy[u].primes_mask;
		}

		// Updating the range [L, R] with lazy[u]
		{
			st[u].prod = (st[u].prod * power(lazy[u].prod, R - L + 1, mod)) % mod;
			st[u].primes_mask |= lazy[u].primes_mask;
		}
		cLazy[u] = 0;
		lazy[u] = node();
	}

	void build (int u, int L, int R) {
		if(L == R) {
			// Leaf value
			st[u] = node(a[L], val_mask[a[L]]);
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
			lazy[u] = node(val, val_mask[val]);
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
			lazy[u] = node(val, val_mask[val]);
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



bool checkPrime(int n){
	if(n < 2)
		return false;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	FOR (i,1,n) cin >> a[i];
	FOR (i,1,300) if (checkPrime(i)) primes.push_back(i);
	FOR (val,1,300) {
		for (int i = 0; i < sz(primes); i++) {
			if (val % primes[i] == 0) {
				val_mask[val] |= (1LL << i);
			}
		}
	}
	T.init(n);
	while (q--) {
		string type;	cin >> type;
		if (type[0] == 'T') {
			int L, R;	cin >> L >> R;
			node get = T.query(L, R);
			see(L, R, get.prod, bitset<10>(get.primes_mask));
			int ans = get.prod % mod;
			for (int i = 0; i < sz(primes); i++) {
				if (get.primes_mask >> i & 1LL) {
					see(primes[i]);
					int mul = (primes[i] - 1) * power(primes[i], mod - 2, mod) % mod;
					ans = (ans * mul) % mod;
				}
			}
			cout << ans << '\n';
		} else {
			int L, R, x;	cin >> L >> R >> x;
			T.update(L, R, x);
		}
	}
}
