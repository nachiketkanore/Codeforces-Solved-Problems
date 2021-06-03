/*
Author: Nachiket Kanore
Created: Saturday 20 February 2021 12:25:32 AM IST
(ツ) Fear not for the future, weep not for the past.
*/
#include <bits/stdc++.h>

#define int long long
using namespace std;

const int _ = 201;
int dp[_][_][_][3];

int ok(int a, int b, int c, int want) {
	if (a+b+c == 1) {
		if (want == 0 && a == 1) return 1;
		if (want == 1 && b == 1) return 1;
		if (want == 2 && c == 1) return 1;
		return 0;
	}
	int &ans = dp[a][b][c][want];
	if (~ans) return ans;
	ans = 0;
	
	if (a > 0 && b > 0) ans |= ok(a-1, b-1, c+1, want);
	if (b > 0 && c > 0) ans |= ok(a+1, b-1, c-1, want);
	if (a > 0 && c > 0) ans |= ok(a-1, b+1, c-1, want);

	if (a >= 2) ans |= ok(a-1, b, c, want);
	if (b >= 2) ans |= ok(a, b-1, c, want);
	if (c >= 2) ans |= ok(a, b, c-1, want);

	return ans;
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, a = 0, b = 0, c = 0;
	cin >> n;
	string s;	cin >> s;
	for (char &ch : s) {
		if (ch == 'B') a++;
		else if (ch == 'G') b++;
		else c++;
	}

	memset(dp, -1, sizeof(dp));
	string answer;
	if (ok(a, b, c, 0)) answer += 'B';
	if (ok(a, b, c, 1)) answer += 'G';
	if (ok(a, b, c, 2)) answer += 'R';
	cout << answer << '\n';
}
