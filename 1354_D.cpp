#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())

int n, q, k;

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

    void updateMax(int idx, int val)
    {
        while(idx <= N)
        {
            bit[idx] = max(bit[idx], val);
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

    int rsum(int l, int r)
    {
        return pref(r) - pref(l - 1);
    }

    int prefMax(int idx)
    {
        int ans = -2e9;
        while(idx > 0)
        {
            ans = max(ans, bit[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
} T;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n >> q;
    T.init(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> k;
        T.update(k, 1);
    }

    while(q--){
        cin >> k;
        if(k > 0){
            T.update(k, 1);
        }else{
            k = -k;
            int lo = 1, hi = n, ans = n;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                int cnt = T.pref(mid);
                if(cnt >= k)
                    ans = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
            T.update(ans, -1);
        }
    }
    for(int i = 1; i <= n; i++){
        if(T.rsum(i - 1, i)){
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
}
