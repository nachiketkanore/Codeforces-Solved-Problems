/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 11 May 2021 04:18:38 PM IST
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
	int n, m;
	cin >> n >> m;
	const int half = n / 2;
	vector<int> one, two;
	vector<int> one_sums, two_sums;
	F0R (i,n) {
		int u;
		cin >> u;
		if (i <= half) one.push_back(u);
		else two.push_back(u);
	}
	F0R (mask,1<<sz(one)) {
		int sum = 0;
		F0R (i,sz(one)) {
			if (mask >> i & 1) sum += one[i];
		}
		sum %= m;
		one_sums.push_back(sum);
	}
	F0R (mask,1<<sz(two)) {
		int sum = 0;
		F0R (i,sz(two)) {
			if (mask >> i & 1) sum += two[i];
		}
		sum %= m;
		two_sums.push_back(sum);
	}
	auto clean = [&](vector<int> &a) {
		vector<int> ret;
		sort(ALL(a));
		for (int x : a) {
			if (ret.empty() || ret.back() ^ x) {
				ret.push_back(x);
			}
		}
		ret = a;
	};
	clean(one_sums);
	clean(two_sums);
	sort(ALL(two_sums));
	int ans = 0;
	F0R (i,sz(one_sums)) cmax(ans, one_sums[i]);
	F0R (i,sz(two_sums)) cmax(ans, two_sums[i]);
	for (int x : one_sums) {
		int upto = m - x;
		int id = lower_bound(ALL(two_sums), upto) - two_sums.begin();
		FOR (i,id - 5, id + 5) {
			if (i >= 0 && i < sz(two_sums)) {
				cmax(ans, (x + two_sums[i]) % m);
			}
		}
	}
	cout << ans << '\n';
}
