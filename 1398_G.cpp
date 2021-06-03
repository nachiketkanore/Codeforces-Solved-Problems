/*
Author: Nachiket Kanore
Created: Thursday 04 March 2021 10:55:46 AM IST
(ツ) You can't let praise or criticism get to you. It's a weakness to get caught up in either one.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <complex>
#include <cstring>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const double PI = acos(-1);
 
namespace fft{
	typedef complex<double> base;
	void fft(vector<base> &v, bool inv){
		vector<base> w(v.size());
		for(int i=2; i<= sz(v); i<<=1){
			int bsz = v.size() / i;
			base ang(cos(2 * PI / i), sin(2 * PI / i));
			if(inv) ang = base(1, 0) / ang;
			for(int j=0; j<bsz; j++){
				for(int k=0; k<i; k++){
					w[k] = v[bsz * k + j];
				}
				base pw(1, 0);
				for(int k=0; k<i/2; k++){
					base a = w[2*k], b = w[2*k+1] * pw;
					v[bsz * k + j] = a + b;
					v[bsz * k + j + v.size()/2] = a - b;
					pw *= ang;
				}
			}
		}
		if(inv){
			for(int i=0; i< sz(v); i++){
				v[i] /= v.size();
			}
		}
	}
	vector<int> multiply(vector<int> &v, vector<int> &w){
		vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
		int n = 1;
		while(n < max(sz(v), sz(w))) n <<= 1;
		n <<= 1;
		fv.resize(n);
		fw.resize(n);
		fft(fv, 0);
		fft(fw, 0);
		for(int i=0; i<n; i++) fv[i] *= fw[i];
		fft(fv, 1);
		vector<int> ret(n);
		for(int i=0; i<n; i++) ret[i] = (round(fv[i].real()) > 0);
		return ret;
	}
}

const int N = 2e5 + 5, M = 2e6 + 5;
int n, x, y, a[N], answer[M+1];
bool poss[M+1];
vector<int> A(M), B(M);

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> x >> y;
	++n;
	FOR (i,1,n) {
		cin >> a[i];
		A[a[i]] = 1;
		B[-a[i] + N] = 1;
	}
	memset(answer, -1, sizeof(answer));

	while (sz(A) && A.back() == 0) A.pop_back();
	while (sz(B) && B.back() == 0) B.pop_back();

	vector<int> C = fft::multiply(A, B);

	const int m = sz(C);
	FOR (i,0,m-1) if (C[i] > 0) {
		int len = abs(i - N);
		if (len > 0) {
			see(len);
			poss[2 * len + 2 * y] = true;
		}
	}

	
	FOR (i,1,M) {
		if (poss[i]) { 
			for (int mul = i; mul <= M; mul += i) 
				cmax(answer[mul], i);
		}
	}
	int q;	cin >> q;
	while (q--) {
		int L;	cin >> L;
		cout << answer[L] << ' ';
	}
}
