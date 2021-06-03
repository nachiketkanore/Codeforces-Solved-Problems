#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 202, inf = 1e18, mod = 1e9 + 7;

int n, k, d, dp[N*N][N][2];

int go(int id, int path, bool has){
    if(path > n)
        return 0;
    if(path == n)
        return has;
    int &ans = dp[id][path][has];
    if(~ans)
        return ans;
    ans = 0;
    for(int e = 1; e <= k; e++)
        ans = (ans + go(id + 1, path + e, has || (e >= d))) % mod;
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    memset(dp, -1, sizeof(dp)); 
    cin >> n >> k >> d;
    cout << go(1, 0, 0);
}
