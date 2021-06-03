#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int to[N], from[N];
int mat[11][N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m;
    map<pair<int,int>,int> edges;
    memset(to, -1, sizeof(to));
    memset(from, -1, sizeof(from));

    FOR(i,1,m) {
        FOR(j,1,n) 
            cin >> mat[i][j];
        FOR(j,2,n) {
            int u = mat[i][j - 1], v = mat[i][j];
            edges[{u, v}]++;
        }
    }

    for(auto &edge : edges) if(edge.second == m) {
        int u = edge.first.first, v = edge.first.second;
        to[u] = v;
        from[v] = u;
    }

    int ans = 0;

    FOR(start,1,n) if(from[start] == -1) {
        int curr = start, len = 1;
        while(to[curr] != -1) {
            curr = to[curr];
            len++;
        }
        ans += len * (len + 1) /2;
    }

    cout << ans << '\n';
}
