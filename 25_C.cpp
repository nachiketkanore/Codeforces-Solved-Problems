#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 300 + 2, inf = 1e18;
int n, mat[N][N], u, v, w, DP[N][N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    FOR(i,1,n) FOR(j,1,n) cin >> mat[i][j];
    int k;
    cin >> k;
    FOR(i,1,k) {
        cin >> u >> v >> w;
        w = min(w, mat[u][v]);
        mat[u][v] = mat[v][u] = w;

        int ans = 0;
        FOR(from,1,n) FOR(to,1,n) {
            mat[from][to] = min({
                mat[from][to],
                mat[from][u] + w + mat[v][to],
                mat[from][v] + w + mat[u][to]
            });
        }
        FOR(x,1,n) FOR(y,1,n) mat[x][y] = min(mat[x][y], mat[y][x]);
        FOR(from,1,n) FOR(to,from+1,n) ans += mat[from][to];
        cout << ans << '\n';

    }
}
