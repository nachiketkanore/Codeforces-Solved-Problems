/*
Author: Nachiket Kanore
Created: Wednesday 24 February 2021 06:27:46 PM IST
(ツ) To avoid criticism, do nothing, say nothing, be nothing.
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

const int inf = 1e18, offset = 400;
int n, m, maxLen, maxBal;
string A, B;
int dp[210][210][410];

int go(int i, int j, int bal) {
	if (bal < 0) return inf;
	if (bal > maxBal) return inf;
	if (i >= n && j >= m) {
		if (bal == 0) return 0;
		int &ans = dp[i][j][bal];
		if (~ans) return ans;
		ans = inf;
		for (char ch : "()") {
			int get = 1 + go(n, m, bal + (ch == '(' ? +1 : -1));
			cmin(ans, get);
		}
		return ans;
	}
	int &ans = dp[i][j][bal];
	if (~ans) return ans;
	ans = inf;
	if (i >= n) {
		for (char ch : "()") {
			int get = 1 + go(n, j + (B[j] == ch), bal + (ch == '(' ? +1 : -1));
			cmin(ans, get);
		}
		return ans;
	}
	if (j >= m) {
		for (char ch : "()") {
			int get = 1 + go(i + (A[i] == ch), m, bal + (ch == '(' ? +1 : -1));
			cmin(ans, get);
		}
		return ans;
	}
	for (char ch : "()") {
		int get = 1 + go(i + (ch==A[i]), j + (ch==B[j]), bal + (ch == '(' ? +1 : -1));
		cmin(ans, get);
	}
	return ans;
}

string answer;

void trace(int i, int j, int bal) {
	if (bal < 0) assert(false);
	if (bal > maxBal) assert(false);
	if (i >= n && j >= m) {
		if (bal == 0) return ;
		int ans = go(i, j, bal);
		for (char ch : "()") {
			int get = 1 + go(n, m, bal + (ch == '(' ? +1 : -1));
			if (get == ans) {
				answer += ch;
				return trace(n, m, bal + (ch == '(' ? +1 : -1));
			}
		}
		assert(false);
	}
	int ans = go(i, j, bal);
	see(i, j, bal, ans);
	if (i >= n) {
		for (char ch : "()") {
			int get = 1 + go(n, j + (B[j] == ch), bal + (ch == '(' ? +1 : -1));
			if (ans == get) {
				answer += ch;
				return trace(n, j + (B[j] == ch), bal + (ch == '(' ? +1 : -1));
			} else see("1", ans, get);
		}
	}
	if (j >= m) {
		for (char ch : "()") {
			int get = 1 + go(i + (A[i] == ch), m, bal + (ch == '(' ? +1 : -1));
			if (ans == get) {
				answer += ch;
				return trace(i + (A[i] == ch), m, bal + (ch == '(' ? +1 : -1));
			} else see("2", ans, get);
		}
	}
	for (char ch : "()") {
		int get = 1 + go(i + (ch==A[i]), j + (ch==B[j]), bal + (ch == '(' ? +1 : -1));
		see(ans, get);
		if (ans == get) {
			answer += ch;
			return trace(i + (ch==A[i]), j + (ch==B[j]), bal + (ch == '(' ? +1 : -1));
		} else see("3", i, j, ans, get);
	}
	see("END");
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> A >> B;
	n = sz(A);
	m = sz(B);
	maxLen = 405;
	maxBal = 205;
	memset(dp, -1, sizeof(dp));
	int best = go(0, 0, 0);
	see(best);
	assert(best % 2 == 0);
	trace(0, 0, 0);
	assert(sz(answer) == best);
	cout << answer << '\n';
}
