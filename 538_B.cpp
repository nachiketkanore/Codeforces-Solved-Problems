#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 1e6 + 2, inf = 1e9;

std::vector<int> quasi;
int dp[N];

int minReq(int rem){
	if(rem <= 0)
		return (rem == 0? 0 : inf);

	int &ans = dp[rem];
	if(~ans)
		return ans;
	ans = inf;

	for(int val : quasi){
		int get = 1 + minReq(rem - val);
		ans = min(ans, get);
	}
	return ans;
}

void print(int rem){
	if(rem == 0)
		return;

	int true_ans = minReq(rem);

	for(int val : quasi){
		int get = 1 + minReq(rem - val);
		if(get == true_ans){
			cout << val << ' ';
			return print(rem - val);
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	FOR(i,1,1000000){
		string s = to_string(i);
		bool ok = 1;
		for(char ch : s) if(ch != '0' and ch != '1') {ok = 0; break;}
		if(ok) quasi.push_back(i);
	}

	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 10) minReq(i);
	int ans = minReq(n);
	cout << ans << '\n';
	print(n);
}
