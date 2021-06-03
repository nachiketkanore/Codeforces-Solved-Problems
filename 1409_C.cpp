#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int inf = 1e18;

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
    int n, x, y;
    cin >> n >> x >> y;

    int T = y - x;
    vector<int> diffs;

    for (int i = 1; i <= T; i++) if (T % i == 0) {
        diffs.push_back(i);
    }

    vector<int> ans;
    int fin_mx = inf;

    sort(diffs.begin(), diffs.end());

    for (int d : diffs) {

        vector<int> a;
        int add = x;
        while (1) {
            if (add > y || sz(a) >= n) break;
            a.push_back(add);
            add += d;
        }
        add = x - d;
        reverse(a.begin(), a.end());
        while (1) {
            if (add <= 0 || sz(a) >= n) break;
            a.push_back(add);
            add -= d;
        }

        reverse(a.begin(), a.end());

        add = y + d;
        while (sz(a) < n) {
            a.push_back(add);
            add += d;
        }

        bool chk_y = false;
        bool chk_x = false;

        for (int val : a) {
            chk_x |= val == x;
            chk_y |= val == y;
        }

        if (chk_y && chk_x) {
            int mx = a.back();
            if (mx < fin_mx) {
                fin_mx = mx;
                ans = a;
            }
        }

    }

    for (int val : ans) {
        cout << val << ' ';
    }   cout << '\n';
}
