#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int mod = 1e9 + 7, inf = 1e18;

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
   int a[n + 2] = {0};
   int dp[n + 2];
   fill(dp, dp + n + 2, 1LL);
   for(int i = 1; i <= n; i++){
      cin >> a[i];
   }
   int ans = 1;
   for(int i = 1; i <= n; i++){
      for(int j = 2*i; j <= n; j+=i){
         if(a[j] > a[i])
            dp[j] = max(dp[j], dp[i] + 1);
      }
   }
   for(int i = 1; i <= n; i++)
      ans = max(ans, dp[i]);
   cout << ans << '\n';
}