/**
 *	Author: Nachiket Kanore
 *	Created: Friday 16 April 2021 04:32:35 PM IST
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

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

void solve() {
	int n;
	cin >> n;
	vector<string> mat(n+1);
	vector<pair<int,int>> pos;
	FOR (i,1,n) {
		cin >> mat[i];
		mat[i] = " " + mat[i];
		FOR (j,1,n) {
			if (mat[i][j] == '*') pos.push_back({i, j});
		}
	}
	assert(sz(pos) == 2);
	auto [x1, y1] = pos.front();
	auto [x2, y2] = pos.back();

	auto inside = [&](int i, int j) {
		return i >= 1 && i <= n && j >= 1 && j <= n;
	};

	if (x1 == x2) {
		if (inside(x1 + 1, y1) && inside(x2 + 1, y2)) {
			mat[x1 + 1][y1] = mat[x2 + 1][y2] = '*';
		} else if (inside(x1 - 1, y1) && inside(x2 - 1, y2)) {
			mat[x1 - 1][y1] = mat[x2 - 1][y2] = '*';
		}
	} else if (y1 == y2) {
		if (inside(x1, y1 + 1) && inside(x2, y2 + 1)) {
			mat[x1][y1 + 1] = mat[x2][y2 + 1] = '*';
		} else if (inside(x1, y1 - 1) && inside(x2, y2 - 1)) {
			mat[x1][y1 - 1] = mat[x2][y2 - 1] = '*';
		}
	} else {
		mat[x1][y2] = mat[x2][y1] = '*';
	}
	FOR (i,1,n) FOR (j,1,n) {
		cout << mat[i][j];
		if (j == n) cout << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
