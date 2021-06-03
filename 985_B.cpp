/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 17 March 2021 07:11:38 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
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
const int N = 2005;
int n, m, mat[N][N], col_sum[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR (i,1,n) {
		FOR (j,1,m) {
			char ch;	cin >> ch;
			mat[i][j] = (int)(ch-'0');
			col_sum[j] += mat[i][j];
		}
	}
	bool found = false;
	FOR (row,1,n) {
		// remove
		FOR (j,1,m) col_sum[j] -= mat[row][j];
		
		bool ok = true;
		FOR (j,1,m) ok &= col_sum[j] > 0;
		// restore
		FOR (j,1,m) col_sum[j] += mat[row][j];

		found |= ok;
	}
	cout << (found ? "YES\n" : "NO\n");
}
