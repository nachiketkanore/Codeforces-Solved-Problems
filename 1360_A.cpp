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
    int a, b;
    cin >> a >> b;
    if(a > b)
        swap(a, b);
    a = 2 * a;
    cout << max(a * a, b * b) << '\n';
}