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
    string s;
    cin >> s;
    int pref_sum = 0;
    map<int,int> cnt;
    cnt[0] = 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        pref_sum += (s[i] - '0');
        ans += cnt[pref_sum - i - 1];
        cnt[pref_sum - i - 1]++;
    }
    cout << ans << '\n';
}
