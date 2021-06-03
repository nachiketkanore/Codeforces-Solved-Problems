/*
Author: Nachiket Kanore
Created: Thursday 21 January 2021 12:45:09 PM IST
(ツ) Nothing could be worse than the fear that one had given up too soon, and left one unexpended effort that might have saved the world.
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

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
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
 
const int N = 5000 + 5, inf = 5e8;

int n, a, b;
string s;
int dp[N][N], dp2[N], dp3[N][N];

int common(int i, int j) {
	if (j == n+1) return 0;
	int &ans = dp[i][j];
	if (~ans) return ans;
	ans = 0;
	if (s[i] == s[j]) 
		ans = 1 + common(i+1, j+1);
	return ans;
}

int range_max(int id, int from) {
	if (id < 1) return 0;
	int &ans = dp3[id][from];
	if (~ans) return ans;
	ans = max(common(id, from), range_max(id-1, from));
	return ans;
}

int go(int from) {
	if (from == n+1) return 0;
	int &ans = dp2[from];
	if (~ans) return ans;
	ans = inf;
	ans = min(ans, a + go(from+1));

	FOR (to,from,n) {
		int len = to - from + 1;
		if (len > from-1) break;
		
		int upto = from - len;
		int best = range_max(upto, from);
		if (best >= len) {
			see(from, s.substr(from, len));
			ans = min(ans, b + go(to+1));
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> a >> b >> s;	s = " " + s;
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));
	memset(dp3, -1, sizeof(dp3));

	FOR (i,1,n) FOR (j,i,n) common(i,j);

	int ans = go(1);
	cout << ans << '\n';
}
