#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, m, x, y;
vector<pair<int,int>> ans;
bool vis[102][102];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n >> m;
    cin >> x >> y;
    vis[x][y] = 1;
    for(int r = x; r >= 1; r--) {
        vis[r][y] = 1;
        ans.push_back({r, y});
    }

    int sx = 1, sy = y;

    for(int row = 1; row <= n; row++) {
        int nsx = -1, nsy = -1;
        for(int i = 1; i <= m; i++) {
            if(vis[row][i] == false) {
                ans.push_back({row, i});
                vis[row][i] = 1;
                nsx = row, nsy = i;
            }
        }
        assert(nsx != -1 && nsy != -1);
        vis[nsx + 1][nsy] = 1;
        ans.push_back({nsx + 1, nsy});
    }

    for(auto& it : ans) {
        int a = it.first, b = it.second;
        if(a < 1 || a > n || b > m || b < 1) continue;
        cout << it.first << ' ' << it.second << '\n';
    }
}
