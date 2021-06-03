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
    int a, b;
    cin >> a >> b;
    int twos = 0;
    while(a < b)
    	twos++, a <<= 1;
    while(a > b && a % 2 == 0)
    	twos++, a /= 2;
    if(a != b){
    	cout << -1 << '\n';
    	return;
    }
    int ans = 0;
    ans += twos/3;
    twos %= 3;
    ans += twos/2;
    twos %= 2;
    ans += twos;
    cout << ans << '\n';
}
