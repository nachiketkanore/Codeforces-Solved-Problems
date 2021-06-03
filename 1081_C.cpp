#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 2e3 + 3, inf = 1e18, mod = 998244353;

int n, m, k, dp[N][N];

int go(int id, int diff){
    if(diff > k)
        return 0;
    if(id > n)
        return diff == k;

    int &ways = dp[id][diff];
    if(~ways)
        return ways;

    int c1 = (m - 1) * go(id + 1, diff + 1);
    int c2 = go(id + 1, diff);
    ways = (c1 + c2) % mod;
    return ways;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    cout << (m * go(2, 0)) % mod;
}
