#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 1e3 + 5, inf = 1e9;

const int OFF = 1e3 + 5;
int n;
vector<int> a;
int dp[2][N][3 * N];

int go(int id, int sum, bool f) {
	if (id == n) 
		return (sum == 0 ? 0 : -inf);
	int &ans = dp[f][id][sum + OFF];
	if (~ans)
		return ans;
	ans = -inf;
	if (f) {
		ans = max(ans, 1 + go(id + 1, sum + a[id], !f));
		ans = max(ans, go(id + 1, sum, f));
	} else {
		ans = max(ans, 1 + go(id + 1, sum - a[id], !f));
		ans = max(ans, go(id + 1, sum, f));
	}
	return ans;
}


void trace(int id, int sum, bool f) {
	if (id == n) {
		assert(sum == 0);
		return ;
	}
	int ans = go(id, sum, f);
	if (f) {
		int c1 = 1 + go(id + 1, sum + a[id], !f);
		if (c1 == ans) {
			cout << a[id] << ' ';
			return trace(id + 1, sum + a[id], !f);
		}
		return trace(id + 1, sum, f);
	} else {
		int c1 = 1 + go(id + 1, sum - a[id], !f);
		if (c1 == ans) {
			cout << a[id] << ' ';
			return trace(id + 1, sum - a[id], !f);
		}
		return trace(id + 1, sum, f);
	}
}

void solve() {
	cin >> n;
	a.resize(n);
	int sum = 0;
	for (int &x : a) cin >> x, sum += x;

	FOR(i,0,n) {
		FOR(j,sum-OFF,sum+OFF) {
			if (j >= 0 && j < 3 * N) {
				dp[0][i][j] = dp[1][i][j] = -1;
			}
		}
	}

	// memset(dp, -1, sizeof(dp));
	int max_len = go(0, 0, 1);
	int removed = n - max_len;
	assert(removed <= n / 2);
	assert(max_len >= n / 2);
	cout << max_len << '\n';
	trace(0,0,1);
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T = 1;	cin >> T;
	while (T--) solve();	
}