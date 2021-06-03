//Let's overkill Div-2-A
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e3+ 2, inf = 1e18;

int n, x, a[N], dp[2][N][N];

bool chk(int id, int taken, int sum){
	if(taken == x and sum == 1)
		return 1;
	if(id > n)
		return 0;
	int &ret = dp[sum][id][taken];
	if(~ret)
		return ret;
	return ret = chk(id + 1, taken + 1, (sum + a[id]) % 2) or chk(id + 1, taken, sum);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int tc;
	cin >> tc;
	FOR(tt, 1, tc){
		cin >> n >> x;
		FOR(i,0,n) FOR(j,0,n) dp[0][i][j] = dp[1][i][j] = -1;
		FOR(i,1,n)	cin >> a[i];
		cout << (chk(1,0,0) ? "Yes" : "No") << '\n';
	}
}
