/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 11:17:25 PM IST
(ツ) There is no greater harm than that of time wasted.
*/
#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, q, answer = 0;
	cin >> n >> q;
	vector<string> all;
	map<string, string> f;
	for (int i = 0; i < q; ++i) {
		string a, b;
		cin >> a >> b;
		f[a] = b;
	}
	function<void(string)> gen = [&](string curr) {
		if ((int)curr.size() == n) {
			all.push_back(curr);
			return;
		}
		for (char ch = 'a'; ch <= 'f'; ch++) {
			gen(curr + ch);
		}
	};
	gen("");
	auto transformed = [&](string s) {
		while ((int)s.size() >= 2) {
			string A, B;
			for (int i = 0; i < (int)s.size(); i++) {
				if (i <= 1) A.push_back(s[i]);
				else B.push_back(s[i]);
			}
			if (!f.count(A)) return string("F");
			A = f[A];
			s = A + B;
		}
		return s;
	};
	for (string s : all) {
		if (transformed(s) == "a") {
			++answer;
		}
	}
	cout << answer << '\n';
}
