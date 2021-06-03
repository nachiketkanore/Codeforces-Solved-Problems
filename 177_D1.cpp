/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 17 March 2021 06:32:00 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
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
const int N = 1e5 + 5;
int add[N+1], n, m, a[N], b[N], mod;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> mod;
	FOR (i,1,n) cin >> a[i];
	FOR (i,1,m) cin >> b[i];
	auto add_in_range = [&](int L, int R, int val) {
		add[L] += val;
		add[R+1] -= val;
	};
	int L = 1, R = n - m + 1, id = 1;
	while (R <= n) {
		assert(id <= m);
		add_in_range(L, R, b[id]);
		++L, ++R, ++id;
	}
	FOR (i,1,n) add[i] += add[i-1];
	FOR (i,1,n)	cout << (a[i] + add[i]) % mod << " \n"[i==n];
}
