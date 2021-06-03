#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 5005, inf = 1e18, mod = 1e9 + 7;

std::vector<pair<int,int>> g[N];
std::vector<int> ret;
int n, m, u, v, w, T, mx, dp[N][N];

int go(int curr, int len){
    if(len < 0)
        return inf;
    if(curr == n && len == 0)
        return 0;
    int &ans = dp[curr][len];
    if(~ans)
        return ans;
    ans = inf;
    for(auto next : g[curr]){
        int cost = next.second + go(next.first, len - 1);
        ans = min(ans, cost);
    }
    return ans;
}

void find(int curr, int len){
    if(curr == n && len == 0)
        return;

    int actual_ans = go(curr, len);
    for(auto next : g[curr]){
        int cost = next.second + go(next.first, len - 1);
        if(cost == actual_ans){
            cout << next.first << " ";
            return find(next.first, len - 1);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> T;
    while(m--){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    for(int len = 1; len <= n; len++){
        int minTime = go(1, len - 1);
        if(minTime <= T)
            mx = len;
    }

    cout << mx << '\n';
    cout << 1 << " ";
    find(1, mx - 1);
}