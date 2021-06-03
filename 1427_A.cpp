/*
Author: Nachiket Kanore
Created: Monday 26 October 2020 04:09:02 PM IST
(ツ) No day in which you learn something is a complete loss.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int n, sum = 0;
		vector<int> pos, neg;

		cin >> n;
		FOR (i,1,n) {
			int u;
			cin >> u;
			sum += u;
			if (u >= 0) pos.push_back(u);
			else neg.push_back(u);
		}

		sort(pos.rbegin(), pos.rend());

		if (sum == 0) cout << "NO\n";
		else {
			cout << "YES\n";
			if (sum > 0) {
				for (int x : pos) cout << x << " ";
				for (int x : neg) cout << x << " ";
					cout << '\n';
			} else if (sum < 0) {
				for (int x : neg) cout << x << " ";
				for (int x : pos) cout << x << " ";
					cout << '\n';
			} else assert(0);
		}
	}
}
