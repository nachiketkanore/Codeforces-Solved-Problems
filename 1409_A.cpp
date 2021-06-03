#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

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
    int L, R;
    cin >> L >> R;
    if (L > R) swap(L, R);
    int ans = 0;

    for (int add = 10; add >= 1; add--) {
        int cnt = (R - L)/add;
        ans += cnt;
        L += cnt * add;
    }

    assert(L == R);
    cout << ans << '\n';
}
