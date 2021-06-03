#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, a[N], b[N], c[N], dp[2][N];

int go(int id, int prevDone){
    if(id == n){
        return ( prevDone ? b[id] : a[id]);
    }
    int &ans = dp[prevDone][id];
    if(~ans)
        return ans;
    ans = 0;

    if(prevDone){
        int c1 = b[id] + go(id + 1, 1);
        int c2 = c[id] + go(id + 1, 0);
        ans = max(c1, c2);
    }
    else{
        int c1 = a[id] + go(id + 1, 1);
        int c2 = b[id] + go(id + 1, 0);
        ans = max(c1, c2);
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];
    FOR(i,1,n) cin >> c[i];

    memset(dp, -1, sizeof(dp));
    int ans = go(1,0);
    cout << ans << '\n';
}
