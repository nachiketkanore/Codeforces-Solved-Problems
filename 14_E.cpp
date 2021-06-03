#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int n, t;
int dp[21][5][5][11][11];

int go(int id, int prev2, int prev1, int hills, int valleys) {
    if (id > n)
        return hills == t && valleys == t - 1;

    int &ans = dp[id][prev2][prev1][hills][valleys];
    if (~ans)
        return ans;
    ans = 0;

    FOR(next,1,4) if (next != prev1) {
        int is_hill = prev2 < prev1 && prev1 > next;
        int is_valley = prev2 > prev1 && prev1 < next;
        ans += go(id + 1, prev1, next, hills + is_hill, valleys + is_valley);

    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> t;

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    FOR(fi,1,4) FOR(se,1,4) if (fi != se) {
        ans += go(3,fi,se,0,0);
    }

    cout << ans;
}
