/*
Author: Nachiket Kanore
Created: Sunday 07 March 2021 05:27:03 AM IST
 Reality is merely an illusion, albeit a very persistent one.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 2e5 + 5;
int n, a[N], b[N], ans;


//can be used for Range min/max/gcd range query in O(1)
class sparseTable{
    public:
        int RMQ1[20][N];
        int RMQ2[20][N];
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
                RMQ1[0][i]=a[i]; //leaf value
                RMQ2[0][i]=b[i]; //leaf value
                int mxj=floorlog[n-i+1]; //2^j <= n-i+1
                int pw=1;
                for(int j=1;j<=mxj;j++)
                {
                    RMQ1[j][i]=max(RMQ1[j-1][i], RMQ1[j-1][i+pw]); //operation
                    RMQ2[j][i]=min(RMQ2[j-1][i], RMQ2[j-1][i+pw]); //operation
                    pw<<=1;
                }
            }   
        }

        int query1(int L, int R)
        {
            int k=floorlog[R-L+1]; //2^k <= R-L+1
            return max(RMQ1[k][L], RMQ1[k][R - (1<<k) +1]); //operation
        }

        int query2(int L, int R)
        {
            int k=floorlog[R-L+1]; //2^k <= R-L+1
            return min(RMQ2[k][L], RMQ2[k][R - (1<<k) +1]); //operation
        }
} T;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    FOR (i,1,n) cin >> a[i];
    FOR (i,1,n) cin >> b[i];
    T.precompute(n);
    FOR (L,1,n) {
        int R1 = -1, R2 = -1;
        int lo = L, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int diff = T.query1(L, mid) - T.query2(L, mid);
            if (diff == 0) {
                R1 = mid;
                hi = mid - 1;
            } else if (diff < 0) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        lo = L, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            int diff = T.query1(L, mid) - T.query2(L, mid);
            if (diff == 0) {
                R2 = mid;
                lo = mid + 1;
            } else if (diff < 0) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (~R2) {
            assert(~R1);
            assert(R2 >= R1);
            ans += R2 - R1 + 1;
        }
    }
    cout << ans << '\n';
}