#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

struct BIT
{
    int N;
    vector<int> bit;

    void init(int n)
    {
        N = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val)
    {
        while(idx <= N)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int pref(int idx)
    {
        int ans = 0;
        while(idx > 0)
        {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    void add(int L, int R, int val)
    {
        update(L, val);
        update(R + 1, -val);
    }

    int rsum(int l, int r)
    {
        return pref(r) - pref(l - 1);
    }
} ans;

int n, m, k, a[N], l[N], r[N], add[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n >> m >> k;
    ans.init(n);
    FOR(i,1,n) {
        cin >> a[i];
    }
    FOR(i,1,m) {
        cin >> l[i] >> r[i] >> add[i];
    }
    BIT operationCounter;
    operationCounter.init(m);

    FOR(i,1,k){
        int from, to;
        cin >> from >> to;
        operationCounter.add(from, to, 1);
    }

    FOR(i,1,m) {
        int howManyTimes = operationCounter.pref(i);
        ans.add(l[i], r[i], howManyTimes * add[i]);
    }

    FOR(i,1,n) {
        cout << (a[i] + ans.pref(i)) << ' ';
    }
}
