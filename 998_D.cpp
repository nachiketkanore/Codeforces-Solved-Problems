#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 3e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
set<int> dist;
int n;
int ans[] = {0,4,10,20,35,56,83,116,155,198,244,292,341,390,439};


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	
	cin >> n;
	if(n <= 12)
		cout << ans[n] << '\n';
	else{
		int ahead = n - 12;
		int anss = ahead * 49 + ans[12];
		cout << anss << '\n';
	}
}

/*
4
10
20
35
56
83
116
155
198
244
292
341
390
*/
