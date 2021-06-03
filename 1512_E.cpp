/**
 *	Author: Nachiket Kanore
 *	Created: Friday 16 April 2021 06:50:02 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <set>
#include <cstring>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

void solve() {
	int n, l, r, s;
	cin >> n >> l >> r >> s;
	int mn = 0, mx = 0;
	int len = r - l + 1;
	FOR (i,1,len) mn += i;
	for (int i = n, cnt = len; i > 0 && cnt > 0; --i, --cnt) mx += i;
	if (s < mn || s > mx) {
		cout << "-1\n";
		return;
	}
	vector<int> my_subarray;
	FOR (i,1,len) {
		my_subarray.push_back(i);
		s -= i;
	}
	assert(s >= 0);
	// now we want to make s = 0
	// and it's always possible to do so
	reverse(ALL(my_subarray));
	int can_go_upto = n;
	F0R (i,len) {
		while (s > 0 && my_subarray[i] + 1 <= can_go_upto) {
			s--;
			my_subarray[i]++;
		}
		can_go_upto--;
	}

	assert(s == 0);
	set<int> take;
	for (int x : my_subarray) take.insert(x);
	vector<int> other;
	FOR (i,1,n) if (!take.count(i)) other.push_back(i);
	
	FOR (i,1,n) {
		if (l <= i && i <= r) {
			cout << *take.begin() << ' ';
			take.erase(take.begin());
		} else {
			cout << other.back() << ' ';
			other.pop_back();
		}
	}
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
