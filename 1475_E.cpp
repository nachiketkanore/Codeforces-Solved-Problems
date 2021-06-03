/**
 *	Author: Nachiket Kanore
 *	Created: Saturday 29 May 2021 05:44:22 PM IST
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
const int N = 2005;

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

mi fact[N+1];

int32_t main() {
	fact[0] = 1;
	FOR (i,1,N) fact[i] = i * fact[i-1];

	auto choose = [&](int n, int r) {
		if (r > n) return mi(0);
		return fact[n] / fact[r] / fact[n-r];
	};

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n), cnt(n+1);
		for (int &x : a) {
			cin >> x;
			cnt[x]++;
		}
		sort(ALL(a));
		reverse(ALL(a));
		while (sz(a) ^ k) a.pop_back();
		int last = a.back();
		int want = 0;
		while (sz(a) && a.back() == last) {
			++want;
			a.pop_back();
		}
		mi ans = choose(cnt[last], want);
		cout << ans << '\n';
	}
}
