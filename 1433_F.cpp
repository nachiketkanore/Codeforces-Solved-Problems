/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 01 June 2021 04:35:18 PM IST
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
const int N = 72;

int n, m, k, mat[N][N];
int dp[N][N][N][N];
bool vis[N][N][N][N];

// go(row, col, sum mod k, selected) = {
// 	max attainable sum
// 	from rows [row, n] and cols [col, m]
// 	sum mod k = 0
// 	selected (row) <= m / 2
// }
// sum mod k == 0, max(sum)
// selected (row) <= m / 2

int go(int row, int col, int sum, int selected) {

	if (col == m + 1) {
		if (selected <= m / 2) {
			return go(row + 1, 1, sum, 0);
		}
		return -inf;
	}

	if (row == n + 1) {
		if (sum == 0) return 0;
		return -inf;
	}

	if (vis[row][col][sum][selected])
		return dp[row][col][sum][selected];

	vis[row][col][sum][selected] = true;

	int &ans = dp[row][col][sum][selected];
	ans = -inf;

	int c1 = mat[row][col] + go(row, col + 1, (sum + mat[row][col]) % k, selected + 1);
	int c2 = 0 + go(row, col + 1, sum, selected);

	ans = max({ans, c1, c2});
	return ans;
}

int32_t main() {
	cin >> n >> m >> k;
	FOR (i,1,n) {
		FOR (j,1,m) {
			cin >> mat[i][j];
		}
	}
	int ans = go(1, 1, 0, 0);
	cout << ans << '\n';
}
