/*
Author: Nachiket Kanore
Created: Wednesday 17 February 2021 10:14:21 PM IST
(ツ) Listen to your intuition. It will tell you everything you need to know.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <queue>
#include <cstring>
#include <array>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n;	cin >> n;
	std::vector<int> a(n), answer(n);	for (auto &it : a) cin >> it;
	using X = array<int,3>;
	queue<X> Q;
	Q.push({0,n-1,0});

	while (!Q.empty()) {
		X now = Q.front();	Q.pop();
		int L = now[0], R = now[1], dep = now[2];
		if (L > R) continue; 
		int id = -1, mx = -1;
		FOR (i,L,R)
			if (cmax(mx, a[i]))
				id = i;
		assert(~id && ~mx);
		answer[id] = dep;
		Q.push({L,id-1,dep+1});
		Q.push({id+1,R,dep+1});
	}
	for (int i = 0; i < n; i++) 
		cout << answer[i] << " \n"[i==n-1];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T = 1;
	cin >> T;
	while (T--)
		solve();
}
