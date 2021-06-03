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
    std::vector<int> one, two;
    map<int,int> cnt;
    FOR(i,1,2*n) {
        int u;
        cin >> u;
        if(cnt.count(u))
            two.push_back(u);
        else {
            one.push_back(u);
            cnt[u] = 1;
        }
    }    
    assert(one == two);
    for(int x : one)
        cout << x << ' ';
    cout << '\n';
}
