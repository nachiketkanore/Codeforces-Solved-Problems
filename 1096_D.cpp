#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
string s;
string hard = "hard";
int a[N], n, dp[N][5];


int solve(int id, int hardId){
	if(hardId > 3)
		return inf;
	if(id > n)
		return 0;

	int &ans = dp[id][hardId];
	if(ans != -1)
		return ans;

	int remove = a[id] + solve(id + 1, hardId);
	int dont_remove = solve(id + 1, hardId + (s[id] == hard[hardId]));

	return ans = min(remove, dont_remove);
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
	cin >> s;
	s = "#" + s;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cout << solve(1,0) << '\n';
}
