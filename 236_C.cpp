/**
 *	Author: Nachiket Kanore
 *	Created: Thursday 13 May 2021 11:40:33 PM IST
**/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <string>
#include <cstring>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 1e6 + 5;

vector<int> primes;
bool prime[N+1];

int lcm(int a, int b){
	return (a*b)/__gcd(a,b);
}

int lcm(int a, int b, int c) {
	return lcm(lcm(a, b), c);
}

int32_t main() {
	FOR (i,2,N) prime[i] = true;
	FOR (i,2,N) if (prime[i]) for (int j = i<<1; j <= N; j += i) prime[j] = false;
	int n;
	cin >> n;
	FOR (i,2,n) if (prime[i]) primes.push_back(i);
	int ans = 0;
	if (n <= 100) FOR (i,1,n) FOR (j,1,n) FOR (k,1,n) cmax(ans, lcm(i, j, k));
	else {
		ans = n;
		FOR (i,n-69,n) FOR (j,n-69,n) FOR (k,n-69,n) cmax(ans, lcm(i, j, k));
	}
	assert(ans >= n);
	cout << ans;
}
