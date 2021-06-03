/*
Author: Nachiket Kanore
Created: Tuesday 05 January 2021 12:52:49 PM IST
(ツ) You can tell whether a man is clever by his answers. You can tell whether a man is wise by his questions.
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
	string a, b;
	int brute_ans;
	string ans;

public:
	Solution() {
		input();
		solve();
		output();
	}
	void input() {
		cin >> a >> b;
		reverse(ALL(a));
		while (sz(a) && a.back() == '0') a.pop_back();
		reverse(ALL(a));
		reverse(ALL(b));
		while (sz(b) && b.back() == '0') b.pop_back();
		reverse(ALL(b));
	}
	void solve() {
		if (sz(a) < sz(b))
			ans = "<";
		else if (sz(a) > sz(b))
			ans = ">";
		else {
			if (a == b)
				ans = "=";
			else if (a < b)
				ans = "<";
			else
				ans = ">";
		}
	}
	void output() {
		cout << ans << '\n';
	}
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	Solution S;
}
