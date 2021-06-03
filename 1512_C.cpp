/**
 *	Author: Nachiket Kanore
 *	Created: Friday 16 April 2021 06:07:24 PM IST
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

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

void solve() {
	int a, b;
	cin >> a >> b;
	int n = a + b;
	string s;
	cin >> s;
	assert(sz(s) == n);

	int ones = b, zeros = a;
	int lo = 0, hi = n - 1;
	while (lo < hi) {
		if (s[lo] != '?' && s[hi] != '?' && s[lo] == s[hi]) {
			if (s[lo] == '0') zeros -= 2;
			else ones -= 2;
		}
		lo++, hi--;
	}
	if (ones < 0 || zeros < 0) { cout << "-1\n"; return; }
	lo = 0, hi = n - 1;
	while (lo < hi) {
		if (s[lo] == '?' && s[hi] != '?') {
			if (s[hi] == '1') ones -= 2;
			else zeros -= 2;
			s[lo] = s[hi];
		} else if (s[lo] != '?' && s[hi] == '?') {
			if (s[lo] == '1') ones -= 2;
			else zeros -= 2;
			s[hi] = s[lo];
		}
		lo++, hi--;
	}
	if (ones < 0 || zeros < 0) { cout << "-1\n"; return; }

	lo = 0, hi = n - 1;
	while (lo < hi) {
		if (s[lo] ^ s[hi]) {
			cout << "-1\n";
			return;
		}
		if (s[lo] == '?') {
			if (ones >= 2) {
				ones -= 2;
				s[lo] = s[hi] = '1';
			} else if (zeros >= 2) {
				zeros -= 2;
				s[lo] = s[hi] = '0';
			} else {
				cout << "-1\n";
				return;
			}
		}
		lo++, hi--;
	}
	if (ones < 0 || zeros < 0) { cout << "-1\n"; return; }
	F0R (i,n) if (s[i] == '?') {
		if (ones > 0) {
			ones--;
			s[i] = '1';
		} else if (zeros > 0) {
			zeros--;
			s[i] = '0';
		} else {
			cout << "-1\n";
			return;
		}
	}
	see(ones, zeros, s);
	if (count(ALL(s), '0') != a || count(ALL(s), '1') != b) { cout << "-1\n"; return; }
	cout << s << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
