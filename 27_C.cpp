#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, a[N];

//can be used for Range min/max/gcd range query in O(1)
class sparseTable{
    public:
        int RMnQ[20][N];
        int RMxQ[20][N];
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
                RMnQ[0][i]=a[i]; //leaf value
                RMxQ[0][i]=a[i];
                int mxj=floorlog[n-i+1]; //2^j <= n-i+1
                int pw=1;
                for(int j=1;j<=mxj;j++)
                {
                    RMnQ[j][i]=min(RMnQ[j-1][i], RMnQ[j-1][i+pw]); //operation
                    RMxQ[j][i]=max(RMxQ[j-1][i], RMxQ[j-1][i+pw]); //operation
                    pw<<=1;
                }
            }   
        }

        int qMax(int L, int R)
        {
            int k=floorlog[R-L+1]; //2^k <= R-L+1
            return max(RMxQ[k][L], RMxQ[k][R - (1<<k) +1]); //operation
        }

        int qMin(int L, int R)
        {
            int k=floorlog[R-L+1]; //2^k <= R-L+1
            return min(RMnQ[k][L], RMnQ[k][R - (1<<k) +1]); //operation
        }        
} T;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
    }
    T.precompute(n);

    FOR(i,2,n-1){
        int mid = a[i];
        int leftMin = T.qMin(1,i-1), leftMax = T.qMax(1,i-1);
        int rightMin = T.qMin(i+1,n), rightMax = T.qMax(i+1,n);
        if(leftMin < mid && mid > rightMin){
            cout << 3 << '\n';
            FOR(j,1,i-1) if(a[j] == leftMin) {
                cout << j << ' ';
                break;
            }
            cout << i << ' ';
            FOR(j,i+1,n) if(a[j] == rightMin) {
                cout << j << ' ';
                break;
            }
            return 0;
        }
        if(leftMax > mid && mid < rightMax){
            cout << 3 << '\n';
            FOR(j,1,i-1) if(a[j] == leftMax) {
                cout << j << ' ';
                break;
            }
            cout << i << ' ';
            FOR(j,i+1,n) if(a[j] == rightMax) {
                cout << j << ' ';
                break;
            }
            return 0;
        }
    }
    cout << 0 << '\n';
}
