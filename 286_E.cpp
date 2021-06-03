/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 07 April 2021 12:16:48 PM IST
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

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;

#include <complex>
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
		for(int i=0; i<n; i++) ret[i] = (round(fv[i].real()) > 0);	// remove to get actual coefficients
		return ret;
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> have(m+1);
	FOR (i,1,n) {
		int bag;
		cin >> bag;
		have[bag] = 1;
	}
	vector<int> poss = fft::multiply(have, have);
	vector<int> should_take;
	FOR (i,1,m) {
		if (have[i]) {
			if (!poss[i]) {
				should_take.push_back(i);
			}
		} else {
			if (poss[i]) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n" << sz(should_take) << '\n';
	for (int take : should_take) {
		cout << take << ' ';
	}
}
