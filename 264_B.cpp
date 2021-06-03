/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 12:27:46 AM IST
(ツ) I destroy my enemies when I make them my friends.
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
 
const int N = 1e5, inf = 1e18;

int n, a[N], dp[N+1], spf[N+1];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	spf[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (!spf[j])
				spf[j] = i;
		}
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int answer = 0;
	for (int i = 0; i < n; i++) {
		int val = a[i];
		int best = 0;
		while (val > 1) {
			best = max(best, dp[spf[val]]);
			val /= spf[val];
		}
		best = best + 1;
		answer = max(answer, best);
		val = a[i];
		while (val > 1) {
			dp[spf[val]] = max(dp[spf[val]], best);
			val /= spf[val];
		}
	}
	cout << answer << '\n';
}
