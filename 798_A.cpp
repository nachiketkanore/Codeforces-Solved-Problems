#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

bool pal(string &s){
   int l = 0, r = sz(s) - 1;
   bool ans = 1;
   while(l < r)
      ans &= s[l++] == s[r--];
   return ans;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   string s;
   cin >> s;
   string t = s;
   bool ans = false;

   FOR(i,0,sz(s)-1){
      FOR(ch,0,25){
         t[i] = (char)('a' + ch);
         if(t == s) continue;
         ans |= pal(t);
      }
      t[i] = s[i];
   }
   cout << (ans ? "YES" : "NO");
}
