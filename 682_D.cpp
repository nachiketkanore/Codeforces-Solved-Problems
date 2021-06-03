#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e3 + 2, inf = 1e18;

int n, m, k;
string s, t;
int dp[N][N][11];
int common[N][N];

int info(int i, int j){
    if(i >= n or j >= m)
        return 0;
    int &ans = common[i][j];
    if(~ans)
        return ans;
    ans = 0;
    if(s[i] == t[j])
        ans = 1 + info(i + 1, j + 1);
    return ans;
}

int go(int i, int j, int k){
    if(i >= n or j >= m)
        return 0;
    if(k == 0)
        return 0;
    int &ans = dp[i][j][k];
    if(~ans)
        return ans;
    ans = 0;
    ans = max(ans, go(i + 1, j, k));
    ans = max(ans, go(i, j + 1, k));

    int getLen = info(i,j);
    
    if(getLen > 0){
        int get = getLen + go(i + getLen, j + getLen, k - 1);
        ans = max(ans, get);
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
    memset(common, -1, sizeof(common));
    cin >> n >> m >> k;
    cin >> s >> t;
    cout << go(0,0,k);
}
