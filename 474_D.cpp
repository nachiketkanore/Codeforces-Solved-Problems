#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5, M = 1e6 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int t, k, dp[N+5];

int solve(int n){
	if(n == 0)
		return 1;
	if(n < 0)
		return 0;

	int &ans = dp[n];
	if(ans != -1)
		return ans;

	ans = solve(n-1) + solve(n-k);
	ans %= mod;

	return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    memset(dp, -1, sizeof(dp));

	cin >> t >> k;

    solve(N);
    for(int i = 1; i < N; i++)
    	dp[i] = (dp[i] + dp[i-1]) % mod;

	while(t--){
		int a, b;
		cin >> a >> b;
		int ans = (dp[b] - dp[a-1] + mod) % mod;
		cout << ans << '\n';
	}

}

