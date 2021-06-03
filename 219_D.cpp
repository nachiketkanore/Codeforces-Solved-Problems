#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, up[N], down[N], allUp, cost[N];
std::vector<int> g[N];
set<int> ug[N];

void dfs(int node, int par, int upCnt, int downCnt){
	up[node] = upCnt;
	down[node] = downCnt;
	for(int child : g[node]){
		if(child != par){
			bool UP = ug[child].count(node);
			bool DOWN = ug[node].count(child);
			allUp += UP;
			dfs(child, node, upCnt + UP, downCnt + DOWN);
		}
	}
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    #ifndef ONLINE_JUDGE
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif	

   	cin >> n;
   	for(int i = 1, u, v; i < n; i++){
   		cin >> u >> v;
   		ug[u].insert(v);
   		g[u].push_back(v);
   		g[v].push_back(u);
   	}
	
	dfs(1,0,0,0);

	int ans = inf;
	for(int i = 1; i <= n; i++){
		cost[i] = allUp + down[i] - up[i];
		ans = min(ans, cost[i]);
	}
	cout << ans << '\n';
	std::vector<int> vert;
	for(int i = 1; i <= n; i++)
		if(cost[i] == ans)
			vert.push_back(i);
	for(int i : vert)
		cout << i << ' ';
	cout << '\n';
}

