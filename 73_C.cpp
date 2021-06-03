#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e12;

string s;
int cost[30][30], k, n;
int dp[30][680][102];

int go(int id, int changes, int prev) {
    if (changes > k)
        return -inf;
    if (id == n)
        return 0;

    int &ans = dp[prev][id][changes];
    if (~ans)
        return ans;
    ans = -inf;

    FOR(keep,0,25) {
        int get = cost[prev][keep] + go(id + 1, changes + ((s[id] - 'a') != keep), keep);
        ans = max(ans, get);
    }

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> s >> k;
    n = sz(s);
    int T;
    cin >> T;
    
    while (T--) {
        char x, y;  int t;
        cin >> x >> y >> t;
        cost[x - 'a'][y - 'a'] = t;
    }   

    memset(dp, -1, sizeof(dp));
    int ans = -inf;

    FOR(keep,0,25) {
        int get = go(1,keep != (s[0] - 'a'),keep);
        ans = max(ans, get);
    }
    cout << ans << '\n';
}
