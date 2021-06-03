#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; (L <= R? i <= R : i >= R); (L <= R? i += 1 : i -= 1))
#define int long long

const int N = 1e5 + 2, inf = 1e18;

string str[2][N];
int n, cost[2][N];
int dp[2][N];

int go(int id, int prev) {
    if(id == n + 1)
        return 0;
    int &ans = dp[prev][id];
    if(~ans)
        return ans;
    ans = inf;
    if(str[0][id] >= str[prev][id - 1]) {
        int get = cost[0][id] + go(id + 1, 0);
        ans = min(ans, get);
    }
    if(str[1][id] >= str[prev][id - 1]) {
        int get = cost[1][id] + go(id + 1, 1);
        ans = min(ans, get);
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    FOR(i,1,n) {
        cin >> cost[1][i];
    }
    FOR(i,1,n) {
        cin >> str[0][i];
        str[1][i] = str[0][i];
        reverse(str[1][i].begin(), str[1][i].end());
    }
    memset(dp, -1, sizeof(dp));
    int ans = min(cost[0][1] + go(2,0), cost[1][1] + go(2,1));
    if(ans >= inf)
        ans = -1;
    cout << ans;
}
