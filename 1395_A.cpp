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
    int r, g, b, w;
    cin >> r >> g >> b >> w;
    int odds = (r % 2 == 1) + (g % 2 == 1) + (b % 2 == 1) + (w % 2 == 1);
    if(odds <= 1) {
        cout << "Yes" << '\n';
        return;
    }
    for(int rem = 0; rem <= 250; rem++) {
        if(min({r, g, b}) >= rem) {
            int nr = r - rem;
            int ng = g - rem;
            int nb = b - rem;
            int nw = w + rem;
            int calc = (nr % 2 == 1) + (ng % 2 == 1) + (nb % 2 == 1) + (nw % 2 == 1);
            if(calc <= 1) {
                cout << "Yes" << '\n';
                return ;
            }
        }
    }
    cout << "No" << '\n';
}
