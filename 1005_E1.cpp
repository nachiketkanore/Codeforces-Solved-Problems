/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 11 May 2021 03:37:57 PM IST
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
#include <map>

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
	vector<int> a(n);
	F0R (i,n) cin >> a[i];
	map<int,int> cnt;
	cnt[0] = 1;
	bool present = false;
	int csum = 0;
	int ans = 0;
	F0R (i,n) {
		if (a[i] < m) csum--;
		else if (a[i] > m) csum++;

		if (a[i] == m) present = true;
		if (present) {
			ans += cnt[csum];
			ans += cnt[csum - 1];
		} else {
			cnt[csum]++;
		}
	}
	cout << ans << '\n';
}
