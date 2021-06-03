#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5e5 + 5;
const int inf = 1e12;
const int mod = 1e9 + 7;
int n, a[N], dp[N][2][2];


int solve(int id, int PosTaken, int NegTaken){

	if(n == 1)
		return a[id];

	if(id < 1){
		if(PosTaken > 0 && NegTaken > 0)
			return 0;
		return -inf;
	}

	int &ans = dp[id][!!PosTaken][!!NegTaken];
	if(ans != -1)
		return ans;

	int GivePos = a[id] + solve(id - 1, PosTaken + 1, NegTaken);
	int GiveNeg = -a[id] + solve(id - 1, PosTaken, NegTaken + 1);
	return ans = max(GiveNeg, GivePos);

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
	cout << solve(n, 0, 0) << '\n';
}
