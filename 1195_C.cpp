#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, h[2][N], dp[2][N];

int solve(int arrId, int id){
	if(id > n)
		return 0;

	int &ans = dp[arrId][id];
	if(ans != -1)
		return ans;

	int take = h[arrId][id] + solve(arrId ^ 1, id + 1);
	int dont_take = solve(arrId , id + 1);
	return ans = max(take, dont_take);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	memset(dp, -1, sizeof(dp));

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> h[0][i];
	for(int i = 1; i <= n; i++)
		cin >> h[1][i];

	cout << max(solve(0, 1), solve(1,1)) << '\n';
}
