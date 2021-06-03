#include <bits/stdc++.h>
//#define int long long
#define sz(x) (int)(x.size())
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//Use pair<int,int> to support multiset like features
typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

oset pref, suff;

const int N = 1e6 + 3, mod = 1e9 + 7;

int n, a[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  

   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   cin >> n;
   for(int i = 1; i <= n; i++)
      cin >> a[i];
   pref.insert({a[1], 1});
   for(int i = 2; i <= n; i++)
      suff.insert({a[i], i});
   long long ans = 0;
   for(int i = 2; i < n; i++){
      suff.erase({a[i], i});
      int left = sz(pref) - pref.order_of_key({a[i]+1,0});
      int right = suff.order_of_key({a[i], i});
      ans += 1LL * left * right;
      pref.insert({a[i], i});
   }
   cout << ans;
}
