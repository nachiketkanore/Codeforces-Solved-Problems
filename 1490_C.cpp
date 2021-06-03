/*
Author: Nachiket Kanore
Created: Wednesday 17 February 2021 10:08:00 PM IST
(ツ) Life is the flower for which love is the honey.
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

void solve() {
	int x;	cin >> x;
	for (int a = 1; ; a++) {
		int one = a * a * a;
		if (one > x) break;
		int b = x - one;
		int c = cbrt(b);
		if (c > 0 && (c * c * c) == b) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T = 1;
	cin >> T;
	while (T--)
		solve();
}
