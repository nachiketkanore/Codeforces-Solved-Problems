/*
Author: Nachiket Kanore
Created: Friday 19 February 2021 12:46:28 PM IST
(ツ) Age does not protect you from love. But love, to some extent, protects you from age.
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
 
const int N = 5e5 + 5, inf = 1e18;

int n, a[N], tree[N << 2], cnt;

void PULL(int u) { tree[u] = __gcd(tree[2*u], tree[2*u+1]); }

void upd(int u, int tl, int tr, int id, int val) {
	if (tl == tr) { assert (tl == id);  tree[u] = val; return; }
	int mid = (tl + tr) / 2;
	if (id <= mid) upd(2*u, tl, mid, id, val); else upd(2*u+1, mid+1, tr, id, val);
	PULL(u);
}
void update(int id, int val) { upd(1, 1, n, id, val); }

void qry(int u, int tl, int tr, int ql, int qr, int x) {
	if (tl > tr || ql > qr) return;
	if (tree[u] % x == 0) return;
	if (tl == tr) { ++cnt; return; }
	int mid = (tl + tr) / 2;
	if (cnt < 2 && ql <= mid) qry(2*u, tl, mid, ql, qr, x);
	if (cnt < 2 && qr > mid) qry(2*u+1, mid+1, tr, ql, qr, x);
}

void query(int L, int R, int x) { qry(1, 1, n, L, R, x); }

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	FOR (i,1,n) {
		cin >> a[i];
		update(i, a[i]);
	}
	int Q;	cin >> Q;
	while (Q--) {
		int type;	cin >> type;
		if (type == 1) {
			int L, R, x;
			cin >> L >> R >> x;
			cnt = 0;
			query(L, R, x);
			cout << (cnt <= 1 ? "YES\n" : "NO\n");
		} else {
			int id, val;
			cin >> id >> val;
			update(id, val);
		}
	}
}
