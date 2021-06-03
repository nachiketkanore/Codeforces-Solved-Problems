/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 04 May 2021 11:24:41 PM IST
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

const int inf = 1e18;
const int N = 5e5 + 5;

int32_t main() {
	int n, p;
	cin >> n >> p;
	vector<pair<int,int>> a(n);
	F0R (i,n) cin >> a[i].first >> a[i].second;
	double ans = 0;
	const double reward = 2000.;
	F0R (i,n) {
		auto [L1, R1] = a[i];
		auto [L2, R2] = a[(i + 1) % n];
		int cnt = 0;
		int mul_one = R1 / p - (L1 - 1) / p;
		int mul_two = R2 / p - (L2 - 1) / p;

		cnt += mul_one * (R2 - L2 + 1) + (R1 - L1 + 1) * mul_two - mul_one * mul_two;
		int tot = (R1 - L1 + 1) * (R2 - L2 + 1);
		ans += 1. * cnt / tot;
	}
	printf("%0.12f\n", reward * ans);
}
