#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 50 + 2, inf = 1e18;

char mat[N][N];

int n, dp[N][N];;

bool go(int i, int j){
    if(mat[i][j] == '0')
        return false;
    if(i == n || j == n)
        return true;
    int &ans = dp[i][j];
    if(~ans)
        return ans;
    bool chk = false;
    if(i + 1 <= n)
        chk |= go(i + 1, j);
    if(j + 1 <= n)
        chk |= go(i, j + 1);
    return ans = chk;
}

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

    memset(dp, -1, sizeof(dp));
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> mat[i][j], sum += mat[i][j] - '0';

    bool ans = true;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) if(mat[i][j] == '1'){
        bool chk = i == n || j == n;
        if(i + 1 <= n)
            chk |= go(i + 1, j);
        if(j + 1 <= n)
            chk |= go(i, j + 1);
        ans &= chk;
    }

    cout << (ans ? "YES" : "NO") << '\n';
}