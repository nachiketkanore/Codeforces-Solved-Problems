/*
Author: Nachiket Kanore
Created: Wednesday 06 January 2021 03:54:48 PM IST
(ツ) To understand the heart and mind of a person, look not at what he has already achieved, but at what he aspires to do.
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
	int n;
	vector<int> ans;
public:
	Solution() {
		input();
		solve();
	}
	void input() {
		cin >> n;
	}
	void solve() {
		ans.resize(n);
		for (int i = 0; i < n; i++)
			ans[i] = i+1;
	}
	~Solution() {
		cout << sz(ans) << '\n';
		for (int x : ans) cout << x << ' ';
		cout << '\n';
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
