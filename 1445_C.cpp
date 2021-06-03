/*
Author: Nachiket Kanore
Created: Tuesday 10 November 2020 12:24:16 PM IST
(ツ) The truth is always exciting. Speak it, then. Life is dull without it.
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
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

const int N = 2e5 + 5, inf = 1e18;

int getPowerIn(int x, int p) {
	int cnt = 0;
	while (x % p == 0) x /= p, ++cnt;
	assert(cnt > 0);
	return cnt;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;

		if (a < b) cout << a << "\n";
		else {
			if (a % b) {
				cout << a << "\n";
				continue;
			}
			// Now a % b == 0
			// a = k.b
			int bb = b;
			vector<int> B;
			for (int d = 2; d * d <= b; d++) if (b % d == 0) {
				B.push_back(d);
				while (b % d == 0) b /= d;
			}
			if (b > 1) B.push_back(b);

			see(bb, B);

			int ans = 0;

			for (int p : B) {
				int powInA = getPowerIn(a, p);
				__int128 rem = 1;
				FOR (i,1,powInA+1) {
					int getAns = a / rem;
					if (getAns % bb) 
						ans = max(ans, getAns);
					rem *= p;
				}
			}
			cout << ans << "\n";
		}
	}
}
