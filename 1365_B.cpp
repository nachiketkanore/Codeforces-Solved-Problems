#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 500 + 2, inf = 1e18;

struct DSU
{
    int connected;
    int par[N], sz[N];
 
    void init(int n) 
    {
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
        connected=n;
    }
 
    int getPar(int k)
    {
        while(k!=par[k])
        {
            par[k]=par[par[k]];
            k=par[k];
        }
        return k;
    }
 
    int getSize(int k)
    {
        return sz[getPar(k)];
    }

    bool same(int u , int v)
    {
        return (getPar(u) == getPar(v));
    }
 
    bool unite(int u, int v)
    {
        int par1=getPar(u), par2=getPar(v);
 
        if(par1==par2)
            return false;
 
        connected--;
 
        if(sz[par1]>sz[par2])
            swap(par1, par2);
 
        sz[par2]+=sz[par1];
        sz[par1]=0;
        par[par1]=par[par2];
        return true;
    }
};

void solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    int n;
    cin >> n;
    int a[n + 1] = {0};
    int b[n + 1] = {0};
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];

    DSU dsu;
    dsu.init(n);

    FOR(i,1,n) FOR(j,1,n) if(b[i] ^ b[j]){
        dsu.unite(i, j);
        dsu.unite(i, i);
    }

    map<int,vector<int>> f;
    FOR(i,1,n) {
        f[dsu.getPar(i)].push_back(i);
    }
    int ret[n + 1] = {0};

    for(auto &it : f){
        vector<int> values;
        for(auto id : it.second)
            values.push_back(a[id]);
        sort(values.begin(), values.end());
        FOR(i,0,sz(values)-1)
            ret[it.second[i]] = values[i];
    }

    bool sorted = true;
    FOR(i,2,n) sorted &= ret[i] >= ret[i-1];
    cout << (sorted ? "Yes" : "No" ) << '\n';

}
