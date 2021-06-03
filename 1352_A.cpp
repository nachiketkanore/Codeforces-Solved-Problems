#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;

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
    std::vector<int> p;
    string s = to_string(n);
    for(int i = 0; i < sz(s); i++){
        if(s[i] != '0'){
            int ans = s[i] - '0';
            int zero = sz(s) - i - 1;
            while(zero--)
                ans = ans * 10;
            p.push_back(ans);
        }
    }
    cout << sz(p) << '\n';
    for(int x : p)
        cout << x << " ";
    cout << '\n';
}