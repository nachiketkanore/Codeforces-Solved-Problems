#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 3e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

std::vector<pair<int,int>> g[N];
int n, m, dp[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

#ifndef ONLINE_JUDGE
freopen("in1.txt","r",stdin);
freopen("out1.txt","w",stdout);
#endif
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		g[w].push_back({u,v});
	}
	int u, v, mx;
	for(int w = N-1; w >= 0; w--){
		std::vector<pair<int,int>> adj;
		for(auto it : g[w]){
			u = it.first, v = it.second;
			adj.push_back({u, dp[v] + 1});
		}
		for(auto it : adj){
			u = it.first, mx = it.second;
			dp[u] = max(dp[u], mx);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';
}

