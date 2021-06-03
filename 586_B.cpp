#include<bits/stdc++.h>
#define int long long
using namespace std;



void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define see(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define see(x...)
#endif

int n;
vector<int> a(55,0), b(55,0), c(55,0);

int32_t main(){
   cin >> n;

   for(int i = 2; i <= n; i++)
      cin >> a[i], a[i] += a[i-1];

   for(int i = 1; i <= n-1; i++)
      cin >> b[i];

   for(int i = n-1; i >= 1; i--)
      b[i] += b[i+1];

   for(int i = 1; i <= n; i++)
      cin >> c[i];

   // see(a);
   // see(b);
   // see(c);
   

   int ans = 1e18;

   for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
            if(i != j){
               int curr = b[j] + c[j] + a[j] + a[i] + c[i] + b[i];
               ans = min(ans, curr);
            }
      }
   }
   cout << ans << endl;
}