/*
Author: Nachiket Kanore
Created: Saturday 20 February 2021 12:56:17 AM IST
(ツ) What you fear is that which requires action to overcome.
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

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, answer = 0;	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		for (int j = i; j < n; j++) {
			if (s[j] == 'U') y++; else if (s[j] == 'D') y--;
			if (s[j] == 'R') x++; else if (s[j] == 'L') x--;
			answer += !x && !y;
		}
	}
	cout << answer << '\n';
}
