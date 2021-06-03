#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, m;
pair<int,int> a[N];
int dp[N + 2];

int go(int curr) {
    if (curr > m)
        return 0;

    int &ans = dp[curr];
    if (~ans)
        return ans;
    ans = inf;
    int right = m - curr + 1;
    ans = min(ans, right);

    FOR(i,1,n) {
        int xi = a[i].first, si = a[i].second;
        int L = xi - si, R = xi + si;
        assert(L <= R);
        if (L <= curr && curr <= R) {
            ans = min(ans, go(R + 1));
        }
        if (R < curr) continue;
        if (xi == curr) {
            ans = min(ans, go(curr + 1));
            continue;
        }
        int inc = L - curr;
        if (inc > 0) {       
            int get = inc + go(R + inc + 1);
            ans = min(ans, get);
        }
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    FOR(i,1,n) {
        cin >> a[i].first >> a[i].second;
    }    
    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof(dp));
    int ans = go(1);
    cout << ans << '\n';
}
