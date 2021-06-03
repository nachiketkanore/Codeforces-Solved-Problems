#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e6 + 2, M = 1e3 + 2, inf = 1e18;

int n, m;
char mat[M][M];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool inside(int x, int y){
   return x >= 1 && x <= n && y >= 1 && y <= m;
}

struct DSU
{
   int connected;
   int par[N], sz[N];
 
   void init(int n) 
   {
      for(int i=1;i<=n;i++)
      {
         par[i]=i;
         sz[i]=1;
      }
      connected=n;
   }
 
   int getPar(int k)
   {
      while(k!=par[k])
      {
         par[k]=par[par[k]];
         k=par[k];
      }
      return k;
   }
 
   int getSize(int k)
   {
      return sz[getPar(k)];
   }

   bool same(int u , int v)
   {
      return (getPar(u) == getPar(v));
   }
 
   bool unite(int u, int v)
   {
      int par1=getPar(u), par2=getPar(v);
 
      if(par1==par2)
         return false;
 
      connected--;
 
      if(sz[par1]>sz[par2])
         swap(par1, par2);
 
      sz[par2]+=sz[par1];
      sz[par1]=0;
      par[par1]=par[par2];
      return true;
   }
} dsu;

int node(int i, int j){
   return (i - 1) * m + j;
}


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   cin >> n >> m;
   dsu.init(n*m);
   FOR(i,1,n) FOR(j,1,m) cin >> mat[i][j];
   FOR(i,1,n) FOR(j,1,m) if(mat[i][j] == '.'){
      FOR(k,0,3) if(inside(dx[k] + i, dy[k] + j) && mat[dx[k] + i][dy[k] + j] == '.'){
         int x = i + dx[k], y = j + dy[k];
         int u = (i - 1) * m + j;
         int v = (x - 1) * m + y;
         dsu.unite(u,v);
      }
   }
   FOR(i,1,n) FOR(j,1,m){
      set<int> pars;
      if(mat[i][j] == '*') {
         FOR(k,0,3) {
            int x = i + dx[k], y = j + dy[k];
            int u = (x - 1) * m + y;
            if(!inside(x,y) || mat[x][y] == '*') continue;
            pars.insert(dsu.getPar(u));
         }
         int ans = 1;
         for(int p : pars)
            ans = (ans + dsu.getSize(p)) % 10;
         cout << ans;
      }
      else
         cout << '.';
      if(j == m) cout << '\n';
   }
}
