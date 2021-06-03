/**
 *	Author: Nachiket Kanore
 *	Created: Sunday 11 April 2021 08:20:55 PM IST
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
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
int becomes[10][N+1];

void solve() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	while (n) {
		(ans += becomes[n%10][m]) %= MOD;
		n /= 10;
	}
	cout << ans << '\n';
}

void pre() {
	F0R (d,10) {
		becomes[d][0] = 1;
		vector<int> cnt(10);
		cnt[d] = 1;
		FOR (ops,1,N) {
			vector<int> new_cnt(10);
			F0R (dig,10) {
				if (dig == 9) {
					(new_cnt[0] += cnt[dig]) %= MOD;
					(new_cnt[1] += cnt[dig]) %= MOD;
				} else {
					new_cnt[dig+1] += cnt[dig];
				}
			}
			cnt = new_cnt;
			F0R (dig,10) {
				cnt[dig] %= MOD;
				(becomes[d][ops] += cnt[dig]) %= MOD;
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	pre();
	int T; cin >> T; while (T--) solve();
}
