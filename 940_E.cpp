#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, c, a[N];
int dp[N];

//can be used for Range min/max/gcd range query in O(1)
class sparseTable{
    public:
        int RMQ[20][N];
        int floorlog[N];

        void precompute(int n)
        {
            for(int i=0;(1<<i)<N;i++)
            {
                for(int j=(1<<i);j<N && j<(1<<(i+1)); j++)
                    floorlog[j]=i;
            }

            for(int i=n;i>=1;i--)
            {
                RMQ[0][i]=a[i]; //leaf value
                int mxj=floorlog[n-i+1]; //2^j <= n-i+1
                int pw=1;
                for(int j=1;j<=mxj;j++)
                {
                    RMQ[j][i]=min(RMQ[j-1][i], RMQ[j-1][i+pw]); //operation
                    pw<<=1;
                }
            }   
        }

        int query(int L, int R)
        {
            int k=floorlog[R-L+1]; //2^k <= R-L+1
            return min(RMQ[k][L], RMQ[k][R - (1<<k) +1]); //operation
        }
} T;

int get_sum(int L, int R) {
    assert(L >= 1 && L <= R && R <= n);
    return a[R] - a[L - 1];
}

int go(int from) {
    if (from == n + 1)
        return 0;

    int &ans = dp[from];
    if (~ans)
        return ans;
        
    // Optimal jumps : {1, c} only
    
    int c1 = get_sum(from, from) + go(from + 1);
    int c2 = inf;
    if (from + c - 1 <= n) {
        c2 = get_sum(from, from + c - 1) - T.query(from, from + c - 1) + go(from + c);
    }
    return ans = min(c1, c2);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> c;
    FOR(i,1,n) cin >> a[i];    
    T.precompute(n);
    FOR(i,1,n) a[i] += a[i - 1];

    memset(dp, -1, sizeof(dp));
    int ans = go(1);
    cout << ans << '\n';
}
