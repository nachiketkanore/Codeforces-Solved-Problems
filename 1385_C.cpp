#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
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

    function<bool(int)> chk = [&](int id) {
        int prev = -1;
        int L = id, R = n;
        while(L <= R) {
            int mn = min(a[L], a[R]);
            if(mn < prev) 
                return false;
            if(mn == a[L]) {
                prev = mn;
                L++;
            }else {
                prev = mn;
                R--;
            }
        }
        return true;
    };

    int lo = 0, hi = n;
    int ans = n;
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        if(chk(mid + 1)) {
            ans = mid;
            hi = mid - 1;
        }else {
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
}
