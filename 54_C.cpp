/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 12 May 2021 02:43:57 PM IST
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

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 1000 + 5;

int n, L[N], R[N], k;
double prob[N];
string s;
int dp[2][2][20];

int go(int id, int small_taken, int started) {
	if (id == sz(s)) return started;
	int &ans = dp[small_taken][started][id];
	if (~ans) return ans;
	ans = 0;
	int from = 0, to = 0;
	if (small_taken) to = 9;
	else to = s[id]-'0';
	if (!started) to = 1;
	FOR (dig,from,to) {
		int curr = s[id]-'0';
		ans += go(id + 1, small_taken || (dig < curr), started || (dig > 0));
	}
	return ans;
}

int get_count(int upto) {
	// count numbers in range [1, upto] with MSB = 1
	if (upto == 0) return 0;
	s = to_string(upto);
	memset(dp, -1, sizeof(dp));
	int ret = go(0, 0, 0);
	return ret;
}

double dp2[N][N];
bool vis[N][N];

double solve(int id, int cnt) {
	if (id == n + 1) {
		if (100 * cnt >= k * n) return 1.;
		return 0.;
	}
	if (vis[id][cnt]) return dp2[id][cnt];
	vis[id][cnt] = 1;
	double &ans = dp2[id][cnt];
	ans = 0;
	ans += solve(id + 1, cnt + 1) * prob[id];
	ans += solve(id + 1, cnt) * (1. - prob[id]);
	return ans;
}

int32_t main() {
	cin >> n;
	FOR (i,1,n) {
		cin >> L[i] >> R[i];
		int cnt = get_count(R[i]) - get_count(L[i] - 1);
		prob[i] = 1. * cnt / (R[i] - L[i] + 1);
		see(L[i], R[i], prob[i]);
	}
	cin >> k;
	double ans = solve(1, 0);
	printf("%0.12f\n", ans);
}