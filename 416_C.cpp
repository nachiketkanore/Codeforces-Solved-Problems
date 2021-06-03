#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 1000 + 2, inf = 1e18;

int n, k, dp[N][N];
vector<array<int,3>> req;
vector<array<int,2>> tables;
vector<pair<int,int>> choices;

int go(int i, int j) {
    if(i >= n || j >= k)
        return 0;
    int &ans = dp[i][j];
    if(~ans)
        return ans;
    ans = max(go(i + 1, j), go(i, j + 1));
    if(req[i][0] <= tables[j][0]) {
        int get = req[i][1] + go(i + 1, j + 1);
        ans = max(ans, get);
    }
    return ans;
}

void trace(int i, int j) {
    if(i >= n || j >= k)
        return ;
    int ans = go(i, j);
    if(go(i + 1, j) == ans)
        return trace(i + 1, j);
    if(go(i, j + 1) == ans)
        return trace(i, j + 1);
    if(req[i][0] <= tables[j][0]) {
        int get = req[i][1] + go(i + 1, j + 1);
        if(get == ans) {
            choices.push_back({req[i][2], tables[j][1]});
            return trace(i + 1, j + 1);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    req.resize(n);
    FOR(i,1,n) {
        cin >> req[i - 1][0] >> req[i - 1][1];
        req[i - 1][2] = i;
    }
    cin >> k;
    tables.resize(k);
    FOR(i,1,k) {
        cin >> tables[i - 1][0];
        tables[i - 1][1] = i;
    }
    sort(req.rbegin(), req.rend());
    sort(tables.rbegin(), tables.rend());
    
    memset(dp, -1, sizeof(dp));
    int ans = go(0,0);
    trace(0,0);

    cout << sz(choices) << " " << ans << '\n';
    for(auto& it : choices) {
        cout << it.first << " " << it.second << '\n';   
    }
}
