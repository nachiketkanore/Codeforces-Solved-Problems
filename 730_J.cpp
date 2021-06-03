#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long
using pii = pair<int,int>;

const int N = 1e2 + 2, inf = 1e18;
const int OK = N * N;

int n, a[N], b[N];
pii dp[N][N * N * 2];
bool vis[N][N * N * 2];


pii go(int id, int have){
	if(id > n){
		if(have >= 0)
			return pii(0,0);
		return pii(inf,inf);
	}

	pii &ans = dp[id][have + OK];
	if(vis[id][have + OK])
		return ans;

	vis[id][have + OK] = 1;

	pii c1 = go(id + 1, have - a[id]);
	c1.second += a[id];

	pii c2 = go(id + 1, have + (b[id] - a[id]));
	c2.first += 1;
	return ans = min(c1, c2);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin >> n;
	FOR(i,1,n) cin >> a[i];
	FOR(i,1,n) cin >> b[i];
	cout << go(1,0).first << " " << go(1,0).second << '\n';
}
