#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;

int fact[2000000];

int power(int a, int b, int p = mod){
    int ret = 1;
    a %= p;
    while(b > 0){
        if(b % 2 == 1)
            ret = ret * a % p;
        b /= 2;
        a = a * a % p;
    }
    return ret;
}

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

int n;

bool chk(std::vector<int> &p) {
    vector<pair<int,int>> edges;
    for(int i = 0; i < n; i++) {
        int right = -1;
        for(int j = i + 1; j < n; j++) {
            if(p[i] < p[j]) {
                right = j;
                break;
            }
        }

        int left = -1;
        for(int j = i - 1; j >= 0; j--) {
            if(p[i] < p[j]) {
                left = j;
                break;
            }
        }
        if(~left) {
            edges.push_back({i, left});
        }
        if(~right) {
            edges.push_back({i, right});
        }
    }

    bool cyc = false;
    DSU dsu;
    dsu.init(n);
    for(auto &e : edges) {
        int u = e.first + 1, v = e.second + 1;
        if(dsu.getPar(u) == dsu.getPar(v))
            return 1;
        dsu.unite(u, v);
    }
    return false;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // n = 1 , ans = 0
    // n = 2 , ans = 0
    // n = 3 , ans = 2
    // n = 4 , ans = 16
    // n = 5 , ans = 104
    // n = 6 , ans = 688
    // n = 7 , ans = 4976
    // n = 8 , ans = 40192
    // n = 9 , ans = 362624
    // n = 10 , ans = 3628288
    // Found on OEIS

    fact[0] = 1;
    for(int i = 1; i < 1000005; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }

    cin >> n;
    int ans = fact[n] - power(2, n - 1) + 10000000LL * mod;
    ans %= mod;
    cout << ans << '\n';
    return 0;

    for(int xx = 1; xx <= 7; xx++){
        std::vector<int> perm;
    
        n = xx;
        for(int i = 1; i <= n; i++) {
            perm.push_back(i);
        }
    
        int ans = 0;
        int fake = fact[n] - power(2, n - 1);
        fake = (fake + mod) % mod;

    
        do {
            if(chk(perm)) {
                ++ans;
            }
        }while(next_permutation(perm.begin(), perm.end()));
    
        cout << "n = " << n << " , ans = " << ans << " $" << fake << '\n';
    }
}
