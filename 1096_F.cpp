/**
 *	Author: Nachiket Kanore
 *	Created: Friday 30 April 2021 08:56:52 PM IST
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
#include <chrono>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;
using namespace std::chrono;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

struct starter{
	high_resolution_clock::time_point t1, t2;
	starter() {
		ios::sync_with_stdio(0); cin.tie(0);
		t1 = high_resolution_clock::now();
	}
	~starter() {
		t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		cerr << "It took " << time_span.count() << " seconds.";
	}
} starter_;

const int MOD = 998244353;
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

struct BIT
{
    int N;
    vector<int> bit;

    void init(int n)
    {
        N = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val)
    {
        while(idx <= N)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    void updateMax(int idx, int val)
    {
        while(idx <= N)
        {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }

    int pref(int idx)
    {
        int ans = 0;
        while(idx > 0)
        {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    int rsum(int l, int r)
    {
        return pref(r) - pref(l - 1);
    }

    int prefMax(int idx)
    {
        int ans = -2e9;
        while(idx > 0)
        {
            ans = max(ans, bit[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
} T;

const int inf = 1e18;
const int N = 2e5 + 5;

int n, p[N], have[N];
int unknown, cnt_unknown[N];

int32_t main() {
	cin >> n;
	FOR (i,1,n) {
		cin >> p[i];
		if (~p[i]) {
			have[p[i]] = 1;
		} else {
			unknown++;
			cnt_unknown[i] = 1;
		}
	}
	FOR (i,1,n) {
		cnt_unknown[i] += cnt_unknown[i-1];
		have[i] += have[i-1];
	}

	// U U
	mi ans = mi(unknown) * (unknown - 1) / 2;
	ans /= 2;

	auto get_poss = [&](int L, int R) {
		if (L > R) return int(0);
		return (R - L + 1) - (have[R] - have[L-1]);
	};

	// U K
	if (unknown)
	FOR (i,1,n) {
		if (p[i] == -1) continue;
		int tot = cnt_unknown[i-1];
		int poss = get_poss(p[i] + 1, n);
		ans += mi(tot) * poss / unknown;
	}
	// K U
	if (unknown)
	for (int i = n; i; --i) {
		if (p[i] == -1) continue;
		int tot = cnt_unknown[n] - cnt_unknown[i-1];
		int poss = unknown - get_poss(p[i] + 1, n);
		ans += mi(tot) * poss / unknown;
	}

	// K K
	T.init(n);
	FOR (i,1,n) {
		if (~p[i]) {
			ans += T.rsum(p[i] + 1, n);
			T.update(p[i], 1);
		}
	}

	cout << ans;
}
