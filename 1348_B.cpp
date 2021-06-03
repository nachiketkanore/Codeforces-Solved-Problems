#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5e5 + 5, mod = 1e9 + 7, inf = 1e17;

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
    int n, k;
    cin >> n >> k;
    set<int> f;
    for(int i = 0, u; i < n; i++){
        cin >> u;
        f.insert(u);
    }
    if(sz(f) > k){
        cout << "-1\n";
        return;
    }
    string ans;
    int num = 1;
    while(sz(f) < k)
        f.insert(num++);
    for(int x : f)
        ans = ans + (to_string(x) + " ");
    cout << n * k << '\n';
    while(n--)
        cout << ans;
    cout << '\n';
}