#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 500 + 2, inf = 1e15;

int n, m, FW[N][N], cnt[N];
array<int,3> edges[N * N];
int ans[N][N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    FOR(i,1,n) FOR(j,1,n) FW[i][j] = (i == j ? 0 : inf);

    FOR(i,1,m) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];   
        auto [u, v, w] = edges[i];     
        FW[u][v] = FW[v][u] = w;
    }    

    FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) FW[i][j] = min(FW[i][j], FW[i][k] + FW[k][j]);

    FOR(from,1,n) {
        FOR(i,1,n) cnt[i] = 0;
        FOR(i,1,m) {
            auto [u, v, w] = edges[i];
            if (FW[from][u] == FW[from][v] + w) 
                ++cnt[u];
            if (FW[from][v] == FW[from][u] + w)
                ++cnt[v];
        }
        FOR(to,1,n) FOR(through,1,n) if (FW[from][to] == FW[from][through] + FW[through][to])
            ans[from][to] += cnt[through];
    }

    FOR(from,1,n) FOR(to,from+1,n) cout << ans[from][to] << " ";
}
