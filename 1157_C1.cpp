#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, a[N], ans;


string solve(int l, int r, int prev){

	if(l > r)
		return "";

	int left = a[l], right = a[r];

	if(left > prev && right > prev){
		
		if(left == right){
			string ans1 = "L" + solve(l + 1, r, left);
			string ans2 = "R" + solve(l, r - 1, right);
			return (sz(ans1) > sz(ans2) ? ans1 : ans2);
		}else if(left < right){
			return "L" + solve(l + 1, r, left);
		}else{
			return "R" + solve(l, r - 1, right);
		}


	}else if(left > prev){
		return "L" + solve(l + 1, r, left);
	}else if(right > prev){
		return "R" + solve(l, r - 1, right);	
	}
	return "";
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	#endif

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	string ans = solve(1, n, 0);
	cout << sz(ans) << '\n';
	cout << ans << '\n';
}

