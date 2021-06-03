#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e3 + 5, mod = 1e9 + 7;

int n, m, d, dp[N][N][2][2][2];
string A, B;

int go(int pos, int rem, bool bigA, bool smallB, bool evenPos){
    if(pos >= n)
        return rem == 0;

    int &ans = dp[pos][rem][bigA][smallB][evenPos];
    if(~ans)
        return ans;
    ans = 0;
    for(int i = 0; i < 10; i++){
        if(!bigA && i < A[pos] - '0')   continue;
        if(!smallB && i > B[pos] - '0') continue;
        if(evenPos){ if(i == d)
            ans = (ans + go(pos + 1, (10*rem + i) % m, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), 1^evenPos)) % mod;
        }else if(i != d){
            ans = (ans + go(pos + 1, (10*rem + i) % m, bigA || (i > A[pos] - '0'), smallB || (i < B[pos] - '0'), 1^evenPos)) % mod;
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

    memset(dp, -1, sizeof(dp));
    cin >> m >> d;
    cin >> A >> B;
    n = sz(A);
    int ans = 0;
    for(int i = 0; i < 10; i++){
        if(i < A[0] - '0')  continue;
        if(i > B[0] - '0')  continue;
        if(i == d)          continue;
        int add = go(1, i % m, i > A[0] - '0', i < B[0] - '0', 1);
        ans = (ans + add) % mod;
    }
    cout << ans;
}