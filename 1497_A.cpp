/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 17 March 2021 08:04:46 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
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

void solve() {
	int n;	cin >> n;
	std::vector<int> c(101);
	FOR (i,1,n) {
		int u;	cin >> u;
		c[u]++;
	}
	FOR (i,0,100) {
		if (c[i] > 0) {
			c[i]--;
			cout << i << ' ';
		}
	}
	FOR (i,0,100) {
		while (c[i] > 0) {
			c[i]--;
			cout << i << ' ';
		}
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
