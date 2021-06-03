//It's time to be who I am, rather than who I am supposed to be.
#include <bits/stdc++.h>
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5e5 + 10;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> 


int32_t main(){ 
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif


	ordered_set o_set; 

	int n;
	cin >> n;
	long long a[n], b[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];

	long long ans = 0;

	for(int i = 0; i < n; i++){
		long long val = a[i] - b[i];
		long long add = o_set.order_of_key(val);
		ans += add;
		o_set.insert(-val);
	}

	cout << ans << '\n';
}
	