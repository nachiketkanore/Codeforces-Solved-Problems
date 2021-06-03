//It's time to be who I am, rather than who I am supposed to be.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+1;
int n, a[N], ans[N], occ[N];
vector<int> g[N];

void dfs(int node, int par, int cnt, int currGCD){
	int val = a[node];	
	int curr = 1;

	for(int i = 1; i * i <= val; i++){
		if(val % i == 0){
			int fi = i, se = val/i;
			occ[fi]++;

			if(occ[fi] >= cnt - 1)
				curr = max(curr, fi);

			if(fi != se)
				occ[se]++;

			if(occ[se] >= cnt - 1)
				curr = max(curr, se);
		}
	}

	ans[node] = max(curr, currGCD);

	for(int next : g[node]){
		if(next != par)
			dfs(next, node, cnt+1, __gcd(currGCD,a[node]));
	}

	for(int i = 1; i * i <= val; i++){
		if(val % i == 0){
			int fi = i, se = val / i;
			occ[fi]--;
			if(fi != se)
				occ[se]--;
		}
	}
}


int32_t main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

  	cin >> n;
  	for(int i = 1; i <= n; i++)
  		cin >> a[i];
  	for(int i = 1,u,v; i < n; i++){
  		cin >> u >> v;
  		g[u].push_back(v);
  		g[v].push_back(u);
  	}

  	dfs(1, 0, 1, 0);

  	for(int i = 1; i <= n; i++)
  		cout << ans[i] << ' ';
  		cout << '\n';
	
}