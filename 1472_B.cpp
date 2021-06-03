/*
Author: Nachiket Kanore
Created: Monday 04 January 2021 07:48:22 PM IST
(ツ) Learning without reflection is a waste, reflection without learning is dangerous.
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

int n, sum, a[N];
bool dp[102][202];
bool vis[102][202];

int go(int id, int rem) {
	if (rem < 0) return 0;
	if (id == n+1) return rem == 0;
	if (vis[id][rem]) return dp[id][rem];
	vis[id][rem] = true;
	int ans = 0;
	ans |= go(id+1, rem);
	ans |= go(id+1, rem - a[id]);
	dp[id][rem] = ans;
	return ans;
}

void solve() {
	cin >> n;
	sum = 0;
	FOR (i,1,n) {
		cin >> a[i];
		sum += a[i];
	}
	FOR (i,1,n) FOR (j,0,sum) vis[i][j] = false;
	if (sum & 1) {
		cout << "NO\n";
	} else {
		sum >>= 1;
		cout << (go(1,sum) ? "YES\n" : "NO\n");
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) solve();
}
