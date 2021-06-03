/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 12:52:10 AM IST
(ツ) Once we accept our limits, we go beyond them.
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
 
const int N = 1e5+5, C = 11;

const int SZ=100;
struct BIT2D { 
    int bit[SZ+1][SZ+1];
    BIT2D(int n = SZ, int m = SZ) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
               bit[i][j] = 0;
    }
    void upd(int X, int Y, int val) {
        for (; X <= SZ; X += (X&-X))
            for (int Y1 = Y; Y1 <= SZ; Y1 += (Y1&-Y1))
                bit[X][Y1] += val;
    }
    int query(int X, int Y) {
        int ans = 0;
        for (; X > 0; X -= (X&-X))
            for (int Y1 = Y; Y1 > 0; Y1 -= (Y1&-Y1))
                ans += bit[X][Y1];
        return ans;
    }
    int getSum(int R1, int R2, int C1, int C2) {
    	int X1 = min(R1, R2);
    	int Y1 = min(C1, C2);
    	int X2 = max(R1, R2);
    	int Y2 = max(C1, C2);
    	assert(X1 <= X2 && Y1 <= Y2);
    	int ans = query(X2, Y2) - query(X2, Y1-1) - query(X1-1, Y2) + query(X1-1,Y1-1);
    	return ans;
    }
};

int n, q, c;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q >> c;	
	vector<BIT2D> cnts(c+1, BIT2D());
	for (int i = 0; i < n; i++) {
		int x, y, s;
		cin >> x >> y >> s;
		cnts[s % (c + 1)].upd(x, y, 1);
	}
	while (q--) {
		int answer = 0;
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		for (int i = 0; i <= c; i++) {
			int contrib = (i + t) % (c + 1);
			contrib *= cnts[i].getSum(x1, x2, y1, y2);
			answer += contrib;
		}
		cout << answer << '\n';
	}
}
