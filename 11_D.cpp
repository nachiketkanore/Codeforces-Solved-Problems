#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 19;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, m, ans, dp[N][1 << N];
bool g[N][N];

int go(int u, int mask, int start, int prev){

	int &ans = dp[u][mask];
	if(ans != -1)
		return ans;

	ans = 0;

	for(int v = start; v < n; v++)
		if(g[u][v] && v != prev){
			if(v == start)
				ans++;
			else if(!(mask & (1 << v)))
				ans += go(v, mask | (1 << v), start, u);
		}
	
	return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    #ifndef ONLINE_JUDGE
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif	

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    while(m--){
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	g[u][v] = g[v][u] = 1;
    }

    for(int i = 0; i < n; i++){
    	ans += go(i,1 << i,i,0)/2;
    }

    cout << ans << '\n';
}

