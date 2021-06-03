#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int info[10][10][10][10];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    FOR(i,0,9) FOR(j,0,9) FOR(k,0,9) FOR(l,0,9) info[i][j][k][l] = inf;

    FOR(from,0,9) {
        FOR(x,0,9) FOR(y,0,9){
            FOR(t1,0,20) FOR(t2,0,20) if(t1 + t2){
                int mod = (from + t1 * x + t2 * y) % 10;
                info[from][mod][x][y] = min(info[from][mod][x][y], t1 + t2 - 1);
            }
        }
    }

    string s;
    cin >> s;
    FOR(x,0,9) FOR(y,0,9) {
        int ans = 0;
        FOR(i,1,sz(s)-1){
            int from = s[i - 1] - '0';
            int to = s[i] - '0';
            int add = info[from][to][x][y];
            ans += add;
            if(ans >= inf)
                break;
        }
        if(ans >= inf)
            ans = -1;
        cout << (ans) << " \n"[y == 9];
    }
}
