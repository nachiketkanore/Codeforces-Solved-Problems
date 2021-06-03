#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, M = 5005;

int n, k, have[N], like[N], cost[N], dp[M][M];

int go(int id, int rem){
	if(rem < 0)
		return -inf;
	if(id == 0)
		return 0;

	int &ans = dp[id][rem];
	if(~ans)
		return ans;
	ans = 0;

	FOR(give, 1, k){
		int get = cost[give] + go(id - 1, rem - give);
		ans = max(ans, get);
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

	cin >> n >> k;
	FOR(i, 1, k*n){
		int u;
		cin >> u;
		have[u]++;
	}
	FOR(i, 1, n){
		int fav;
		cin >> fav;
		like[fav]++;
	}
	FOR(i, 1, k){
		cin >> cost[i];
	}

	int ans = 0;
	memset(dp, -1, sizeof(dp));

	FOR(i, 1, N - 2) {
		int val = i;
		int howmany = like[i];
		int wehave = have[i];
		ans += go(howmany, wehave);
	}
	cout << ans << '\n';
}
