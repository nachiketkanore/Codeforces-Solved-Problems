#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, chk = 1e9;

int n, a[N], b[N], R, dp[105][30005];
vector<pair<int,int>> order;

int go(int id, int curr){
	if(curr < 0)
		return -inf;
	if(id > n)
		return 0;

	int &ans = dp[id][curr];
	if(~ans)
		return ans;

	ans = go(id + 1, curr);
	int which = order[id - 1].second;
	if(curr >= a[which]){
		int get = 1 + go(id + 1, curr + b[which]);
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

	cin >> n >> R;
	FOR(i, 1, n){
		cin >> a[i] >> b[i];
		if(b[i] >= 0)
			order.push_back({a[i] - chk, i});
		else
			order.push_back({-(a[i] + b[i]), i});
	}	

	memset(dp, -1, sizeof(dp));
	sort(order.begin(), order.end());
	int maxTake = go(1, R);
	cout << (maxTake) << '\n';
}
