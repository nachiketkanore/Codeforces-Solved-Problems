//It's time to be who I am, rather than who I am supposed to be.
#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1000;
const int inf = 1e12;


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = sz(s);
		int ans = 0, cnt = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == 'L')
				cnt++, ans = max(ans, cnt);
			else cnt = 0;
		}
		cout << ++ans << '\n';
	}
}