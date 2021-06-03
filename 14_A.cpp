#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, m;
    cin >> n >> m;
    char mat[n + 1][m + 1];
    int mnX = inf, mxX = 0, mnY = inf, mxY = 0;
    FOR(i,1,n) FOR(j,1,m){
        cin >> mat[i][j];
        if(mat[i][j] == '*'){
            mnX = min(mnX, i);
            mxX = max(mxX, i);
            mnY = min(mnY, j);
            mxY = max(mxY, j);
        }
    }
    FOR(i,mnX,mxX){ 
        FOR(j,mnY,mxY) 
            cout << mat[i][j]; 
        cout << '\n';
    }
}
