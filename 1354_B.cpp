#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
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
    string s;
    cin >> s;
    int ans = inf;
    int idx[4];
    memset(idx, -1, sizeof(idx));

    for(int i = 0; i < sz(s); i++){
        int z = s[i] - '0', x, y;
        if(z == 1)  x = 2, y = 3;
        else if(z == 2) x = 1, y = 3;
        else x = 1, y = 2;
        if(~idx[x] && ~idx[y]){
            int j = min(idx[x], idx[y]);
            ans = min(ans, i - j + 1);
        }
        idx[z] = i;
    }
    if(ans == inf)
        ans = 0;
    cout << ans << '\n';
}
