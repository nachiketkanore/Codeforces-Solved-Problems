#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 1e5 + 2, inf = 1e18;

void solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    int ans = inf;
    for(int i = 1; i * i <= n; i++) if(n % i == 0){
        int fi = i, se = n/i;
        if(fi <= k)
            ans = min(ans, se);
        if(se <= k)
            ans = min(ans, fi);
    }
    cout << ans << '\n';
}