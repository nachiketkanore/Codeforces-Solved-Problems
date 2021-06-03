/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 12 May 2021 11:49:05 AM IST
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
const int N = 1e6 + 5;

int n;
int bal[N], min_pref[N], min_suff[N];
char s[N];

int32_t main() {
	cin >> n;
	FOR (i,1,n) {
		cin >> s[i];
		bal[i] = bal[i - 1] + (s[i] == '(' ? +1 : -1);
	}
	FOR (i,1,n) {
		if (i == 1) min_pref[i] = bal[i];
		else min_pref[i] = min(bal[i], min_pref[i - 1]);
	}
	for (int i = n; i; --i) {
		if (i == n) min_suff[i] = bal[i];
		else min_suff[i] = min(bal[i], min_suff[i + 1]);
	}
	int ans = 0;
	FOR (i,1,n) {
		int delta = (s[i] == '(' ? -2 : +2);
		int curr_bal = bal[i] + delta;
		if (curr_bal < 0) continue;
		int final_bal = bal[n] + delta;
		if (final_bal != 0) continue;
		if (min_pref[i - 1] < 0) continue;
		int smallest_suff = min_suff[i + 1] + delta;
		if (i == n) smallest_suff = 0;
		if (smallest_suff < 0) continue;
		++ans;
	}
	cout << ans << '\n';
}
