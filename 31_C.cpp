#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 5000 + 2, inf = 1e18;

set<int> g[N];
int n, L[N], R[N];
bool vis[N];

bool chk(int i, int j) {
    if(R[i] == L[j]) return false;
    if(R[j] == L[i]) return false;
    if(R[i] < L[j]) return false;
    if(R[j] < L[i]) return false;
    return true;
}

void dfs(int u) {
    vis[u] = 1;
    for(int v : g[u]) if(!vis[v]) dfs(v);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    FOR(i,1,n) {
        cin >> L[i] >> R[i];
    }
    FOR(i,1,n) FOR(j,i+1,n) if(chk(i,j) || chk(j,i)) {
        g[i].insert(j);
        g[j].insert(i);
    }

    vector<int> ans;

    FOR(i,1,n) {
        vector<pair<int,int>> removed;

        for(int x : g[i]) {
            removed.push_back({i, x});
        }
        g[i].clear();

        FOR(j,1,n) if(i != j) {
            if(g[j].count(i)) {
                removed.push_back({j, i});
                g[j].erase(g[j].find(i));
            }
        }

        int comps = 0;
        FOR(j,1,n) vis[j] = false;

        FOR(t,1,n) if(!vis[t]) {
            ++comps;
            dfs(t);
        }

        if(comps == n) {
            ans.push_back(i);
        }

        for(auto &it : removed) {
            g[it.first].insert(it.second);
        }
    }

    cout << sz(ans) << '\n';
    for(int x : ans)
        cout << x << ' ';
}
