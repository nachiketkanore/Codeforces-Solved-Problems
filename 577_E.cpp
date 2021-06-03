#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<array<int,3>> pts[1002];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    FOR(i,1,n) {
        int x, y;
        cin >> x >> y;
        pts[y/1000].push_back({x, y, i});
    }

    FOR(i,0,1001) {
        if (i & 1) 
            sort(pts[i].rbegin(), pts[i].rend());
        else
            sort(pts[i].begin(), pts[i].end());

        for (auto& it : pts[i]) 
            cout << it[2] << ' ';
    }

}
