#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 4e5 + 5, mod = 1e9 + 7, inf = 1e18;

void solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}

void solve(){
    int n, sum = 0, u, ans = 0, id = -1;
    cin >> n;
    map<int,int> pos;
    pos[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> u;
        sum += u;
        if(pos.count(sum))
            id = max(id, pos[sum]);
        ans += i - id - 1;
        pos[sum] = i;
    }
    cout << ans << '\n';
}