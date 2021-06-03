#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 502, mod = 1e9 + 7;

int n, m, dp[N][N][N/2];
char mat[N][N];

bool bad(int x, int y){
	return x < 1 || x > n || y < 1 || y > m;
}

int go(int x1, int y1, int x2){
	int dist = abs(x1 - 1) + abs(y1 - 1);
	int y2 = (n - x2) + (m - dist);

	if((x1 > x2) || (y1 > y2) || (mat[x1][y1] != mat[x2][y2]))
		return 0;
	if(x1 == x2 && y2-y1 <= 1)
		return 1;
	if(y1 == y2 && x2-x1 <= 1)
		return 1;
	int &ans = dp[x1][x2][dist];
	if(~ans)
		return ans;
	
	ans = 0;
	ans = (ans + go(x1, y1 + 1, x2)) % mod;
	ans = (ans + go(x1, y1 + 1, x2 - 1)) % mod;
	ans = (ans + go(x1 + 1, y1, x2)) % mod;
	ans = (ans + go(x1 + 1, y1, x2 - 1)) % mod;
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin >> n >> m;
	FOR(i, 1, n) FOR(j, 1, m) cin >> mat[i][j];
	memset(dp, -1, sizeof(dp));
	cout << go(1, 1, n) << '\n';
}
