/*
Author: Nachiket Kanore
Created: Tuesday 23 February 2021 06:44:38 PM IST
(ツ) Your worst enemy cannot harm you as much as your own unguarded thoughts.
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

int n, t, dp[102][10];

int go(int id, int mod) {
	if (id == n+1) 
		return (mod == 0 ? 1 : 0);
	int &ans = dp[id][mod];
	if (~ans) return ans;
	ans = 0;
	for (int dig = (id==1); dig <= 9; dig++) {
		ans |= go(id+1, (mod * 10 + dig) % t);
	}
	return ans;
}

void trace(int id, int mod) {
	if (id == n+1) {
		assert(mod == 0);
		return;
	}
	int ans = go(id, mod);
	assert(ans);
	for (int dig = (id==1); dig <= 9; dig++) {
		if (go(id+1, (mod * 10 + dig) % t)) {
			cout << dig;
			return trace(id+1, (mod * 10 + dig) % t);
		}
	}
}

void solve() {
	cin >> n >> t;
	memset(dp, -1, sizeof(dp));
	if (go(1,0)) {
		trace(1,0);
	} else {
		cout << "-1\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T = 1; while (T--) solve();
}
