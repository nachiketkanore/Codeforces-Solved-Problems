/**
 *	Author: Nachiket Kanore
 *	Created: Monday 05 April 2021 06:21:59 PM IST
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
	int n;
	cin >> n;
	vector<int> tag(n), s(n), dp(n);
	for (int &x : tag) cin >> x;
	for (int &x : s) cin >> x;
	for (int i = 0; i < n; i++) {
		for (int j = i-1; ~j; j--) {
			if (tag[i]^tag[j]) {
				int e = abs(s[i] - s[j]);
				int dpi = dp[i];
				int dpj = dp[j];
				cmax(dp[j], dpi + e);
				cmax(dp[i], dpj + e);
			}
		}
	}
	int ans = 0;
	F0R (i,n) cmax(ans, dp[i]);
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
