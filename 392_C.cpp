/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 11 May 2021 01:54:58 PM IST
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

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

struct __init__{
	high_resolution_clock::time_point t1, t2;
	__init__() {
		ios::sync_with_stdio(0); cin.tie(0);
		t1 = high_resolution_clock::now();
	}
	~__init__() {
		t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		cerr << "It took " << time_span.count() << " seconds.";
	}
} __init__;

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

int32_t main() {
	int n, k;
	cin >> n >> k;

	const int SZ = ((k + 1) << 1) + 1;
	const int N = 69;
	vector<vector<mi>> mat(SZ, vector<mi> (SZ));
	vector<vector<mi>> choose(N, vector<mi> (N, 0));
	vector<mi> p2(N, 1);
	vector<vector<mi>> init(SZ, vector<mi> (1, 0));

	F0R (i,k+1) {
		init[i][0] = 1;
		init[k + 1 + i][0] = 0;
		init[SZ - 1][0] = 0;
	}
	init[k + 1][0] = 1;

	choose[0][0] = 1;
	F0R (i,N) F0R (j,i+1) choose[i][j] += (i ? choose[i - 1][j] : 0) + (i && j ? choose[i - 1][j - 1] : 0);

	F0R (i,N) if (i) p2[i]  = p2[i - 1] * 2;

	F0R (i,k+1) mat[k + 1 + i][i] = 1;
	mat[SZ - 1][SZ - 1] = 1;
	mat[SZ - 1][k] = 1;

	F0R (i,k+1) {
		FOR (j,0,i) {
			mat[i][j] += choose[i][j];
			mat[i][k + 1 + j] += choose[i][j] * p2[i - j];
		}
	}

	see(mat);
	see(init);

	auto multiply = [](vector<vector<mi>> A, vector<vector<mi>> B) {
		const int n = sz(A);
		const int m = sz(B[0]);
		const int K = sz(A[0]);
		vector<vector<mi>> ret(n, vector<mi> (m, 0));

		F0R (i,n) F0R (j,m) F0R (k,K) ret[i][j] += A[i][k] * B[k][j];

		return ret;
	};

	auto power = [&](vector<vector<mi>> mat, int k) {

		const int n = mat.size();
		const int m = mat[0].size();
		assert(n == m);
		vector<vector<mi>> ret(n, vector<mi> (m, 0));
		F0R (i,n) ret[i][i] = 1;
		while (k) {
			if (k & 1) ret = multiply(ret, mat);
			mat = multiply(mat, mat);
			k >>= 1;
		}
		return ret;
	};

	auto ans = power(mat, n);

	ans = multiply(ans, init);


	cout << ans[SZ - 1][0] << '\n';
}
