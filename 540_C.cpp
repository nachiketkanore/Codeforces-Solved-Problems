#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
#define ar array
using namespace std;

const int N = 505;
const int inf = 1e12;
const int mod = 1e9 + 7;
char mat[N][N];
int n, m, r1, c1, r2, c2, vis[N][N];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

bool inside(int x, int y){
	return x >= 1 and x <= n and y >= 1 and y <= m;
}

void dfs(int x, int y){
	if(!inside(x, y))
		return ;
	if(mat[x][y] == 'X' || vis[x][y])
		return ;
	vis[x][y] = 1;

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny);
	}
}

void check(){
	memset(vis, 0, sizeof(vis));
	dfs(r1, c1);
	if(vis[r2][c2]){
		cout << "YES" << '\n';
		exit(0);
	}
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> mat[i][j];

	cin >> r1 >> c1 >> r2 >> c2;
	mat[r1][c1] = '.';

	if(mat[r2][c2] == 'X'){
		mat[r2][c2] = '.';
		check();
	}else{

		for(int i = 0; i < 4; i++){
			int nx = r2 + dx[i];
			int ny = c2 + dy[i];
			if(inside(nx, ny) && mat[nx][ny] == '.'){
				mat[nx][ny] = 'X';
				check();
				mat[nx][ny] = '.';
			}
		}

	}
	cout << "NO" << '\n';
}