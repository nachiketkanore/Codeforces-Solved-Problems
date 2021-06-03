#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int tt;
    cin >> tt;
    while(tt--){
        int a, b, n;
        cin >> a >> b >> n;
        if(a > n or b > n){
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        while(max(a,b) <= n){
            ++ans;
            if(a >= b){
                b += a;
            }
            else{
                a += b;
            }
        }
        cout << ans << "\n";
    }
}
