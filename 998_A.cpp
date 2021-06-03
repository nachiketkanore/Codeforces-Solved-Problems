#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, a[12];


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int mask = 0; mask < (1 << n); mask++){

		int one = 0, two = 0;
		int c1 = 0, c2 = 0;
		std::vector<int> _1, _2;
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)){
				c1++, one += a[i];
				_1.push_back(i);
			}else{
				c2++, two += a[i];
				_2.push_back(i);
			}
		}

		if(c1 && c2){
			if(one != two){
				cout << _1.size() << '\n';
				for(int x : _1)
					cout << x+1 << ' ';
				return 0;
			}
		}

	}
	cout << -1;
}
