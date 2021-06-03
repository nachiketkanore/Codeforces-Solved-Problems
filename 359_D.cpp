#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 3e5 + 2;

int n;
int arr[N];

int gcd(int a, int b) { 
    if(a == 0 && b == 0) return 0;
    return b == 0 ? a : gcd(b, a % b); 
}

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
                RMQ[0][i]=arr[i]; 
                int mxj=floorlog[n-i+1]; //2^j <= n-i+1
                int pw=1;
                for(int j=1;j<=mxj;j++)
                {
                    RMQ[j][i]=gcd(RMQ[j-1][i], RMQ[j-1][i+pw]);
                    pw<<=1;
                }
            }   
        }

        int query(int L, int R)
        {
            int k=floorlog[R-L+1]; //2^k <= R-L+1
            return gcd(RMQ[k][L], RMQ[k][R - (1<<k) +1]);
        }
} T;

int getLeft(int L, int R, int G){
    int ans = R;
    while(L <= R){
        int mid = (L + R)/2;
        int GCD = T.query(mid, R);
        if(GCD % G == 0){
            ans = min(ans, mid);
            R = mid - 1;
        }else{
            L = mid + 1;
        }
    }
    return ans;
}

int getRight(int L, int R, int G){
    int ans = L;
    while(L <= R){
        int mid = (L + R)/2;
        int GCD = T.query(L, mid);
        if(GCD % G == 0){
            ans = max(ans, mid);
            L = mid + 1;
        }else{
            R = mid - 1;
        }
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    FOR(i,1,n)
        cin >> arr[i];

    T.precompute(n);

    int mxLen = -1;
    set<int> ans;

    FOR(i,1,n){
        int val = arr[i];
        int L = getLeft(1,i,val);
        int R = getRight(i,n,val);
        if(R - L > mxLen){
            ans.clear();
            mxLen = R - L;
            ans.insert(L);
        }else if(R - L == mxLen){
            ans.insert(L);
        }
    }
    cout << sz(ans) << ' ' << mxLen << '\n';
    for(int it : ans)
        cout << it << ' ';
}
