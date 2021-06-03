//It's time to be who I am, rather than who I am supposed to be.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100+10;
const int mod = 998244353;
int n, m, ans, vis[N], deg[N];
vector<int> g[N], comp;


void dfs(int node){
	vis[node] = 1;
	comp.push_back(node);
	for(int next : g[node]){
		if(!vis[next])
			dfs(next);
	}
}

bool oddCycle(){
	int sz = comp.size();
	int degTwo = 0;
	for(int node : comp)
		degTwo += deg[node] == 2;
	return (degTwo == sz) and (sz % 2 == 1);
}


int32_t main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

   cin >> n >> m;

   for(int i = 1; i <= m; i++){
   		int u, v;
   		cin >> u >> v;
   		deg[u]++, deg[v]++;
   		g[u].push_back(v);
   		g[v].push_back(u);
   }

   for(int i = 1; i <= n; i++){
   	if(!vis[i]){
   		comp.clear();
   		dfs(i);
   		if(oddCycle())
   			ans++;
   	}
   }
   int rem = n - ans;
   if(rem % 2 == 1) ans++;
   cout << ans << '\n';

}