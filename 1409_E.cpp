#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 3e5 + 2, inf = 1e18;

pair<int,int> xy[N];
int n, k;
int dp[N][3];

int get_next_id(int from, int val) {
    // return largest id >= from, such that x[id] <= val
    int ret = -1;
    int lo = from, hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (xy[mid].first <= val) {
            ret = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    assert(~ret);
    return ret;
}

int get_sum(int L, int R) {
    return R - L + 1;
}

int go(int id, int taken) {
    if (taken == 2)
        return 0;
    if (id > n)
        return 0;

    int &ans = dp[id][taken];
    if (~ans)
        return ans;

    ans = go(id + 1, taken);

    // put 1 platform starting from x[id]
    // next id = upper_bound(x[id] + k)
    
    int right_bound = xy[id].first + k;
    int right_id = get_next_id(id, right_bound);
    assert(xy[right_id].first <= right_bound);

    int c1 = get_sum(id, right_id) + go(right_id + 1, taken + 1);
    ans = max(ans, c1);

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--){
        cin >> n >> k;
        FOR(i,1,n) cin >> xy[i].first;
        FOR(i,1,n) cin >> xy[i].second;
        FOR(i,0,n+2) dp[i][0] = dp[i][1] = dp[i][2] = -1;

        sort(xy + 1, xy + n + 1);

        int ans = go(1,0);
        cout << ans << '\n';
    }
}