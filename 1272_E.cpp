#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int n, a[N];
bool vis[N];
std::vector<int> g[N];
int ans[N], dist[N];

void multiSourceBFS(int bit){
    fill(dist, dist + N, inf);
    fill(vis, vis + N, false);

    queue<int> Q;
    FOR(i,1,n) if((a[i] & 1) == bit){
        dist[i] = 0;
        Q.push(i);
    }

    while(!Q.empty()){
        int from = Q.front();
        Q.pop();
        if(vis[from]) 
            continue;
        vis[from] = true;
        for(int to : g[from]) {
            if(dist[to] > dist[from] + 1) {
                dist[to] = dist[from] + 1;
                Q.push(to);
            }
        }
    }

    FOR(i,1,n) if(bit != (a[i] & 1)) {
        ans[i] = dist[i];
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
    FOR(i,1,n){
        cin >> a[i];
        if(i - a[i] >= 1) {
            g[i - a[i]].push_back(i);
        }
        if(i + a[i] <= n) {
            g[i + a[i]].push_back(i);
        }
    }

    FOR(i,1,n)  
        ans[i] = inf;

    multiSourceBFS(0);
    multiSourceBFS(1);

    FOR(i,1,n) {
        if(ans[i] >= inf)
            ans[i] = -1;
        cout << (ans[i]) << ' ';
    }
}
