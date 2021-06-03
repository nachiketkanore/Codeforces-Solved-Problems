/*
Author: Nachiket Kanore
Created: Tuesday 27 October 2020 04:46:55 PM IST
(ツ) Reviewing what you have learned and learning anew, you are fit to be a teacher.
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
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 200 + 5, inf = 1e18;

string s;
int n, dp[N];

bool ok(int L, int R) {
	int at = -1;
	FOR(i,L,R) if (s[i] == '@') { at = i; break; }
	
	if (at == -1) return false;

	int len = 0;
	FOR(i,L,at-1) {
		len++;
		if (s[i] == '@') return false;
	}
	if (len == 0) return false;
	len = 0;

	FOR(i,at+1,R) {
		len++;
		if (s[i] == '@') return false;
	}
	return len > 0;
}

int go(int from) {
	if (from == n)
		return 1;
	int &ans = dp[from];
	if (~ans)
		return ans;
	ans = 0;

	for (int to = from; to < n; to++)
		if (ok(from, to))
			ans |= go(to + 1);
	return ans;
}

void trace(int from) {
	if (from == n)
		return ;

	for (int to = from; to < n; to++)
		if (ok(from, to) && go(to + 1)) {
			FOR(i,from,to) cout << s[i];
			if (to + 1 == n) cout << "\n";
			else cout << ",";
			return trace(to + 1);			
		}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> s;
	n = sz(s);

	memset(dp, -1, sizeof(dp));
	int ans = go(0);
	if (ans) trace(0);
	else cout << "No solution\n";
}
