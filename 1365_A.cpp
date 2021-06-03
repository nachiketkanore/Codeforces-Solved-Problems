#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

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
    int n, m;
    cin >> n >> m;
    int mat[n + 1][m + 1];
    FOR(i,1,n) FOR(j,1,m) cin >> mat[i][j];
    int rows = 0, cols = 0;
    FOR(i,1,n){
        int sum = 0;
        FOR(j,1,m) sum += mat[i][j];
        if(sum == 0)
            rows++;
    }
    FOR(j,1,m) {
        int sum = 0;
        FOR(i,1,n) sum += mat[i][j];
        if(sum == 0)
            cols++;
    }
    int chk = min(rows, cols);
    cout << (chk&1 ? "Ashish" : "Vivek") << "\n";
}
