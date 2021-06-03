/*
Author: Nachiket Kanore
Created: Thursday 18 February 2021 07:02:12 PM IST
(ツ) Do not be too timid and squeamish about your reactions. All life is an experiment. The more experiments you make the better.
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
	int n;	cin >> n;
	vector<int> a(n);
	for (auto &it : a) 
		cin >> it;
	
	auto get_operations = [&](int x, int y) {
		if (x > y) swap(x, y);
		for (int j = 0; ; j++)
			if (2 * (x * (1LL << j)) >= y) 
				return j;
		assert(false);
		return -1LL;
	};
	
	int answer = 0;
	for (int i = 1; i < n; i++) {
		int req = get_operations(a[i-1], a[i]);
		cerr << a[i-1] << ' ' << a[i] << " , required = " << req << '\n';
		answer += req;
	}
	cout << answer << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T = 1;
	cin >> T;
	while (T--)
		solve();
}
