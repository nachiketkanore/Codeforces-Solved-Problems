#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e2 + 5, M = 1e6 + 5;
const int inf = 1e18;
const int mod = 1e8;
int n1, n2, k1, k2, total, dp[N][N][11][11];


int solve(int rem, int one, int two, int cOne, int cTwo){
	if(rem == 0)
		return (one == n1 && two == n2 && cOne <= k1 && cTwo <= k2);
	if(rem < 0)
		return 0;
	if(one > n1 || two > n2 || cOne > k1 || cTwo > k2)
		return 0;
	
	int &ans = dp[one][two][cOne][cTwo];
	if(ans != -1)
		return ans;

	ans = 0;
	
	ans += solve(rem - 1, one + 1, two, cOne + 1, 0);
	ans %= mod;
	ans += solve(rem -1, one, two + 1, 0, cTwo + 1);
	ans %= mod;

	return ans;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
	#endif

    memset(dp, -1, sizeof(dp));

    cin >> n1 >> n2 >> k1 >> k2;

    total = n1 + n2;

    cout << solve(total, 0, 0, 0, 0) << '\n';
}

