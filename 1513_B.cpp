/**
 *	Author: Nachiket Kanore
 *	Created: Monday 12 April 2021 12:07:09 AM IST
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
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	int all;
	cin >> all;
	vector<int> a{all};
	F0R (i,n-1) {
		int u;
		cin >> u;
		a.push_back(u);
		all &= u;
	}
	int cnt_all = count(ALL(a), all);
	int ans = cnt_all * (cnt_all - 1) % MOD;
	FOR (i,1,n-2) (ans *= i) %= MOD;
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
