#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 2e5 + 5, LG = 19;

int tim=0;
int parent[LG][N], a[N], pref[N];
int tin[N], tout[N], level[N];
std::vector<pair<int,int>> g[N];
int n, q;

void dfs(int k, int par, int lvl)
{
    tin[k]=++tim;
    parent[0][k]=par;
    level[k]=lvl;
    for(auto it:g[k])
    {
        if(it.first==par)
            continue;
        dfs(it.first, k, lvl+it.second);
    }
    tout[k]=tim;
}

void precompute()
{
    for(int i=1;i<LG;i++)
        for(int j=1;j<=n;j++)
            if(parent[i-1][j])
                parent[i][j]=parent[i-1][parent[i-1][j]];
}

int LCA(int u, int v)
{
    if(level[u]<level[v])
        swap(u,v);
    int diff=level[u]-level[v];
    for(int i=LG-1;i>=0;i--)
    {
        if((1<<i) & diff)
        {
            u=parent[i][u];
        }
    }
    if(u==v)
        return u;
    for(int i=LG-1;i>=0;i--)
    {
        if(parent[i][u] && parent[i][u]!=parent[i][v])
        {
            u=parent[i][u];
            v=parent[i][v];
        }
    }
    return parent[0][u];
}

int walk(int u, int h){ // node at distance 'h' from u
    for(int i = LG-1; i >= 0; i--){
        if((h >> i) & 1)
            u = parent[i][u];
    }
    return u;
}

void dfs2(int u, int p) {
    for(auto it : g[u]) if(it.first != p) {
        dfs2(it.first, u);
        pref[u] += pref[it.first];
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
    }
    FOR(i,2,n) {
        int par, w;
        cin >> par >> w;
        g[i].push_back({par, w});
        g[par].push_back({i, w});
    }
    dfs(1,0,0);
    precompute();

    FOR(i,1,n) {
        int currNode = i;
        int lo = 1, hi = n;
        int farthestNode = -1;
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            int distanceUp = mid;
            int nodeUp = walk(i, distanceUp);
            int dist = level[currNode] - level[nodeUp];
            //need to go further up
            if(dist <= a[currNode]) {
                farthestNode = nodeUp;
                lo = mid + 1;
            }else {
                hi = mid - 1;
            }
        }
        if(~farthestNode) {     
            pref[parent[0][farthestNode]]--;
            pref[parent[0][currNode]]++;
        }
    }

    dfs2(1,1);

    FOR(i,1,n) {
        cout << (pref[i]) << ' ';
    }
}
