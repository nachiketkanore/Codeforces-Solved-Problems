/**
 *	Author: Nachiket Kanore
 *	Created: Tuesday 04 May 2021 11:08:58 PM IST
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
#include <chrono>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;
using namespace std::chrono;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

struct starter{
	high_resolution_clock::time_point t1, t2;
	starter() {
		ios::sync_with_stdio(0); cin.tie(0);
		t1 = high_resolution_clock::now();
	}
	~starter() {
		t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		cerr << "It took " << time_span.count() << " seconds.";
	}
} starter_;

const int inf = 1e18;
const int N = 5e5 + 5;

int32_t main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	double me_win = 1. * a / b;
	double me_lose = 1. - me_win;
	double he_win = 1. * c / d;
	double he_lose = 1. - he_win;

	int me_turns = 0;
	int he_turns = 0;
	double ans = 0;

	FOR (i,1,1000000) {
		if (i&1) {
			ans += pow(me_lose, me_turns) * pow(he_lose, he_turns) * me_win;
			me_turns++;
		}
		else he_turns++;
	}

	printf("%0.12f\n", ans);
}
