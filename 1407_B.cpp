#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

vector<int> remove_id(vector<int> a, int id) {
	assert(id >= 0 && id < sz(a));
	vector<int> ret;
	for (int i = 0; i < sz(a); i++) if (i != id) ret.push_back(a[i]);
	return ret;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	sort(a.begin(), a.end());
	
	vector<int> ans;
	ans.push_back(a.back());
	a.pop_back();
	int curr_gcd = ans.back();

	for (int i = 1; i < n; i++) {
		int which = -1;
		int val = -1;
		for (int j = 0; j < sz(a); j++) {
			int get_gcd = __gcd(curr_gcd, a[j]);
			if (get_gcd > val) {
				val = get_gcd;
				which = j;
			}
		}
		assert(~which);
		assert(val > 0);
		curr_gcd = val;
		ans.push_back(a[which]);
		a = remove_id(a, which);
	}

	for (int x : ans) {
		cout << x << ' ';
	}	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T = 1;	cin >> T;
	while (T--) solve();	
}