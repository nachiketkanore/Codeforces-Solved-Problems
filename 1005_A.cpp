/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 11 May 2021 03:18:29 PM IST
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
	int n;
	cin >> n;
	vector<int> a(n);
	F0R (i,n) cin >> a[i];
	vector<int> ans;
	for (int i = 0; i < n; ) {
		int val = a[i];
		assert(val == 1);
		int j = i + 1;
		while (j < n && a[j] == a[j - 1] + 1) {
			val++;
			j++;			
		}
		ans.push_back(val);
		i = j;
	}
	cout << sz(ans) << '\n';
	F0R (i,sz(ans)) cout << ans[i] << " \n"[i == sz(ans) - 1];
}
