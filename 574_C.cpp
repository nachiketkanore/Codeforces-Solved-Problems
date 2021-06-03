/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 16 March 2021 10:57:41 PM IST
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

void solve() {
	int n;	cin >> n;
	std::vector<int> a(n);
	for (int &x : a) {
		cin >> x;
		while (x % 2 == 0) x >>= 1;
		while (x % 3 == 0) x /= 3;
	}	
	sort (ALL(a));
	cout << (a.front() == a.back() ? "Yes" : "No");
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	solve();
}
