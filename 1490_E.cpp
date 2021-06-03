/*
Author: Nachiket Kanore
Created: Thursday 18 February 2021 07:28:49 PM IST
(ツ) Build a better mousetrap and the world will beat a path to your door.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n;	cin >> n;
	vector<pair<int,int>> a(n+1);
	vector<int> pref(n+1);
	FOR (i,1,n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(ALL(a));
	FOR (i,1,n) {
		pref[i] = pref[i-1] + a[i].first;
	}
	bool allOK = true;
	vector<int> answers;

	for (int i = n; i; i--) {
		if (i < n)
			allOK &= pref[i] >= a[i+1].first;
		if (allOK)
			answers.push_back(a[i].second);
	}
	sort(ALL(answers));
	cout << sz(answers) << '\n';
	for (int id : answers) cout << id << ' ';
		cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T = 1;
	cin >> T;
	while (T--)
		solve();
}
