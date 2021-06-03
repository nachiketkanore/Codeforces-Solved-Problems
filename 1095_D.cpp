/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 12 May 2021 11:17:32 AM IST
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

int n, nxt[3][N];

int32_t main() {
	cin >> n;
	FOR (i,1,n) cin >> nxt[1][i] >> nxt[2][i];

	auto check = [&](int curr, int next) {
		vector<int> ans;

		FOR (i,1,n) {
			int next_next = -1;
			if (nxt[1][curr] == next) 
				next_next = nxt[2][curr];
			else if (nxt[2][curr] == next)
				next_next = nxt[1][curr];
			else return false;
			ans.push_back(curr);
			curr = next;
			next = next_next;
		}

		for (int p : ans) {
			cout << p;
			cout << ' ';
		}
		cout << '\n';
		return true;
	};

	if (check(1, nxt[1][1])) return 0;
	if (check(1, nxt[2][1])) return 0;
	assert(0);
}
