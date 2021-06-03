#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;

void solve();

int n, u, v, m;
vector<int> g[N];
vector<int> counts;

int dfs(int u, int par) {
    int subtree_size = 1;
    for(int v : g[u]) if(par != v) {
        subtree_size += dfs(v, u);
    }
    if(~par) {
        int cnt = subtree_size * (n - subtree_size);
        counts.push_back(cnt);
    }
    return subtree_size;
}

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
    cin >> n;
    FOR(i,2,n) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    assert(sz(counts) == n - 1);
    sort(counts.begin(), counts.end());
    cin >> m;
    vector<int> primes(m);
    for(int &x : primes) {
        cin >> x;
    }
    if(m < n - 1) {
        int add = n - 1 - m;
        FOR(i,1,add) primes.push_back(1);
        sort(primes.begin(), primes.end());
    }else {
        sort(primes.begin(), primes.end());
        while(sz(primes) != n - 1) {
            int last = primes.back();
            primes.pop_back();
            int last2 = primes.back();
            primes.pop_back();
            int add = (last * last2) % mod;
            primes.push_back(add);
        }
    }
    assert(sz(primes) == n - 1 && sz(counts) == n - 1);
    int ans = 0;
    for(int i = sz(primes) - 1; ~i; i--) {
        ans = (ans + counts[i] * primes[i]) % mod;
    }
    cout << ans << '\n';

    FOR(i,1,n) {
        g[i].clear();
        counts.clear();
    }
}
