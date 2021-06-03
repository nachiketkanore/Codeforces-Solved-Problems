#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 30 + 2, inf = 1e18;

int n, m;
bool mat[N][N];
int ret[N][N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        FOR(i,1,n) FOR(j,1,m) cin >> mat[i][j];
        memset(ret, -1, sizeof(ret));

        pair<int,int> chk[max(n,m) + 2];
        int mx = 0;

        FOR(i,1,n) FOR(j,1,m){
            int d1 = abs(i - 1) + abs(j - 1);
            int d2 = abs(n - i) + abs(m - j);
            int x = min(d1,d2);
            if(d1 == d2) continue;
            mx = max(mx, x);
           // cout << x << " \n"[j == m];
            chk[x].first += mat[i][j] == 0;
            chk[x].second += mat[i][j] == 1;
        }
        int ans = 0;
        FOR(i,0,max(n,m) + 1){

            ans += min(chk[i].first, chk[i].second);
        }
            cout << ans;
        cout << '\n';
    }
}
