/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 11 May 2021 05:12:40 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <string>
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

struct ${
	$() {
		ios::sync_with_stdio(0); 
		cin.tie(0);
	}
} $;

const int inf = 1e18;
const int N = 5e5 + 5;

int32_t main() {
	string s;
	cin >> s;
	int n = sz(s);
	vector<int> freq(10);
	F0R (i,n) freq[s[i]-'0']++;

	set<string> done;
	int ans = 0;

	vector<int> fact(20);
	fact[0] = 1;
	FOR (i,1,20) fact[i] = i * fact[i - 1];

	auto get_contrib = [&](vector<int> cnt) {
		int len = 0;
		F0R (i,sz(cnt)) len += cnt[i];
		int ret = fact[len];
		F0R (i,sz(cnt)) ret /= fact[cnt[i]];
		return ret;
	};

	auto compute = [&](string t) {
		string chk = t;
		sort(ALL(chk));
		if (done.count(chk)) return int(0);
		done.insert(chk);
		
		vector<int> cnt(10);
		F0R (i,sz(t)) cnt[t[i]-'0']++;
		
		// should be subset
		F0R (i,10) if (freq[i] > 0 && cnt[i] == 0) return int(0);

		int contrib = 0;
		contrib += get_contrib(cnt);

		if (cnt[0] > 0) {
			cnt[0]--;
			contrib -= get_contrib(cnt);
		}
		return contrib;
	};

	F0R (mask,1<<n) {
		string chk;
		F0R (i,n) if (mask >> i & 1) chk += s[i];
		if (sz(chk)) {
			ans += compute(chk);
		}
	}
	cout << ans << '\n';
}
