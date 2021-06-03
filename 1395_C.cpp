#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, m, a[202], b[202];
int dp[202][1 << 12];


int go(int id, int curr) {
    if(id == n) 
        return curr;
    int &ans = dp[id][curr];
    if(~ans)
        return ans;
    ans = inf;
    for(int i = 0; i < m; i++) {
        ans = min(ans, go(id + 1, curr | (a[id] & b[i])));
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0,0) << '\n';
}
