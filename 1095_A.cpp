/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 12 May 2021 11:02:09 AM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

int32_t main() {
	int n;	string s;
	cin >> n >> s;
	int i = 0, cnt = 1;
	while (i < n) {
		int todo = cnt++;
		string get;
		while (todo--) {
			get += s[i++];
		}
		sort(ALL(get));
		assert(get.back() == get.front());
		cout << get.back();
	}
}
