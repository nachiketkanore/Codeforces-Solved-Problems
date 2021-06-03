#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

vector<int> occ[26];

int getid(int x, int L){
   auto it = lower_bound(occ[x].begin(), occ[x].end(), L);
   if(it == occ[x].end())
      return -1;
   return *it;
}

void __print(int x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define see(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define see(x...)
#endif

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   string s, t;
   cin >> s >> t;
   int fs[26] = {0};
   int ft[26] = {0};
   for(char ch : s) fs[ch - 'a']++;
   for(char ch : t) ft[ch - 'a']++;
   FOR(i,0,25){
      if(ft[i] > 0 && fs[i] == 0){
         cout << -1;
         return 0;
      }
   }

   int n = sz(s), m = sz(t);
   int idx = 0;
   for(char ch : s)
      occ[ch - 'a'].push_back(idx++);
   int ans = 1;
   int curr = 0;

   FOR(i,0,m-1){
      int want = t[i] - 'a';
      int id = getid(want, curr);
      if(id == -1){
         curr = 0;
         ans++;
         id = getid(want, curr);
      }
      curr = id + 1;
   }
   cout << ans;
}
