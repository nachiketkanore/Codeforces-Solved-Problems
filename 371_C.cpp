#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
string s;
int haveA, haveB, haveC, costA, costB, costC, money, reqA, reqB, reqC;

bool canMake(int burgers){
	int cost = 0;

	int wantA = max(0LL, reqA * burgers - haveA);
	int wantB = max(0LL, reqB * burgers - haveB);
	int wantC = max(0LL, reqC * burgers - haveC);

	cost = wantC * costC + wantB * costB + wantA * costA;

	return cost <= money;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> s;
	cin >> haveA >> haveB >> haveC;
	cin >> costA >> costB >> costC;
	cin >> money;

	for(char ch : s){
		reqA += ch == 'B';
		reqB += ch == 'S';
		reqC += ch == 'C';
	}

	int ans = 0;
	int lo = 0, hi = 1e13;
	while(lo <= hi){
		int mid = (lo + hi)/2;
		if(canMake(mid)){
			ans = mid;
			lo = mid + 1;
		}else {
			hi = mid - 1;
		}
	}
	cout << ans << '\n';
}