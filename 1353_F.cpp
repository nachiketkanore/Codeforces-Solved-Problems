#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 102, inf = 1e18;

int n, m, mat[N][N], dp[N][N];

void solve();

bool inside(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int go(int x, int y, int keep){
    if(!inside(x, y))
        return inf;
    if(mat[x][y] < keep)
        return inf;

    int &ans = dp[x][y];
    if(~ans)
        return ans;

    int cost = mat[x][y] - keep;

    if(x == n && y == m){
        return cost;
    }

    int right = cost + go(x + 1, y, keep + 1);
    int down = cost + go(x, y + 1, keep + 1);
    return ans = min(right, down);
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
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mat[i][j];

    int ans = inf;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int keep = mat[i][j] - (i - 1 + j - 1);
            memset(dp, -1, sizeof(dp));
            int cost = go(1, 1, keep);
            ans = min(ans, cost);
        }

    cout << ans << '\n';
}
