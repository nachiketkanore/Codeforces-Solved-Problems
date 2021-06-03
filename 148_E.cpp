#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 102, M = 1e4 + 2, inf = 1e9;

int n, m;
int a[N][N], size[N];
int dp[N][M];
int info[N][N];

int go(int id, int chosen){
	if(chosen > m)
		return -inf;
	if(id > n)
		return (chosen == m ? 0 : -inf);

	int &ret = dp[id][chosen];
	if(~ret)
		return ret;

	int ans = go(id + 1, chosen);
	int x = size[id];

	FOR(take, 1, x){
		int cost = info[id][take] + go(id + 1, chosen + take);
		ans = max(ans, cost);
	}

	return ret = ans;
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
	FOR(i, 1, n){
		cin >> size[i];
		FOR(j, 1, size[i]){
			cin >> a[i][j];
			a[i][j] += a[i][j - 1];
		}
	}

	FOR(id, 1, n){
		int x = size[id];
		FOR(i, 1, x){
			FOR(j, i + 1, x){
				int cnt = i + (x - j + 1);
				int sum = a[id][i] + (a[id][x] - a[id][j - 1]);
				info[id][cnt] = max(info[id][cnt], sum);
			}
			//For straight prefix and suffix
			info[id][i] = max(info[id][i], a[id][i]);
			info[id][x - i + 1] = max(info[id][x - i + 1], (a[id][x] - a[id][i - 1]));
		}
	}

	int ans = go(1, 0);
	cout << ans << '\n';
}
