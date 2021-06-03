#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 205, inf = 1e18;

int k, a, b, n, dp[N][N];
string s;

int go(int from, int lines_done){
	if(from == n + 1)
		return lines_done == k;

	bool poss = false;
	int &ans = dp[from][lines_done];
	if(~ans)
		return ans;

	FOR(jump, a, b){
		if(from + jump - 1 <= n){
			poss |= go(from + jump, lines_done + 1);
		}
	}
	return ans = poss;
}

void print(int from, int lines_done){
	if(from == n + 1)
		return ;

	FOR(jump, a, b){
		if(from + jump - 1 <= n){
			bool poss = go(from + jump, lines_done + 1);
			if(poss){	
				FOR(i, from, from + jump - 1)	cout << s[i];	cout << '\n';
				print(from + jump, lines_done + 1);
				return;
			}
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

	memset(dp, -1, sizeof(dp));
	cin >> k >> a >> b >> s;
	n = sz(s); s = " " + s;
	if(go(1, 0)){
		print(1, 0);
	}else{
		cout << "No solution";
	}
}
