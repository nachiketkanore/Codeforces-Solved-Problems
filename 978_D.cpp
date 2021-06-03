/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 11 May 2021 05:55:23 PM IST
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

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 1e5 + 5;

int n, diff;
int a[N];
int dp[3][N];

int go(int id, int prev) {
	if (id == n + 1) return 0;
	int hash = 0;
	if (prev == a[id] - 1) hash = 0;
	if (prev == a[id]) hash = 1;
	if (prev == a[id] + 1) hash = 2;
	int &ans = dp[hash][id];
	if (~ans) return ans;
	ans = inf;
	FOR (val,a[id]-1,a[id]+1) {
		if (val - prev == diff) {
			int cost = (val != a[id]) + go(id + 1, val);
			cmin(ans, cost);
		}
	}
	return ans;
}

int32_t main() {
	cin >> n;
	if (n == 1) {
		cout << "0\n";
		return 0;
	}
	FOR (i,1,n) cin >> a[i];

	int ans = inf;

	FOR (val1,a[1]-1,a[1]+1) {
		FOR (val2,a[2]-1,a[2]+1) {
			::diff = val2 - val1;
			memset(dp, -1, sizeof(dp));
			int req = (a[1] != val1) + (a[2] != val2) + go(3, val2);
			cmin(ans, req);
		}
	}
	if (ans >= inf) ans = -1;
	cout << ans << '\n';
}
