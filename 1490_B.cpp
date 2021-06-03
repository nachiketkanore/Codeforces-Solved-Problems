/*
Author: Nachiket Kanore
Created: Thursday 18 February 2021 07:16:27 PM IST
(ツ) The greatest way to live with honor in this world is to be what we pretend to be.
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
	vector<int> c(3);
	FOR (i,1,n) {
		int u;	cin >> u;
		c[u % 3]++;
	}
	int answer = 0;
	int each = n / 3;
	while (c[0] != each || c[1] != each || c[2] != each) {
		if (c[0] > each) {
			++answer;
			c[0]--;
			c[1]++;
		}
		if (c[1] > each) {
			++answer;
			c[1]--;
			c[2]++;
		}
		if (c[2] > each) {
			++answer;
			c[2]--;
			c[0]++;
		}
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
