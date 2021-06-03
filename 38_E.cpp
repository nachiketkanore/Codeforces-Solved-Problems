#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 3e3 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, dp[N][N];
array<int,2> val[N];

int solve(int prevTaken, int curr){
	if(curr > n)
		return 0;

	int &ans = dp[prevTaken][curr];
	if(ans != -1)
		return ans;

	int put = val[curr][1] + solve(curr, curr + 1);
	int dont_put = abs(val[curr][0] - val[prevTaken][0]) + solve(prevTaken, curr + 1);
	return ans = min(put, dont_put);
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
		cin >> val[i][0] >> val[i][1];
	sort(val + 1, val + n + 1);

	cout << solve(1, 2) + val[1][1] << '\n';
}
