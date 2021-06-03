// I like overkilling problems
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 100 + 2, inf = 1e18;

string mat[2];
int n, dp[N][N][4][4];

int getMask(int col){
	if(col > n)
		return 3;
	int mask = 0;
	if(mat[0][col] == 'X')
		mask |= 1 << 0;
	if(mat[1][col] == 'X')
		mask |= 1 << 1;
	return mask;
}

int go(int i, int j, int maski, int maskj){
	if(j > n)
		return 0;

	int &ret = dp[i][j][maski][maskj];
	if(~ret)
		return ret;

	int ans = go(i + 1, j + 1, maskj, getMask(j + 1));

	if(maski == 0 and (maskj >> 1 & 1) == 0){
		int nmask = getMask(j + 1);
		int get = 1 + go(i + 1, j + 1, maskj ^ (2) , nmask);
		ans = max(ans, get);
	}
	if(maski == 0 and (maskj >> 0 & 1) == 0){
		int nmask = getMask(j + 1);
		int get = 1 + go(i + 1, j + 1, maskj ^ (1), nmask);
		ans = max(ans, get);
	}
	if(maskj == 0 and (maski >> 1 & 1) == 0){
		int nmask = getMask(j + 1);
		int get = 1 + go(i + 1, j + 1, 3, nmask);
		ans = max(ans, get);
	}
	if(maskj == 0 and (maski >> 0 & 1) == 0){
		int nmask = getMask(j + 1);
		int get = 1 + go(i + 1, j + 1, 3, nmask);
		ans = max(ans, get);
	}
	return ret = ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	memset(dp, -1, sizeof(dp));
	cin >> mat[0] >> mat[1];
	n = sz(mat[0]);
	mat[0] = " " + mat[0];
	mat[1] = " " + mat[1];
	cout << go(1, 2, getMask(1), getMask(2));
}
