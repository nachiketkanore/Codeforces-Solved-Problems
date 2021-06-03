#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5e3 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, a[N], dp[N][N];

int solve(int i, int j){
	if(i == 1 && j == n)
		return 0;

	int &ans = dp[i][j];
	if(ans != -1)
		return ans;

	ans = inf;
	if(i - 1 >= 1 and a[i-1] == a[i])
		ans = min(ans, solve(i-1, j));
	else if(i - 1 >= 1)
		ans = min(ans, 1 + solve(i-1, j));
	if(j + 1 <= n and a[j+1] == a[j])
		ans = min(ans, solve(i, j+1));
	else if(j + 1 <= n)
		ans = min(ans, 1 + solve(i, j+1));
	if(i - 1 >= 1 and j + 1 <= n and a[i-1] == a[j+1])
		ans = min(ans, 1 + solve(i-1, j+1));
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

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = inf;
	for(int i = 1; i <= n; i++){
		ans = min(ans, solve(i, i));
	}
	cout << ans << '\n';
}
