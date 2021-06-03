#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e2 + 2, inf = 1e18;

int n, m, k, mat[N][N], dp[N][N][12];

int go(int i, int j, int rem){
	if(i == 1){
		if(rem % k == 0)
			return 0;
		return -inf;
	}

	int &ans = dp[i][j][rem];
	if(~ans)
		return ans;
	ans = -inf;

	if(j + 1 <= m and i - 1 >= 1){
		int add = mat[i - 1][j + 1];
		int get = add + go(i - 1, j + 1, (rem + add) % k);
		ans = max(ans, get);
	}
	if(i - 1 >= 1 and j - 1 >= 1){
		int add = mat[i - 1][j - 1];
		int get = add + go(i - 1, j - 1, (rem + add) % k);
		ans = max(ans, get);
	}
	return ans;
}

void print(int i, int j, int rem){
	if(i == 1)
		return;

	int real_ans = go(i,j,rem);

	if(j + 1 <= m and i - 1 >= 1){
		int add = mat[i - 1][j + 1];
		int get = add + go(i - 1, j + 1, (rem + add) % k);
		if(get == real_ans){
			cout << "R";
			return print(i - 1, j + 1, (rem + add) % k);
		}
	}
	if(i - 1 >= 1 and j - 1 >= 1){
		int add = mat[i - 1][j - 1];
		int get = add + go(i - 1, j - 1, (rem + add) % k);
		if(real_ans == get){
			cout << "L";
			return print(i - 1, j - 1, (rem + add) % k);
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

	cin >> n >> m >> k;
	++k;
	FOR(i,1,n) 
	FOR(j,1,m){
		char ch;
		cin >> ch;
		mat[i][j] = ch - '0';
	}

	memset(dp, -1, sizeof(dp));
	int ans = -1;

	FOR(col,1,m){
		int get = mat[n][col] + go(n,col,mat[n][col] % k);
		ans = max(ans, get);
	}
	cout << ans << '\n';
	if(ans != -1)
		FOR(col,1,m){
			int get = mat[n][col] + go(n,col,mat[n][col] % k);
			if(get == ans){
				cout << col << '\n';
				print(n, col, mat[n][col] % k);
				break;
			}
		}
}
