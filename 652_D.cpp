/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 11 May 2021 02:29:39 PM IST
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

int n, l[N], r[N];
array<int,3> ranges[N];
vector<int> coords;
int tree[N], ans[N];

int32_t main() {
	cin >> n;
	FOR (i,1,n) {
		cin >> l[i] >> r[i];
		ranges[i][0] = l[i];
		ranges[i][1] = r[i];
		ranges[i][2] = i;
		coords.push_back(l[i]);
		coords.push_back(r[i]);
	}

	sort(ALL(coords));

	FOR (i,1,n) {
		ranges[i][0] = int(lower_bound(ALL(coords), ranges[i][0]) - coords.begin()) + 1;
		ranges[i][1] = int(lower_bound(ALL(coords), ranges[i][1]) - coords.begin()) + 1;
	}

	sort(ranges + 1, ranges + n + 1);

	auto get = [&](int R) {
		int ret = 0;
		while (R) {
			ret += tree[R];
			R -= R & -R;
		}
		return ret;
	};

	auto upd = [&](int id, int val) {
		while (id < N) {
			tree[id] += val;
			id += id & -id;
		}
	};

	for (int i = n; i; --i) {
		auto [L, R, id] = ranges[i];
		ans[id] = get(R);
		upd(R, 1);
	}

	FOR (i,1,n) cout << ans[i] << "\n";
}
