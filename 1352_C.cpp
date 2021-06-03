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
    int n, k;
    cin >> n >> k;
    int x = (k % (n - 1) == 0 ? k/(n - 1) : k/(n-1) + 1);
    cout << k + x - 1 << '\n';
}