#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 3e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, x, y;
string s;


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> x >> y;
	cin >> s;
	string new_s;

	int ones = 0, zeros = 0;
	new_s.push_back(s[0]);
	for(int i = 1; i < n; i++){
		if(new_s.back() == s[i])
			continue;
		new_s.push_back(s[i]);
	}	
	s = new_s;
	for(char ch : s)
		ones += ch == '1', 
		zeros += ch == '0';

	int ans = inf;
	if(zeros == 1){
		cout << y << '\n';
		return 0;
	}else if(zeros == 0){
		cout << 0 << '\n';
		return 0;
	}

	for(int revs = 0; revs <= ones; revs++){
		int flips = zeros - revs;
		if(flips > 0){
			ans = min(ans, flips * y + revs * x);
		}
	}

	
	cout << ans << '\n';
}
