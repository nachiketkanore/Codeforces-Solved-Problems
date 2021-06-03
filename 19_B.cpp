#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 2000 + 2, inf = 1e18;

int n, t[N], c[N];
int dp[N][N];

int go(int id, int time){
	if(time <= 0) return 0;
	if(id > n) return inf;

	int &ans = dp[id][time]; if(~ans) return ans;

	return ans = min(go(id + 1, time), c[id] + go(id + 1, time - t[id] - 1));
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin >> n;
	FOR(i,1,n){
		cin >> t[i] >> c[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << go(1,n);
}
