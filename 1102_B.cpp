/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 12 May 2021 12:38:06 PM IST
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
const int N = 5e5 + 5;

int32_t main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> cnt(5001);
	vector<int> a(n);
	int mx = 0;
	F0R (i,n) {
		cin >> a[i];
		cnt[a[i]].push_back(i);
		cmax(mx, sz(cnt[a[i]]));
	}
	if (mx > k) cout << "NO\n";
	else {
		cout << "YES\n";
		vector<int> colors(k);
		vector<int> ans(n);
		F0R (i,k) colors[i] = i + 1;
		int id = 0;
		F0R (i,5001) {
			while (sz(cnt[i])) {
				ans[cnt[i].back()] = colors[id];
				id = (id + 1) % k;
				cnt[i].pop_back();
			}
		}
		F0R (i,n) cout << ans[i] << " \n"[i == n-1];
	}
}
