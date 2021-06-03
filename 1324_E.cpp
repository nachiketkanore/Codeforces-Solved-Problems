#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e3 + 5;
const int inf = 1e12;
const int mod = 1e9 + 7;
int n, h, l, r, a[N], dp[N][N];


int solve(int time, int id){
	if(id > n)
		return 0;

	int &ans = dp[time][id];
	if(ans != -1)
		return ans;

	int h1 = (time + a[id]) % h;
	int h2 = (time + a[id] - 1) % h;
	int take = (l <= h1 and h1 <= r ? 1 : 0) + solve(h1, id + 1);
	int dont_take = (l <= h2 and h2 <= r ? 1 : 0) + solve(h2, id + 1);
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

	cin >> n >> h >> l >> r;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cout << solve(0, 1) << '\n';
}
