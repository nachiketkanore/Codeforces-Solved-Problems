/**
 *	Author: Nachiket Kanore
 *	Created: Saturday 29 May 2021 04:29:40 PM IST
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

const int MOD = 1e9 + 7;
struct mi {
	using ll = long long;
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
	mi& operator+=(const mi& m) { if ((v += m.v) >= MOD) v -= MOD; return *this; }
	mi& operator-=(const mi& m) { if ((v -= m.v) < 0) v += MOD;	return *this; }
	mi& operator*=(const mi& m) { v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }

	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
			return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); return pow(a,MOD-2);	}

	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	mi operator++(int32_t) { mi temp; temp.v = v++; return temp; }
	mi operator--(int32_t) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v; return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		ll x; is >> x;
		m.v = x;
		return is;
	}
};

const int inf = 1e18;
const int N = 2e6;

mi fact[N+1];
int spf[N+1];

int32_t main() {
	fact[0] = 1; FOR (i,1,N) fact[i] = i * fact[i-1];
	FOR (i,2,N) if (!spf[i]) for (int j = i; j <= N; j += i) if (!spf[j]) spf[j] = i;
	auto choose = [&](int n, int r) {
		if (r > n) return mi(0);
		return fact[n] / fact[n - r] / fact[r];
	};
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		mi ans = pow(mi(2), y - 1);
		while (x^1) {
			int p = spf[x];
			int c = 0;
			while (x % p == 0) ++c, x /= p;
			ans *= choose(c + y - 1, c);
		}
		cout << ans << '\n';
	}
}
