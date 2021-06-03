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

#define int long long
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
 

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int SZ = sqrt(N) + 1;

int n, Q;
int col[N], a[N];
vector<int> g[N];
int cnt;

struct data {
	int l, r, idx;
	int cnt;
}qr[N];

int freq[N];
int cntFreq[N];
long long ans[N];
long long cur = 0;

bool comp(struct data &d1, struct data &d2)
{
	int b1 = d1.l / SZ;
	int b2 = d2.l / SZ;
	if(b1 != b2)
		return b1 < b2;
	else
		return (b1 & 1) ? d1.r < d2.r : d1.r > d2.r;
}

inline void add(int x)
{	
	freq[x]++;
	cntFreq[freq[x]]++;
}

inline void remove(int x)
{
	cntFreq[freq[x]]--;
	freq[x]--;
}

void mo()
{
	sort(qr + 1, qr + Q + 1, comp);
	int l = 1, r = 0;
	cur = 0;
	for(int i=1;i<=Q;i++)
	{
		cnt = qr[i].cnt;
		while(l < qr[i].l) remove(a[l++]);
		while(l > qr[i].l) add(a[--l]);
		while(r < qr[i].r) add(a[++r]);
		while(r > qr[i].r) remove(a[r--]);
		ans[qr[i].idx] = cntFreq[cnt];
	}
}

int tin[N], tout[N], timer = 0;

void dfs(int u, int par) {
	tin[u] = ++timer;
	for (int v : g[u]) if (v ^ par) dfs(v, u);
	tout[u] = timer;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> Q;

	FOR (i,1,n) {
		cin >> col[i];
	}

	FOR (i,2,n) {
		int u, v;	cin >> u >> v;
		g[u].pb(v);	g[v].pb(u);
	}

	dfs(1,1);

	FOR (i,1,n) {
		a[tin[i]] = col[i];
	}

	FOR (i,1,Q) {
		int u, tot;
		cin >> u >> tot;
		qr[i].l = tin[u];
		qr[i].r = tout[u];
		qr[i].idx = i;
		qr[i].cnt = tot;
	}

	mo();

	FOR (i,1,Q) {
		cout << ans[i] << "\n";
	}
}