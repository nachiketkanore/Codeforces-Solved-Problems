#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)

const int N = 1e6 + 2, inf = 1e9;

int n, m;
int column_mask[N];
int dp[1 << 3][N];

bool valid(int prev, int curr) {
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || i == 1)
            sum1 += prev >> i & 1,
            sum1 += curr >> i & 1;
        if(i == 1 || i == 2) 
            sum2 += prev >> i & 1,
            sum2 += curr >> i & 1;
    }
    if(n == 2)
        return sum1&1;
    assert(n == 3);
    return (sum1&1 && sum2&1);
}

int go(int col, int prev_col) {
    if(col == m)
        return 0;

    int &ans = dp[prev_col][col];
    if(~ans)
        return ans;
    ans = inf;
    for(int mask = 0; mask < (1 << n); mask++) {
        if(valid(prev_col, mask)) {
            int flips = __builtin_popcountll(mask ^ column_mask[col]) + go(col + 1, mask);
            ans = min(ans, flips);
        }
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    if(n >= 4) {
        cout << -1;
        return 0;
    }
    if(n == 1) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char ch;    cin >> ch;
            column_mask[j] |=  (ch - '0') << i;
        }
    }

    int ans = inf;
    memset(dp, -1, sizeof(dp));

    for(int mask = 0; mask < (1 << n); mask++) {
        int flips = __builtin_popcountll(mask ^ column_mask[0]) + go(1, mask);
        ans = min(ans, flips);
    }
    cout << ans;
}
