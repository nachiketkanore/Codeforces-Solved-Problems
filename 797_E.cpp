/*
Author: Nachiket Kanore
Created: Monday 08 March 2021 08:50:42 PM IST
(ツ) Notice that the stiffest tree is most easily cracked, while the bamboo or willow survives by bending with the wind.
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

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 1e5 + 5, MAGIC = 369;
int n, q, a[N], dp[N][MAGIC];

int go1(int id, int k) {
	if (id > n) return 0;
	int &ans = dp[id][k];
	if (~ans) return ans;
	return ans = 1 + go1(id + a[id] + k, k);
}

int go2(int id, int k) {
	if (id > n) return 0;
	return 1 + go2(id + a[id] + k, k);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	FOR (i,1,n) cin >> a[i];
	memset(dp, -1, sizeof(dp));
	cin >> q;
	while (q--) {
		int id, k;
		cin >> id >> k;
		if (k < MAGIC) 
			cout << go1(id, k) << '\n';
		else 
			cout << go2(id, k) << '\n';
	}
}
