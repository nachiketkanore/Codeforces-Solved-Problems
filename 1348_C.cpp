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
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    
    if(s[k - 1] != s[0]) {
        cout << s[k - 1] << '\n';
    }
    else {
        cout << s[0];
        if(s[n - 1] == s[k]) {
            for(int i = k; i < n; i += k) {
                cout << s[k];
            }
        }
        else {
            for(int i = k; i < n; i++) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}