/*
Author: Nachiket Kanore
Created: Friday 26 February 2021 06:28:18 PM IST
(ツ) Take things as they are. Punch when you have to punch. Kick when you have to kick.
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

void solve() {
	int n;	cin >> n;
	int ans = -1;
	for (int i = 1; ; i++) {
		int req = i * (i + 1) / 2;
		if (n >= req) n -= req, ans = i;
		else break;
	}
	assert(~ans);
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T = 1; while (T--) solve();
}
