/*
Author: Nachiket Kanore
Created: Wednesday 17 February 2021 09:54:41 AM IST
(ツ) Your ability to learn faster than your competition is your only sustainable competitive advantage.
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
	int n;	cin >> n;
	vector<int> a(n);	for (int &x : a) cin >> x;
	sort(ALL(a));
	vector<int> f;
	for (int i = 0; i < n; ) {
		int j = i, c = 0;
		while (j < n && a[j] == a[i]) ++c, ++j;
		f.push_back(c);
		i = j;
	}
	sort(ALL(f));
	vector<int> nf;
	for (int x : f) if (nf.empty() || nf.back() != x) nf.push_back(x);
	int ans = inf;
	for (int c : nf) {
		int req = 0;
		for (int x : f) {
			if (x < c) req += x;
			else req += x - c;
		}
		cmin(ans, req);
	}
	assert(ans != inf);
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T = 1;
	cin >> T;
	while (T--)
		solve();
}
