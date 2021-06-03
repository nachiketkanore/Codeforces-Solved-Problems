#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 20;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, m, k, a[N], cost[N][N], dp[1 << 19][N];

int solve(int mask, int taken, int last){
	if(taken == m)
		return 0;
	if(taken > m)
		return -inf;

	int &ans = dp[mask][last];
	if(ans != -1)
		return ans;
	ans = 0;

	for(int i = 1; i <= n; i++){
		if(!(mask & (1LL << i))){
			int next_ans = a[i] + cost[last][i] + solve(mask | (1LL << i), taken + 1, i);
			ans = max(ans, next_ans);
		}
	}
	return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	memset(dp, -1, sizeof(dp));

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 0, u, v, w; i < k; i++){
		cin >> u >> v >> w;
		cost[u][v] = w;
	}

	cout << solve(0,0,0) << '\n';
}
