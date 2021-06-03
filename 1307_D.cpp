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
 
const int N = 2e5 + 5, inf = 1e12;

int n, m, k;
int a[N];
vector<int> g[N];
int to1[N], toN[N];

void SSSP(int source, int dist[]) {
	FOR (i,1,n) dist[i] = inf;
	dist[source] = 0;
	queue<int> Q;
	Q.push(source);
	while (!Q.empty()) {
		int curr = Q.front();	Q.pop();
		for (int nxt : g[curr]) 
			if (dist[nxt] > dist[curr]+1) {
				dist[nxt] = dist[curr]+1;
				Q.push(nxt);
			}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;	
	FOR (i,1,k) cin >> a[i];
	FOR (i,1,m) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	SSSP(1, to1);
	SSSP(n, toN);

	assert(to1[n] == toN[1]);

	FOR (i,1,n) see(i, to1[i]);

	sort(a+1, a+k+1, [&](int i, int j) {
		return to1[i]-toN[i] < to1[j]-toN[j];
	});

	// Now maximize to1[u] + toN[v] + 1
	// for i < j, u = a[i], v = a[j]

	int ans = 0;
	int best = -inf;

	for (int i = 1; i <= k; i++) {
		cmax(ans, toN[a[i]] + best + 1);
		cmax(best, to1[a[i]]);
	}

	cmin(ans, to1[n]);
	cout << ans << "\n";
}