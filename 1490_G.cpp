/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 06 April 2021 11:49:32 AM IST
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

const int inf = 1e18;
const int N = 5e5 + 5;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<pair<int,int>> pref;

	int M = -inf;
	F0R (i,n) {
		cin >> a[i];
		if (i) a[i] += a[i-1];
		if (pref.empty() || pref.back().first < a[i])
			pref.push_back({a[i], i});
		cmax(M, a[i]);
	}
	assert(is_sorted(ALL(pref)));
	assert(pref.back().first == M);
	int S = a[n-1];
	see(pref);

	while (m--) {
		int x;
		cin >> x;
		if (x <= M) {
			int idx = lower_bound(ALL(pref), make_pair(x, int(0))) - pref.begin();
			cout << pref[idx].second << ' ';
		} else if (S <= 0) {
			cout << "-1 ";
		} else {
			int full_rots = (x - M + S - 1) / S;
			int rem = x - full_rots * S;
			int idx = lower_bound(ALL(pref), make_pair(rem, int(0))) - pref.begin();
			assert(idx < sz(pref));
			int partial = pref[idx].second;
			cout << (full_rots * n + partial) << ' ';
		}
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
