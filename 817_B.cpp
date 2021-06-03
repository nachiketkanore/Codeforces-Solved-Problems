/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 11 May 2021 05:41:03 PM IST
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

struct ${
	$() {
		ios::sync_with_stdio(0); 
		cin.tie(0);
	}
} $;

const int inf = 1e18;
const int N = 5e5 + 5;

int choose1(int n) {
	return n;
}

int choose2(int n) {
	return n * (n - 1) / 2;
}

int choose3(int n) {
	return n * (n - 1) * (n - 2) / 6;
}

int32_t main() {
	int n;
	cin >> n;
	vector<int> a(n);
	F0R (i,n) cin >> a[i];
	sort (ALL(a));
	map<int,int> cnt, tcnt;
	F0R (i,3) cnt[a[i]]++;
	F0R (i,n) tcnt[a[i]]++;

	vector<int> keys;
	for (auto [key, val] : cnt) {
		keys.push_back(key);
	}
	sort(ALL(keys));

	if (sz(cnt) == 1) {
		int val = keys[0];
		see(val);
		cout << choose3(tcnt[val]);
	} else if (sz(cnt) == 2) {
		int val1 = keys[0];
		int val2 = keys[1];
		if (cnt[val1] == 2)
			cout << 1LL * choose2(tcnt[val1]) * choose1(tcnt[val2]);
		else
			cout << 1LL * choose2(tcnt[val2]) * choose1(tcnt[val1]);
	} else if (sz(cnt) == 3) {
		cout << 1LL * choose1(tcnt[keys[0]]) * choose1(tcnt[keys[1]]) * choose1(tcnt[keys[2]]);
	} else assert(0);
}
