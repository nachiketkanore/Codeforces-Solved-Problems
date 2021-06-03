#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 3, mod = 1e9 + 7, inf = 1e18;

int n, m, vis[N], ans, par[N];
std::vector<int> g[N], comp;

int find(int u){
   if(u == par[u])
      return par[u];
   par[u] = find(par[par[u]]);
   return par[u];
}

bool unite(int u, int v){
   u = find(u), v = find(v);
   if(u == v)
      return false;
   par[u] = v;
   return true;
}

void dfs(int u){
   vis[u] = 1;
   comp.push_back(u);
   for(int v : g[u])
      if(!vis[v])
         dfs(v);
}

bool chk(){
   bool cycle = false;
   set<pair<int,int>> e;
   for(int u : comp)
      for(int v : g[u]){
         if(u < v) e.insert({u, v});
         else e.insert({v, u});
      }
   for(auto x : e){
      if(!unite(x.first, x.second))
         cycle = true;
   }
   return cycle == false;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  

   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   cin >> n >> m;
   for(int i = 1; i <= n; i++)
      par[i] = i;
   while(m--){
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   for(int i = 1; i <= n; i++) if(!vis[i]){
      comp.clear();
      dfs(i);
      ans += chk();
   }
   cout << ans;
}
