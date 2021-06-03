#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 1e6 + 5, inf = 1e18;

int prime[N + 1];
int cntPrimes[N + 1];

void pre() {
	fill(prime + 2, prime + N, true);
	for (int i = 2; i <= N; i++) if (prime[i]) {
		for (int j = 2 * i; j <= N; j += i) {
			prime[j] = false;
		}
	}
	int cnt = 0;
	FOR(i,0,N) {
		cnt += prime[i];
		cntPrimes[i] = cnt;
	}
}

int Pi(int n) {
	return cntPrimes[n];
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	// int n = 100;

	// FOR(i,1,n) {
	// 	// cout << i << "==============" << '\n';
	// 	vector<bool> has(i + 1, false);
	// 	for (int a = 1; a <= i; a++) {
	// 		for (int b = 1; b <= i; b++) if (a != b) {
	// 			int one = __gcd(a, b);
	// 			int two = a/ one;
	// 			int three = b/ one;
	// 			if ((one + two > three) && (one + three > two) && (three + two > one)) {
	// 				has[a] = true;
	// 				has[b] = true;
	// 			}
	// 		}
	// 	}
	// 	int cnt = 0;
	// 	FOR(j,1,i) {
	// 		if (!has[j]) {
	// 			++cnt;
	// 			// cout << j << ' ';
	// 		}	
	// 	}
	// 	cout << cnt;
	// 	cout << '\n';
	// 	// cout << cnt << '\n';
	// }
	// https://oeis.org/search?q=1+2+3+2+3+3+4+4+3+3+4+4+5+5&sort=&language=english&go=Search
	
	pre();

	int T;
	cin >> T;
	while (T--) {
		int n;	cin >> n;
		int root = sqrt(n);
		int ans = Pi(n) - Pi(root) + 1;
		cout << ans << '\n';
	}
}