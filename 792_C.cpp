#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

string s, ans;
int n, dp[2][3][N];

int go(int id, int mod, bool leading){
	if(id >= n)
		return (leading && mod == 0 ? 0 : -inf);

	int c1 = 0, c2 = 0;
	int &ans = dp[leading][mod][id]; if(~ans) return ans;

	if(s[id] == '0'){
		c1 = (leading) + go(id + 1, mod, leading);
	}else{
		c1 = 1 + go(id + 1, (mod + (s[id] - '0')) % 3, 1);
	}

	c2 = go(id + 1, mod, leading);
	return ans = max(c1, c2);
}

void trace(int id, int mod, bool leading){
	if(id >= n)
		return ;

	int c1 = 0;
	int real_ans = go(id, mod, leading);

	if(s[id] == '0'){
		if(leading){
			c1 = 1 + go(id + 1, mod, leading);
			if(c1 == real_ans){
				cout << s[id];
				return trace(id + 1, mod, leading);
			}
		}else{
			c1 = go(id + 1, mod, leading);
			if(c1 == real_ans){
				return trace(id + 1, mod, leading);
			}
		}
	}else{
		c1 = 1 + go(id + 1, (mod + (s[id] - '0')) % 3, 1);
		if(c1 == real_ans){
			cout << s[id];
			return trace(id + 1, (mod + (s[id] - '0')) % 3, 1);
		}
	}
	return trace(id + 1, mod, leading);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	memset(dp, -1, sizeof(dp));
	cin >> s;
	n = sz(s);
	int mxLen = go(0,0,0);
	bool zero = false;
	for(char ch : s) zero |= ch == '0';
 	if(mxLen < 0){
 		cout << (zero ? "0" : "-1");
 		return 0;
 	}
 	trace(0,0,0);
}
