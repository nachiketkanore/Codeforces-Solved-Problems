#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 20, inf = 1e18;

int n, m, k, mat[N][N];
map<int,int> vals[N][N];
bool vis[N][N];

void go1(int i, int j, int curr_xor, int steps){
	if(i >= n || j >= m || steps > N)
		return;
	curr_xor ^= mat[i][j];
	vals[i][j][curr_xor] += 1;
	vis[i][j] = true;

	go1(i + 1, j, curr_xor, steps + 1);
	go1(i, j + 1, curr_xor, steps + 1);
}

int go(int i, int j, int curr_xor){
	if(i < 0 || j < 0)
		return 0;
	int ans = 0;
	if(vis[i][j]){
		int want = k ^ curr_xor; // path1 ^ path2 = k => path1 = path2 ^ k
		ans += vals[i][j][want];
		return ans;
	}

	curr_xor ^= mat[i][j];
	ans += go(i - 1, j, curr_xor);
	ans += go(i, j - 1, curr_xor);
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin >> n >> m >> k;
	FOR(i,0,n-1) FOR(j,0,m-1) cin >> mat[i][j];
	go1(0,0,0,0);
	cout << go(n-1,m-1,0);

}
