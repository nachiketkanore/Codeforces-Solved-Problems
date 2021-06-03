#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int n, q, a[N], k, ans, curr;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   cin >> n >> q;
   FOR(i,1,n) {
      cin >> a[i];
      a[i] += a[i - 1];
   }
   FOR(qq,1,q){
      cin >> k;
      curr += k;
      int id = upper_bound(a + 1, a + n + 1, curr) - a - 1; //zero-based index
      if(id == n){
         curr = 0;
         id = 0;
      }
      cout << (n - id) << '\n';
   }
}
