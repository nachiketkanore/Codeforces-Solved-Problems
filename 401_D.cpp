#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

string n;
int m, size, dp[(1 << 18)][105];

int go(int mask, int rem){
	if(__builtin_popcountll(mask) == size)
		return rem == 0;

	int &ans = dp[mask][rem];
	if(~ans)
		return ans;
	ans = 0;
	for(int i = 0; i < size; i++) if((mask >> i & 1) == 0){
		if(mask == 0 and n[i] == '0') continue;	//no leading zeros
		if(i > 0 and n[i] == n[i - 1] and (mask >> (i - 1) & 1) == 0) continue;	//no extra counting
		ans += go(mask | (1 << i), (rem * 10 + (n[i] - '0')) % m);
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
	sort(n.begin(), n.end());
	size = sz(n);
	cout << go(0, 0);
}
