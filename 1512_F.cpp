/**
 *	Author: Nachiket Kanore
 *	Created: Friday 16 April 2021 05:52:06 PM IST
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

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n), b(n-1);
	F0R (i,n) cin >> a[i];
	F0R (i,n-1) cin >> b[i];

	int ans = inf;
	int have = 0;
	int days_to_come_here = 0;
	F0R (i,n) {
		int end_here = (c - have + a[i] - 1) / a[i];
		if (end_here < 0) end_here = 0;
		cmin(ans, days_to_come_here + end_here);
		if (i < n-1) {
			int here = (b[i] - have + a[i] - 1) / a[i];
			have += here * a[i];
			assert(have >= b[i]);
			have -= b[i];
			days_to_come_here += here + 1;
		}
	}
	assert(ans ^ inf);
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
