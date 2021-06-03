/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 17 March 2021 06:53:35 PM IST
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
const int N = 105;
int n, m, answer;
char mat[N][N];
bool vis[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
bool inside(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}
void go(int i, int j) {
	if (!inside(i,j) || mat[i][j]^'B' || vis[i][j]) return;
	vis[i][j] = true;
	F0R(k,4) go(i+dx[k], j+dy[k]);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR (i,1,n) FOR (j,1,m) cin >> mat[i][j];
	FOR (i,1,n) FOR (j,1,m) 
		if (mat[i][j]^'.' && !vis[i][j]) 
			++answer, go(i, j);
	cout << answer << '\n';
}
