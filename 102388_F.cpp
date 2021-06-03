#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 500 + 2, inf = 1e9;

int n, m, k, mat[N][N], info[N][N];
char ch;
int dp[N][N];

int go(int day, int skips_rem){
	if(skips_rem < 0)
		return inf;
	if(day > n)
		return 0;

	int &ans = dp[day][skips_rem];
	if(~ans)
		return ans;
	ans = inf;

	FOR(skips,0,mat[day][m]){
		int chk_ans = info[day][skips] + go(day + 1, skips_rem - skips);
		ans = min(ans, chk_ans);
	}
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> k;
	FOR(i,1,n) FOR(j,1,m) {
		cin >> ch;
		mat[i][j] = ch - '0';
		mat[i][j] += mat[i][j - 1];
	}
	FOR(i,0,N-1) FOR(j,0,N-1) info[i][j] = inf;
	FOR(day,1,n){
		FOR(i,1,m) FOR(j,i,m){
			int todo = mat[day][j] - mat[day][i - 1];
			int toskip = mat[day][m] - todo;
			int minstay = (todo == 0? 0: j-i+1);
			info[day][toskip] = min(info[day][toskip], minstay);
		}
		if(mat[day][m] == m){
			info[day][m] = 0;
		}
	}
	cout << go(1,k);
}
