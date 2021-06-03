#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int f[26];
int n;
string s;
vector<int> idx;
int dp[2600][2600];

int go(int i, int j){
	if(i > j)
		return 0;
	if(i == j)
		return 1;
	int &ret = dp[i][j]; if(~ret) return ret;
	int ans = max(go(i + 1, j), go(i, j - 1));
	if(s[i] == s[j])
		ans = max(ans, 2 + go(i + 1, j - 1));
	return ret = ans;
}

void print(int i, int j){
	if(i > j)
		return;
	if(i == j){
		idx.push_back(i);
		return;
	}
	int ans = go(i, j);
	if(go(i + 1, j) == ans)
		return print(i + 1, j);
	if(go(i, j - 1) == ans)
		return print(i, j - 1);
	if(s[i] == s[j] and (2 + go(i + 1, j - 1) == ans)){
		idx.push_back(i);
		idx.push_back(j);
		return print(i + 1, j - 1);
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin >> s;
	n = sz(s);
	for(char ch : s){
		f[ch - 'a']++;
		if(f[ch - 'a'] >= 100){
			FOR(i,1,100)
			cout << (char)(ch);
			return 0;
		}
	}
	memset(dp, -1, sizeof(dp));

	int mx = go(0,n-1);
	print(0,n-1);
	sort(idx.begin(), idx.end());
	if(mx >= 100){
		int cnt = 100;
		string ans;
		FOR(i,0,49)
			ans.push_back(s[idx[i]]);
		cout << ans;
		reverse(ans.begin(), ans.end());
		cout << ans;
	}else{
		for(int id : idx)
			cout << s[id];
	}
}
