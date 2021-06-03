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
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    bool pal = true;
    int l = 0, r = sz(s) - 1;
    while(l < r)
        pal &= s[l++] == s[r--];
    cout << (pal ? "-1" : s) << '\n';
}