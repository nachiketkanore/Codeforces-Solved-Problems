/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 17 March 2021 09:41:48 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <map>
#include <cstring>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 1e7 + 5;
int spf[N+1];	//Can go upto N = 1e7
 
void SPF(){
	spf[1] = 1;
	FOR (i,2,N) if (!spf[i]) for (int j = i; j <= N; j += i) if (!spf[j]) spf[j] = i; 
}


void solve() {
	int n, k;
	cin >> n >> k;	assert(k == 0);
	std::vector<vector<int>> a;
	F0R(i,n) {
		int val;	cin >> val;
		vector<int> pfs;
		while (val > 1) {
			int p = spf[val];
			int c = 0;
			while (val % p == 0) val /= p, ++c;
			c &= 1;
			if (c) pfs.push_back(p);
		}
		if (pfs.empty()) pfs = {1};
		sort(ALL(pfs));
		a.push_back(pfs);
	}
	map<vector<int>, int> curr;
	int ans = 0;
	for (std::vector<int> pf : a) {
		if (curr.count(pf)) {
			++ans;
			curr.clear();
			curr[pf] = 1;
		} else {
			curr[pf] = 1;
		}
	}
	ans += sz(curr) > 0;
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	SPF();
	int T; cin >> T; while (T--) solve();
}
