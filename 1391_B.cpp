#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 100 + 2, inf = 1e18;

void solve();

int n , m;
char mat[N][N];
bool vis[N * N];
std::vector<int> g[N * N];

int node(int i, int j) {
    return (i - 1) * m + j;
}

void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) if(!vis[v]) dfs(v);
}

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
    FOR(i,1,n) {
        FOR(j,1,m) {
            cin >> mat[i][j];
            vis[node(i,j)] = false;
        }
    }

    FOR(i,1,n*m) g[i].clear();

    FOR(i,1,n) {
        FOR(j,1,m) {
            if(mat[i][j] == 'C') continue;
            int u = node(i, j);
            if(mat[i][j] == 'R') {
                if(j + 1 <= m) {
                    int v = node(i, j + 1);
                    g[v].push_back(u);
                    g[u].push_back(v);
                }
            }else {
                if(i + 1 <= n) {
                    int v = node(i + 1, j);
                    g[v].push_back(u);
                    g[u].push_back(v);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n * m; i++) if(vis[i] == false) {
        ++ans;
        dfs(i);
    }

    cout << ans - 1 << '\n';
}
