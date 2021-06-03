#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5000 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dp[N][N], a[N], n, m, k;

int solve(int id, int taken){
	
	if(taken == k)
		return 0;
	if(id > n)
		return -inf;

	int &ans = dp[id][taken];
	if(ans != -1)
		return ans;

	//Dont take or take - 2 conditions
	int dont_take = solve(id + 1, taken);
	int take = 0;

	int nextId = id + m - 1;
	if(nextId <= n){
		int sum = a[nextId] - a[id - 1];
		take = sum + solve(id + m, taken + 1);
	}

	ans = max(take, dont_take);
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] += a[i-1];
	}

	memset(dp, -1, sizeof(dp));

	cout << solve(1, 0) << '\n';
}