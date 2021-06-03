#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int n,m;
   cin >> n >> m;
   int ans = 0;

   FOR(i,1,n) {
      int row_min = inf;
      FOR(j,1,m){
         int u;
         cin >> u;
         row_min = min(row_min, u);
      }
      ans = max(ans, row_min);
   }
   cout << ans;
}
