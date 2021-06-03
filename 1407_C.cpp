#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int n, ans[N];
vector<int> ids;

int ask(int L, int R) {
	cout << "? " << L << ' ' << R << endl;
	int get;
	cin >> get;
	return get;
}

int32_t main() {

	cin >> n;
	FOR(i,1,n)	
		ids.push_back(i);
	int all = 0;

	while (sz(ids) >= 2) {
		int id1 = ids.back();
		ids.pop_back();
		int id2 = ids.back();
		ids.pop_back();

		int val1 = ask(id1, id2);
		int val2 = ask(id2, id1);

		if (val1 > val2) {
			ans[id1] = val1;
			all += val1;
			ids.push_back(id2);
		} else if (val2 > val1) {
			ans[id2] = val2;
			all += val2;
			ids.push_back(id1);
		} else assert(0);
	}

	int sum = n * (n + 1) / 2;
	int other = sum - all;
	ans[ids.back()] = other;

	cout << "!";
	FOR(i,1,n) cout << " " << ans[i];
}