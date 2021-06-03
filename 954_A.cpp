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
   vector<char> a;
   char ch;
   FOR(i,1,n){
      cin >> ch;
      if(sz(a) == 0)
         a.push_back(ch);
      else{
         if((ch == 'U' && a.back() == 'R') || (ch == 'R' && a.back() == 'U')){
            a.pop_back();
            a.push_back('D');
         }else
            a.push_back(ch);
      }
   }
   cout << sz(a);
}
