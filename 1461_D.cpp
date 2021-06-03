/*
Author: Nachiket Kanore
Created: Tuesday 16 March 2021 03:23:09 PM IST
(ツ) Fame usually comes to those who are thinking about something else.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <map>
#include <cstring>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
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

const int N = 1e6 + 5, inf = 1e18;
int n, q, a[N], sum[N+1];
map<int,bool> poss;

int get_sum(int mn, int mx) {
	assert(mn <= mx && mx <= N);
	return sum[mx] - sum[mn-1];
}

void go(int mn, int mx) {
	while (get_sum(mn, mn) == 0) ++mn;
	while (get_sum(mx, mx) == 0) --mx;
	if (mn > mx) return;
	see(mn, mx);
	if (mn == mx) {
		int curr = get_sum(mn, mx);
		poss[curr] = true;
		return;
	}
	int curr = get_sum(mn, mx);
	poss[curr] = true;
	int mid = (mn + mx) / 2;
	if (get_sum(mn, mid) > 0)	go(mn, mid);
	if (get_sum(mid+1, mx) > 0)	go(mid+1, mx);
}

void solve() {
	FOR (i,1,N) sum[i] = 0;
	poss.clear();
	int mn = inf, mx = -inf;
	cin >> n >> q;
	FOR (i,1,n) {
		cin >> a[i];
		cmin(mn, a[i]);
		cmax(mx, a[i]);
		sum[a[i]] += a[i];
	}
	FOR (i,1,N) sum[i] += sum[i-1];
	go(mn, mx);
	while (q--) {
		int s;	cin >> s;
		if (poss.count(s)) cout << "Yes\n";
		else cout << "No\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}