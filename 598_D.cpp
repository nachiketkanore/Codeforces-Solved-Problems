#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e3 + 2, inf = 1e18;
const int M = 1e6 + 2;

int n, m, k;
bool vis[N][N];
char mat[N][N];
vector<pair<int,int>> comp;
int answer[M];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};


bool inside(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int node(int i, int j){
    return (i - 1) * m + j;
}

void dfs(int x, int y){
    if(!inside(x,y) || vis[x][y] || mat[x][y] == '*')
        return;
    vis[x][y] = 1;
    comp.push_back({x, y});
    FOR(i,0,3)
        dfs(x + dx[i], y + dy[i]);
}

int getCompAnswer(){
    int walls = 0;
    for(auto it: comp){
        int x = it.first, y = it.second;
        FOR(i,0,3){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(inside(nx,ny) && mat[nx][ny] == '*')
                walls++;
        }
    }
    return walls;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n >> m >> k;

    FOR(i,1,n) FOR(j,1,m) cin >> mat[i][j];
    FOR(i,1,n) FOR(j,1,m) if(mat[i][j] == '.' && vis[i][j] == false){
        comp.clear();
        dfs(i,j);
        int ans = getCompAnswer();
        FOR(i,0,sz(comp)-1)
            answer[node(comp[i].first, comp[i].second)] = ans;
    }
    while(k--){
        int x, y;   cin >> x >> y;
        cout << answer[node(x,y)] << '\n';
    }
}
