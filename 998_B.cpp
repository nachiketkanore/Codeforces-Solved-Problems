#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, a[105], cost, ans;


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> cost;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	std::vector<int> vals;
	int even = 0, odd = 0;
	if(a[1] & 1) odd++;
	else even++;

	for(int i = 2; i < n; i++){
		odd += a[i] % 2 == 1;
		even += a[i] % 2 == 0;
		if(odd == even){
			int curr = abs(a[i+1] - a[i]);
			vals.push_back(curr);
			odd = even = 0;
		}
	}

	sort(vals.begin(), vals.end());

	for(int i = 0; i < sz(vals); i++)
		if(vals[i] <= cost)
			++ans, cost -= vals[i];

	cout << ans << '\n';

}
