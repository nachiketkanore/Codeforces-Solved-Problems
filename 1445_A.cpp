/*
Author: Nachiket Kanore
Created: Wednesday 06 January 2021 04:01:52 PM IST
(ツ) Better than a thousand hollow words, is one word that brings peace.
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

class Solution {
private:
	int n, x;
	vector<int> a, b;
	bool ans = true;
public:
	Solution() {
		input();
		solve();
	}
	void input() {
		cin >> n >> x;
		a.resize(n);
		b.resize(n);
		for (int &it : a) cin >> it;
		for (int &it : b) cin >> it;
	}
	void solve() {
		sort(ALL(a));
		sort(ALL(b));
		reverse(ALL(b));
		for (int i = 0; i < n; i++) {
			ans &= a[i] + b[i] <= x;
		}
	}
	~Solution() {
		cout << (ans ? "Yes\n" : "No\n");
	}
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		Solution S;
	}
}
