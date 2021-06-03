/*
Author: Nachiket Kanore
Created: Monday 04 January 2021 07:48:22 PM IST
(ツ) Learning without reflection is a waste, reflection without learning is dangerous.
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
 
const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int a, b, k;
	cin >> a >> b >> k;
	int get = 1;
	while (a % 2 == 0) {
		get *= 2;
		a >>= 1;
	}
	while (b % 2 == 0) {
		get *= 2;
		b >>= 1;
	}
	cout << (get >= k ? "YES" : "NO") << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;	cin >> T;
	while (T--) solve();
}
