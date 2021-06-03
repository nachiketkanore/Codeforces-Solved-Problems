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

   int tt = 1;
   cin >> tt;
   while(tt--){
      int n, k;
      cin >> n >> k;
      FOR(i,0,n-1){
         cout << (char)('a' + (i % k));
      }  cout << '\n';
   }
}
