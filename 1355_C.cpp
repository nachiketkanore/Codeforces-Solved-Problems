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
    //cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    int a , b , c , d;
    cin >> a >> b >> c >> d;

    int ans = 0;

    for(int i = max(a + b , c); i <= c + d ;i++){
        int val1 = min(i - c, d - c + 1);
        int val2 = i - a - b + 1;
        int x = -max(0LL,i - b - b) - max(0LL, i - a - c) + max(0LL, i - b - c - 1);
        ans += val1 * (val2 + x);
    }
    cout << ans << endl;
}
