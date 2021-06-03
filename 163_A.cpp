#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 5002, inf = 1e18, mod = 1e9 + 7;

string a, b;
int n, m, dp[N][N];

int go(int i, int j){
	if(i >= n || j >= m)
		return 1;
	int &ret = dp[i][j];
	if(~ret)
		return ret;
	int ans = go(i, j + 1);
	if(a[i] == b[j])
		ans += go(i + 1, j + 1);
	ans %= mod;
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
	cin >> a >> b;
	n = sz(a), m = sz(b);
	int ans = 0;
	FOR(i,0,n-1){
		ans += go(i, 0);
		ans %= mod;
	}
	ans = (ans - n + mod) % mod;
	cout << ans << '\n';
}
