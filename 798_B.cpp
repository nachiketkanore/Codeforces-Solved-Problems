#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, ans = inf;
string s[N];
string t;

string get(string s, int left){
   return s.substr(left) + s.substr(0,left);
}

int go(string make){

   int cost = 0;

   FOR(i,2,n){
      bool poss = 0;
      FOR(shift,0,sz(t)-1){
         if(get(s[i], shift) == make){
            poss = 1;
            cost += shift;
            break;
         }
      }
      if(!poss)
         return inf;
   }
   return cost;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   cin >> n;
   FOR(i,1,n) cin >> s[i];
   t = s[1];
   FOR(shift,0,sz(t)-1){
      string shifted = get(t, shift);
      int cost = shift + go(shifted);
      ans = min(ans, cost);
   }
   if(ans == inf)
      ans = -1;
   cout << ans;
}
