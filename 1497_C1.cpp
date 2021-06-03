/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 17 March 2021 09:34:41 PM IST
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

int lcm(int a, int b){
	return (a*b)/__gcd(a,b);
}

void solve() {
	int n, k;	cin >> n >> k;
	assert(k == 3);
	int a = -1, b = -1, c = -1;
	if (n & 1) a = n / 2, b = n / 2, c = 1;
	else {
		for (int p2 = 1; p2 <= n; p2 <<= 1) {
			int rem = n - p2;
			if (rem > 0 && rem % 2 == 0) {
				int x = p2, y = rem / 2, z = rem / 2;
				assert(x + y + z == n);
				if (2 * lcm(x, lcm(y, z)) <= n) a = x, b = y, c = z;
			}
		}
	}
	assert(~a && ~b && ~c);
	assert(a + b + c == n);
	assert(2 * lcm(a, lcm(b, c)) <= n);
	cout << a << ' ' << b << ' ' << c << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
