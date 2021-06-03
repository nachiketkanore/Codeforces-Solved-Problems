/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 26 May 2021 01:08:16 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <functional>
#include <cstring>
#include <set>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n, S;
		cin >> n >> S;
		vector<vector<int>> g(n);
		vector<int> leaves(n), sub_size(n);
		vector<int> edge_count(n-1);
		vector<array<int,3>> edges(n-1);
		F0R (i,n-1) {
			auto &[u, v, w] = edges[i];
			cin >> u >> v >> w;
			--u, --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		function<void(int,int)> dfs1 = [&](int u, int par) {
			if (sz(g[u]) == 1) leaves[u] = 1;
			sub_size[u] = 1;
			for (int v : g[u]) {
				if (v == par) continue;
				dfs1(v, u);
				leaves[u] += leaves[v];
				sub_size[u] += sub_size[v];
			}
		};	dfs1(0, -1);
		set<pair<int,int>> diffs;
		int tot = 0, ans = 0;
		auto get_diff = [&](int id) {
			return edge_count[id] * (edges[id][2] - edges[id][2] / 2);
		};
		F0R (i,n-1) {
			auto &[u, v, w] = edges[i];
			if (sub_size[u] < sub_size[v])
				swap(u, v);
			edge_count[i] = leaves[v];
			tot += w * edge_count[i];
			diffs.insert(make_pair(get_diff(i), i));
		}
		while (tot > S) {
			auto [best_diff, id] = *diffs.rbegin();
			diffs.erase(prev(diffs.end()));
			tot -= best_diff;
			edges[id][2] >>= 1;
			diffs.insert(make_pair(get_diff(id), id));
			++ans;
		}
		cout << ans << '\n';
	}
}
