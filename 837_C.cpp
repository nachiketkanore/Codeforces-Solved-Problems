#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 100 + 2, inf = 1e18;

int n, a, b;
int x[N], y[N];
int ans;

bool canFit(int xa, int ya, int x, int y){
    return (x <= xa && y <= ya) || (y <= xa && x <= ya);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n >> a >> b;
    FOR(i,1,n)
        cin >> x[i] >> y[i];
    FOR(i,1,n) FOR(j,1,n) if(i != j) {
        int len = x[i], brd = y[i];
        if(a >= len && b >= brd){
            bool yes = canFit(a - len, b, x[j], y[j]) or canFit(a, b - brd, x[j], y[j]);
            if(yes)
                ans = max(ans, x[i]*y[i] + x[j]*y[j]);
        }
        swap(len, brd);
        if(a >= len && b >= brd){
            bool yes = canFit(a - len, b, x[j], y[j]) or canFit(a, b - brd, x[j], y[j]);
            if(yes)
                ans = max(ans, x[i]*y[i] + x[j]*y[j]);
        }
    }
    cout << ans;
}
