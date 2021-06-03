#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, dp[N];

int go(int id){
    if(id > n)
        return id == n + 1 ? 1 : -inf;
    int &ans = dp[id];
    if(~ans)
        return ans;
    return ans = 2*go(id + 2);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    if(n&1){
        return cout << 0, 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << max(0LL, go(1)) << '\n';
}
