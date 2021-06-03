/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 11 May 2021 02:58:07 PM IST
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

#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;
using namespace std::chrono;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

//Use pair<int,int> to support multiset like features
typedef tree<pair<long long,int>, null_type, less<pair<long long,int>>, rb_tree_tag, tree_order_statistics_node_update> oset;

oset curr;

/*
1. Number of elements strictly greater than a[i]
int cnt = sz(curr) - (int)curr.order_of_key({a[i]+1,0});

2. Number of elements strictly less than a[i]
int cnt = (int)curr.order_of_key({a[i],i});

3. Use insert like this : curr.insert({a[id], id});

4. Finding the k -th smallest element in the set using * because 
    find_by_order returns an iterator 
    auto k-th_smallest_value =  *(o_set.find_by_order(k - 1))  
    It is (k - 1) since it uses zero indexes

5. Erasing : curr.erase({a[i], i});
*/

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

const int N = 5e5 + 5;

int32_t main() {
	using ll = long long;
	int n;	ll T;
	cin >> n >> T;
	ll pref = 0, ans = 0;
	// curr.insert(make_pair(0ll, 1e9));
	F0R (i,n) {
		ll u;
		cin >> u;
		pref += u;
		if (pref < T) ++ans;
		int cnt = sz(curr) - (int)curr.order_of_key({pref - T + 1,0});
		ans += cnt;
		curr.insert({pref, i});
	}
	cout << ans << '\n';
}
