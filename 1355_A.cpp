/*Falling != Failing*/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 2e5 + 2, inf = 1e18, mod = 1e9 + 7; 

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
    int a1, k;
    cin >> a1 >> k;
    int prev = a1;
    if(k == 1){
        cout << prev << '\n';
        return;
    }
    int ans = a1;
    for(int i = 2; i <= k; i++){
        int mn = inf, mx = -inf;
        int val = prev;
        while(val){
            mn = min(mn, val % 10);
            mx = max(mx, val % 10);
            val /= 10;
        }
        ans = prev + mn * mx;
        if(ans == prev)
            break;
        prev = ans;
    }
    cout << ans << '\n';
}
