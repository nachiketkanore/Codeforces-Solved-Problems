#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long


void solve();

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    int ans = a * b;

    int diff_a = a - x, diff_b = b - y;

    int N = n;

    int new_a = a - min(n, diff_a);
    n -= min(n, diff_a);
    int new_b = b - min(n, diff_b);
    n -= min(n, diff_b);

    ans = min(ans, new_a * new_b);

    n = N;

    new_b = b - min(n, diff_b);
    n -= min(n, diff_b);
    new_a = a - min(n, diff_a);
    n -= min(n, diff_a);

    ans = min(ans, new_b * new_a);

    cout << ans << '\n';
}
