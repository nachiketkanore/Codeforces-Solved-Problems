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
    cin >> t;
    while(t--)
        solve();
}

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    bool neg = false, pos = false;
    bool ans = true;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) {
            pos |= a[i] > 0, neg |= a[i] < 0;
            continue;
        }
        int make = b[i] - a[i];
        if(make < 0){
            ans &= neg;
        }else{
            ans &= pos;
        }
        pos |= a[i] > 0;
        neg |= a[i] < 0;
    }
    cout << (ans ? "YES" : "NO" ) << '\n';
}