#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 1e5 + 2, inf = 1e9;

int n,m;
string s;
int cnt[20][20];
int dp[20][1 << 20];

int go(int pos, int mask){
	if(pos >= m)
		return 0;

	int add_dist = 0;
	int &ans = dp[pos][mask];
	if(~ans)
		return ans;
	ans = inf;

	FOR(i,0,m-1) FOR(j,i+1,m-1) if((mask >> i & 1) ^ (mask >> j & 1))
		add_dist += cnt[i][j];
	FOR(i,0,m-1) if((mask >> i & 1) == 0){
		int next_ans = go(pos + 1, mask | (1 << i));
		int cost = add_dist + next_ans;
		ans = min(ans, cost);
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
	cin >> n >> m;
	cin >> s;
	FOR(i,1,n-1){
		char from = min(s[i], s[i-1]), to = max(s[i], s[i-1]);
		cnt[from - 'a'][to - 'a']++;
		cnt[to - 'a'][from - 'a']++;
	}
	cout << go(0,0);
}
