/**
 *	Author: Nachiket Kanore
 *	Created: Sunday 04 April 2021 07:36:53 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)
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

const int N = 1e5 + 5;
int n, d, a[N];
bool vis[2][10][N];

using D = long double;
const D EPS = 1e-14;
const D inf = 1e9;
D dp[2][10][N];
std::vector<int> ret;

D go(int id, int mod, int taken) {
	if (id == n+1) {
		if (mod == d && taken) return 0;
		return -inf;
	}
	D& ans = dp[taken][mod][id];
	if (vis[taken][mod][id]) return ans;
	
	vis[taken][mod][id] = 1;
	ans = -inf;
	
	cmax(ans, log(a[id]) + go(id+1, (mod * a[id]) % 10, 1));
	cmax(ans, go(id+1, mod, taken));
	
	return ans;
}

void trace(int id, int mod, int taken) {
	if (id == n+1) {
		assert(mod == d && taken);
		return;
	}
	D ans = go(id, mod, taken);

	D get1 = log(a[id]) + go(id+1, (mod * a[id]) % 10, 1);

	if (abs(get1 - ans) < EPS) {
		ret.push_back(a[id]);
		return trace(id+1, (mod * a[id]) % 10, 1);
	}

	D get2 = go(id+1, mod, taken);
	if (abs(get2 - ans) < EPS) {
		return trace(id+1, mod, taken);
	}
	
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> d;
	FOR (i,1,n) cin >> a[i];
	D max_prod = go(1, 1, 0);
	see(max_prod);
	if (max_prod > 0.0) {
		trace(1, 1, 0);
		see("HERE1");
		assert(sz(ret));
		cout << sz(ret) << '\n';
		for (int val : ret) {
			cout << val << ' ';
		}
	} else {
		cout << "-1\n";
	}
}
