//It's time to be who I am, rather than who I am supposed to be.
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1000;
const int inf = 1e12;
int n, m, k, ans;

int countLess(int val){
	int ret = 0;
	for(int i = 1; i <= n; i++){
		int add = (val % i == 0 ? val/i - 1 : val/i);
		add = min(add, m);
		ret += add;
	}
	return ret;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> m >> k;

	int lo = 1, hi = m*n;
	while(lo <= hi){
		int mid = (lo + hi)/2;
		if(countLess(mid) < k)
			ans = mid, lo = mid + 1;
		else hi = mid - 1;
	}

	cout << ans << '\n';

}