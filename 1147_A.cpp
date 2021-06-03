#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, k, u, f[N], ans, a[N], id[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   cin >> n >> k;
   FOR(i,1,k){
      cin >> a[i];
      id[a[i]] = i;
   }
   set<pair<int,int>> chk;
   FOR(i,1,n){
      chk.insert({i,i});
      if(i + 1 <= n) chk.insert({i,i+1});
      if(i - 1 >= 1) chk.insert({i,i-1});
   }

   FOR(i,1,k){
      if(chk.find({a[i],a[i]}) != chk.end())
         chk.erase(chk.find({a[i],a[i]}));
      int u = a[i], v;
      if(u + 1 <= n){
         v = u + 1;
         if(id[v] > i){
            if(chk.find({u,v}) != chk.end())
               chk.erase(chk.find({u,v}));
         }
      }
      if(u - 1 >= 1){
         v = u - 1;
         if(id[v] > i){
            if(chk.find({u,v}) != chk.end())
               chk.erase(chk.find({u,v}));
         }
      }
   }

   cout << sz(chk) << '\n';
}
