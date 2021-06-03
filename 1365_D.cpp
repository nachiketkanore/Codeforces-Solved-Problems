#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 50 + 2, inf = 1e18;

char mat[N][N];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool vis[N][N];

bool inside(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y){
    if(!inside(x,y) || mat[x][y] == '#' || vis[x][y])
        return ;
    vis[x][y] = 1;
    FOR(k,0,3) 
        dfs(x + dx[k], y + dy[k]);
}

void solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    cin >> n >> m;
    FOR(i,1,n) FOR(j,1,m) cin >> mat[i][j];
    FOR(i,1,n) FOR(j,1,m) {
        vis[i][j] = 0;
        if(mat[i][j] == 'B'){
            FOR(k,0,3){
                int nx = i + dx[k], ny = j + dy[k];
                if(inside(nx,ny) && mat[nx][ny] == '.')
                    mat[nx][ny] = '#';
            }
        }
    }
    dfs(n,m);
    bool good = true, bad = false;
    FOR(i,1,n) FOR(j,1,m){
        if(mat[i][j] == 'G')
            good &= vis[i][j];
        if(mat[i][j] == 'B')
            bad |= vis[i][j];
    }
    cout << (good && !bad ? "Yes" : "No" ) << '\n';
}
