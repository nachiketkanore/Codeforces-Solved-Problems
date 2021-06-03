/**
 *	Author: Nachiket Kanore
 *	Created: Sunday 11 April 2021 08:03:46 PM IST
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
	int n, k;
	cin >> n >> k;
	int want = k;
	vector<int> a(n+2);
	vector<int> vals;
	FOR (i,1,n) vals.push_back(i);
	for (int i = 2; i < n; i += 2) {
		if (k > 0) {
			k--;
			a[i] = vals.back();
			vals.pop_back();
		}
	}
	reverse(ALL(vals));
	FOR (i,1,n) if (!a[i]) {
		a[i] = vals.back();
		vals.pop_back();
	}
	FOR (i,2,n-1) if (a[i-1] < a[i] && a[i] > a[i+1]) --want;
	if (k > 0 || want != 0) {
		cout << "-1\n";
	} else {
		FOR (i,1,n) cout << a[i] << " \n"[i==n];
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
