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

   int n;
   cin >> n;
   int each = n*(n*n + 1)/2;
   bool f[n * n + 2];
   FOR(i,1,n*n) f[i] = true;

   int L = 1, R = n * n;

   FOR(i,1,n){
      int give = each;
      while(give != 0){
         cout << L << ' ' << R << ' ';
         give -= L + R;
         L++, R--;
      }
      cout << '\n';
   }
}
