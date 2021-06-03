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
    int n;
    cin >> n;
    int val = n;
    int two = 0, three = 0;
    while(val % 2 == 0) val /= 2, ++two;
    while(val % 3 == 0) val /= 3, ++three;
    if(two > three or val != 1){
        cout << -1 << '\n';
    }else{
        int ans = (three - two) + three;
        cout << ans << '\n';
    }
}
