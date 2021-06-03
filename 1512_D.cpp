/**
 *	Author: Nachiket Kanore
 *	Created: Friday 16 April 2021 05:16:37 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <map>
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
	int n;
	cin >> n;
	vector<int> b(n+2);
	int sum = 0;
	map<int,int> freq;
	for (auto &x : b) {
		cin >> x;
		freq[x]++;
		sum += x;
	}

	for (auto &x : b) {
		int other_sum = sum - x;
		freq[x]--;
		if (other_sum % 2 == 0) {
			int want = other_sum >> 1;
			if (freq[want] > 0) {
				freq[want]--;
				int tot = 0;
				for (auto [val, cnt] : freq) {
					while (cnt--) cout << val << ' ', tot++;
				}
				assert(tot == n);
				cout << '\n';
				return;
			}
		}
		freq[x]++;
	}
	cout << "-1\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
