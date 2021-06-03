/*
Author: Nachiket Kanore
Created: Monday 08 March 2021 06:33:13 PM IST
(ツ) Science is organized knowledge. Wisdom is organized life.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 3e5 + 5;
int n, m, tin[N], anc[N], timer, a[N], b[N];
std::vector<int> g[N];
std::vector<pair<int,int>> ans;

void dfs(int node , int parent){
    tin[node] = anc[node] = ++timer;
    for(int edge : g[node]){
        int next = a[edge] ^ b[edge] ^ node;
        if(next != parent){
            if(!tin[next]){
                dfs(next , node);
                anc[node] = min(anc[node] , anc[next]);
                ans.push_back({node , next});
            }
            else{
                anc[node] = min(anc[node] , tin[next]);
                if(tin[next] < tin[node]){
                    ans.push_back({node , next});
                }
            }
            if(anc[next] > tin[node]){
                cout << "0\n";
                exit(0);
            }
        }
    }
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR (i,1,m) {
		cin >> a[i] >> b[i];
		g[a[i]].push_back(i);
		g[b[i]].push_back(i);
	}
	dfs(1,0);
	assert(sz(ans) == m);
	for (auto [u, v] : ans) 
		cout << u << ' ' << v << '\n';
}
