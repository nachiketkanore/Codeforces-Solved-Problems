#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e16;

int n, k;
string s, t;
char fi, se;
int dp[202][202][202];

int go(int id, int changes, int occ1) {
    if (changes > k) 
        return -inf;
    if (id == n)
        return 0;

    int &ans = dp[id][changes][occ1];
    if (~ans)
        return ans;
    ans = 0;

    if (s[id] == se) {
        int get = occ1 + go(id + 1, changes, occ1 + (s[id] == fi));
        ans = max(ans, get);
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        int get = 0;
        if (ch == se) {
            get = occ1 + go(id + 1, changes + (s[id] != ch), occ1 + (ch == fi));
        } else {
            get = go(id + 1, changes + (s[id] != ch), occ1 + (ch == fi));
        }
        ans = max(ans, get);
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cin >> s;
    cin >> t;
    fi = t[0];
    se = t[1];

    memset(dp, -1, sizeof(dp));
    int ans = go(0,0,0);
    cout << ans;    
}
