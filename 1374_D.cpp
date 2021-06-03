/*
Author: Nachiket Kanore
Created: Tuesday 23 February 2021 06:24:16 PM IST
(ツ) Opportunity is missed by most because it is dressed in overalls and looks like work.
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
	int n, k;	cin >> n >> k;
	vector<int> a(n), want;
	for (int &x : a) {
		cin >> x;
		if (x % k) {
			int w = k - (x % k);
			assert(w > 0);
			want.push_back(w);
		}
	}
	if (!sz(want)) {
		cout << "0\n";
		return;
	}
	sort(ALL(want));
	int ans = 0;
	for (int i = 0; i < sz(want); ) {
		int j = i, cnt = 0, w = want[i];
		while (j < sz(want) && want[j] == want[i]) ++j, ++cnt;
		int done = 1, curr = w;
		while (done < cnt) {
			curr += k;
			done++;
		}
		cmax(ans, curr);
		i = j;
	}
	cout << ans+1 << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
