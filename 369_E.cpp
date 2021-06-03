#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <array>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const map<A, B> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(mt_rng); }

template<int D, typename T> struct vec : public vector<vec<D - 1, T>> {
	static_assert(D >= 1, "Dimensions invalid");
	template<typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {}
};
template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, const T& val = T()) : vector<T>(n, val) {} };

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
} bit(1000005);

const int N = 1e6+5, inf = 1e18;
int n, Q;
vector<int> lefts[N];
vector<pair<int,int>> queries[N];
int ans[N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> Q;

	FOR (i,1,n) {
		int L, R;
		cin >> L >> R;
		lefts[R].push_back(L);
	}

	// Number of segments with atleast one point common with P = { ... }
	// is same as (Total segments - Number of segments having no common points with P = { ... })

	FOR (qId,1,Q) {
		int cnt;	cin >> cnt;
		int SMALL = 0, LARGE = 1000001;
		vector<int> pts;
		pts.push_back(SMALL);
		FOR (j,1,cnt) {
			int pt;	cin >> pt;
			pts.push_back(pt);
		}
		pts.push_back(LARGE);

		for (int i = 1; i < sz(pts); i++) {
			int L = pts[i-1]+1;
			int R = pts[i]-1;
			queries[R].push_back({L, qId});
		}
	}

	FOR (x,0,N-1) {
		for (int L : lefts[x]) {
			bit.add(L, 1);
		}
		// Now we have all segments with right endpoints <= x
		// Now answer all queries for with right endpoint = x

		for (auto it : queries[x]) {
			int qLeft = it.first;
			int qId = it.second;

			int add = bit.sum(qLeft, N);
			ans[qId] += add;
		}
	}

	FOR (i,1,Q) {
		cout << (n - ans[i]) << "\n";
	}
}