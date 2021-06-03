/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 06 April 2021 03:20:55 PM IST
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
const int N = 405;
int n, m, each, a[N], L[N], R[N], want[N];
vector<pair<int,int>> friends_req[N];
int dp[N][N << 3];

int go(int id, int from_yesterday) {
	if (id > n) return 0;
	int &ans = dp[id][from_yesterday];
	if (~ans) return ans;
	ans = -inf;

	int have_for_today = a[id] + from_yesterday;
	if (have_for_today < each) return -inf;

	int now = a[id], prev = from_yesterday;
	if (prev >= each) {
		prev -= each;
	} else {
		int extra = each - prev;
		prev = 0;
		assert(now >= extra);
		now -= extra;
	}

	// now my quota is finished..
	// I now have "prev" from yesterday and "now" from today
	
	int left_over_for_today = prev + now;
	cmax(ans, 0 + go(id+1, now));

	for (int i = 0, given_to_friends = 0; i < sz(friends_req[id]); i++) {
		given_to_friends += friends_req[id][i].first;
		if (given_to_friends <= left_over_for_today) {
			int give_for_tomorrow = 0;	// only from "now"
			if (given_to_friends <= prev) {
				give_for_tomorrow = now;
			} else {
				int extra = given_to_friends - prev;
				assert(now >= extra);
				give_for_tomorrow = now - extra;
			}
			cmax(ans, i+1 + go(id+1, give_for_tomorrow));
		} else break;
	}
	return ans;
}

void trace(int id, int from_yesterday) {
	if (id > n) return ;
	int ans = go(id, from_yesterday);

	int have_for_today = a[id] + from_yesterday;
	if (have_for_today < each) assert(false);

	int now = a[id], prev = from_yesterday;
	if (prev >= each) {
		prev -= each;
	} else {
		int extra = each - prev;
		prev = 0;
		assert(now >= extra);
		now -= extra;
	}

	// now my quota is finished..
	// I now have "prev" from yesterday and "now" from today
	
	int left_over_for_today = prev + now;

	if (ans == 0 + go(id+1, now)) {
		cout << "0\n";
		return trace(id+1, now);
	}

	for (int i = 0, given_to_friends = 0; i < sz(friends_req[id]); i++) {
		given_to_friends += friends_req[id][i].first;
		if (given_to_friends <= left_over_for_today) {
			int give_for_tomorrow = 0;	// only from "now"
			if (given_to_friends <= prev) {
				give_for_tomorrow = now;
			} else {
				int extra = given_to_friends - prev;
				assert(now >= extra);
				give_for_tomorrow = now - extra;
			}
			if (ans == i+1 + go(id+1, give_for_tomorrow)) {
				cout << i+1 << ' ';
				for (int j = 0; j <= i; j++) cout << friends_req[id][j].second << " \n"[j==i];
				return trace(id+1, give_for_tomorrow);
			}
		} else break;
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	memset(dp, -1, sizeof(dp));
	cin >> n >> each;
	FOR (i,1,n) {
		cin >> a[i];
		assert(a[i] >= each);
	}
	cin >> m;
	FOR (i,1,m) {
		cin >> L[i] >> R[i] >> want[i];
		FOR (j,L[i],R[i]) {
			friends_req[j].push_back({want[i], i});
		}
	}
	FOR (i,1,n) sort(ALL(friends_req[i]));
	int ans = go(1, 0);
	assert(ans >= 0);
	cout << ans << '\n';
	trace(1, 0);
}
