#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 1e2 + 2;
const int inf = 1e9;

int t[N], w[N];
int n;
int dp[N][N << 1][N << 1];

/*
200 >= max(down) >= down >= up
hence up <= 200 always
*/

int go(int id, int up, int down){
	if(up > 200) return inf;
	if(id > n)
		return (down >= up ? down : inf);

	int &ans = dp[id][up][down]; if(~ans) return ans;

	int c1 = go(id + 1, up + w[id], down);
	int c2 = go(id + 1, up, down + t[id]);
	return ans = min(c1, c2);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	memset(dp, -1, sizeof(dp));
	cin >> n;
	FOR(i,1,n){
		cin >> t[i] >> w[i];
	}
	cout << go(1,0,0);
}
