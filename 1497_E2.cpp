/**
 *	Author: Nachiket Kanore
 *	Created: Monday 05 April 2021 03:37:00 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <functional>
#include <cstring>

#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)
using namespace std;

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

const int N = 1e7;
int spf[N+1], mask[N+1];

std::vector<int> compress(std::vector<int> a, int n) {
	vector<int> new_a(n+1), vals = a, un_vals;
	sort(ALL(vals));
	FOR (i,1,n) if (!sz(un_vals) || un_vals.back() != vals[i]) un_vals.push_back(vals[i]);
	vals = un_vals;
	FOR (i,1,n)	new_a[i] = lower_bound(ALL(vals), a[i]) - vals.begin();
	return new_a;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n+1);
	vector<vector<int>> jump_to(k+1, vector<int>(n+1, -1));
	vector<int> freq(n);

	FOR (i,1,n) {
		cin >> a[i];
		a[i] = mask[a[i]];
	}
	see(a);
	a = compress(a, n);
	// a[i] => [0, n)
	see(a);

	FOR (changes,0,k) {
		int to = 1;
		int unique_vals = 0;

		auto add = [&](int val) {
			if (freq[val] == 0) unique_vals++;
			freq[val]++;
		};
		auto remove = [&](int val) {
			assert(freq[val] > 0);
			if (freq[val] == 1) unique_vals--;
			freq[val]--;
		};
		
		add(a[1]);

		FOR (i,1,n) {
			// required changes = len - unique_vals
			while (1) {
				if (to == n) break;
				to++;
				add(a[to]);
				if ((to - i + 1) - unique_vals <= changes) {
					continue;
				} else {
					remove(a[to]);
					to--;
					break;
				}
			}
			see(changes, i, to);
			assert(i <= to);
			jump_to[changes][i] = to;
			remove(a[i]);
		}
	}

	const int inf = 1e9;
	vector<vector<int>> dp(k+1, vector<int>(n+1, -1));

	function<int(int,int)> go = [&](int id, int changes_rem) {
		if (changes_rem < 0) return inf;
		if (id > n) return 0;
		int &ans = dp[changes_rem][id];
		if (~ans) return ans;
		ans = inf;

		FOR (changes,0,changes_rem) {
			int to = jump_to[changes][id];
			cmin(ans, 1 + go(to + 1, changes_rem - changes));
		}
		return ans;
	};	

	int ans = go(1, k);
	assert(ans < inf);
	cout << ans << '\n';
}

void pre() {
	FOR (i,2,N) if (!spf[i]) for (int j = i; j <= N; j += i) if (!spf[j]) spf[j] = i;
	FOR (i,1,N) {
		int val = i;
		int keep = 1;
		while (val > 1) {
			int p = spf[val], cnt = 0;
			while (val % p == 0) val /= p, cnt ^= 1;
			if (cnt) keep *= p;
		}
		mask[i] = keep;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	pre();
	int T;
	cin >> T;
	while (T--) solve();
}