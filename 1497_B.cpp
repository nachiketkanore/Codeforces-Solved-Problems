/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 17 March 2021 08:11:57 PM IST
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
const int N = 1e5 + 5;
int cnt[N];

void solve() {
	int n, m;	cin >> n >> m;
	std::vector<int> a(n);
	for (int &x : a) {
		cin >> x;
		cnt[x % m]++;
	}
	int ans = 0;
	F0R (mod,m) {
		if (mod == 0) ans += cnt[mod] > 0, cnt[mod] = 0;
		else {
			int one = mod;
			int two = m - mod;
			if (!cnt[one] && !cnt[two]) continue;
			if (one == two) {
				++ans;
				cnt[one] = cnt[two] = 0;
				continue;
			}
			if (cnt[one] == cnt[two]) {
				++ans;
				cnt[one] = cnt[two] = 0;
			} else if (cnt[one] > cnt[two]) {
				++ans;
				cnt[one] -= cnt[two] + 1;
				cnt[two] = 0;
			} else {
				++ans;
				cnt[two] -= cnt[one] + 1;
				cnt[one] = 0;
			}
		}
	}
	FOR (mod,1,m-1) ans += cnt[mod];
	cout << ans << '\n';
	for (int &x : a) {
		cnt[x % m] = 0;
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
