/*
Author: Nachiket Kanore
Created: Tuesday 09 February 2021 07:25:29 PM IST
(ツ) Experience is simply the name we give our mistakes.
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
 
const int N = 1e5 + 5, inf = 1e18;

int n, a[N];
int dp1[N], dp2[N];

int goLeft(int id) {
	if (id < 1) return 0;
	int &ans = dp1[id];
	if (~ans) return ans;
	ans = 1;
	if (id - 1 > 0 && a[id - 1] < a[id]) ans += goLeft(id - 1);
	return ans;
}

int goRight(int id) {
	if (id > n) return 0;
	int &ans = dp2[id];
	if (~ans) return ans;
	ans = 1;
	if (id + 1 <= n && a[id + 1] > a[id]) ans += goRight(id + 1);
	return ans;
}

void solve() {
	cin >> n;
	FOR (i,1,n) cin >> a[i];
	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));

	int ans = 0;
	FOR (i,1,n) {
		cmax(ans, goLeft(i));
		cmax(ans, 1 + goLeft(i - 1));
	}
	FOR (i,1,n) {
		cmax(ans, goRight(i));
		cmax(ans, 1 + goRight(i + 1));
	}

	FOR (i,2,n-1) {
		if (a[i - 1] < a[i + 1] && (a[i + 1] - a[i - 1]) >= 2) {
			cmax(ans, goLeft(i - 1) + 1 + goRight(i + 1));
		}
	}	
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T = 1;
	while (T--)
		solve();
}
