#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    
    int sum = 0, mx = 0;

    for(int i = 0, u; i < n; i++) {
        cin >> u;
        sum += u;
        mx = max(mx, u);
    }

    bool ans = (sum % 2 == 0) && (mx <= (sum - mx));

    cout << (ans ? "YES" : "NO") << "\n";
}
