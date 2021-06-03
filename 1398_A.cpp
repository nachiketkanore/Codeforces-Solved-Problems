#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; (L <= R? i <= R : i >= R); (L <= R? i += 1 : i -= 1))
#define int long long

const int N = 2e5 + 2, inf = 1e18;

void solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);  

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    int n;
    cin >> n;
    int a[n + 2] = {};
    FOR(i,1,n) {
        cin >> a[i];
    }
    int one = a[1], two = a[2], last = a[n];
    if(one + two <= last) {
        cout << 1 << ' ' << 2 << ' ' << n << '\n';
        return ;
    }
    cout << -1 << '\n';
}
