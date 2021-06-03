/*
Author: Nachiket Kanore
Created: Tuesday 23 February 2021 09:03:39 PM IST
(ツ) Parents can only give good advice or put them on the right paths, but the final forming of a persons character lies in their own hands.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <map>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

int n, k;
string s;
vector<string> ans;

void solve() {
	cin >> k >> s;
	n = sz(s);
	vector<bool> used(26, false);
	string curr;
	for (char ch : s) {
		if (!used[ch-'a']) {
			if (sz(curr)) ans.push_back(curr);
			curr.clear();
			curr += ch;
			used[ch-'a'] = true;
		} else {
			curr += ch;
		}
	}
	if (sz(curr)) ans.push_back(curr);
	while (sz(ans) > k) {
		ans[sz(ans) - 2] += ans[sz(ans) - 1];
		ans.pop_back();
	}
	if (sz(ans) != k) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (const string &p : ans)
			cout << p << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T = 1; while (T--) solve();
}
