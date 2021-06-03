/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 12:21:21 AM IST
(ツ) Sometimes the biggest act of courage is a small one.
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
 
const int N = 2e5 + 5, inf = 1e18;

int n, a[N], dp[2][N];

int go(int id, int who) {
	if (id >= n) return 0;
	int &ans = dp[who][id];
	if (~ans) return ans;
	ans = inf;
	int hard = 0;
	for (int j = id; j < min(n, id+2); j++) {
		hard += a[j];
		int req = (who == 0 ? hard : 0);
		req += go(j+1, who^1);
		ans = min(ans, req);
	}
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < 2; j++) {
			dp[j][i] = -1;
		}
	}
	int answer = go(0,0);
	cout << answer << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T = 1;
	cin >> T;
	while (T--)
		solve();
}
