#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 20, inf = 1e18, mod = 1e9 + 7;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  

   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   string s;
   cin >> s;
   int n = sz(s);
   s = "#" + s;
   int ans = 0;
   for(int i = 2; i <= n; i++){
      int x = (s[i - 1] - '0') * 10 + (s[i] - '0');
      if(x % 4 == 0){
         ans += i - 1;
      }
   }
   for(int i = 1; i <= n; i++)
      ans += (s[i] - '0') % 4 == 0;
   cout << ans;
}