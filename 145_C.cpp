#include <bits/stdc++.h>

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
const int N = 1e5 + 5, M = 5050;

const int MOD = 1e9 + 7;
struct mi {
	using ll = long long;
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
	mi& operator+=(const mi& m) { if ((v += m.v) >= MOD) v -= MOD; return *this; }
	mi& operator-=(const mi& m) { if ((v -= m.v) < 0) v += MOD;	return *this; }
	mi& operator*=(const mi& m) { v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }

	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
			return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); return pow(a,MOD-2);	}

	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	mi operator++(int32_t) { mi temp; temp.v = v++; return temp; }
	mi operator--(int32_t) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
	friend ostream& operator<<(ostream& os, const mi& m) {
		os << m.v; return os;
	}
	friend istream& operator>>(istream& is, mi& m) {
		ll x; is >> x;
		m.v = x;
		return is;
	}
};

mi fact[N+1];

mi choose(int x, int y) {
    if (y > x) return mi(0);
    return fact[x] / fact[y] / fact[x - y];
}

bool is_lucky(int n) {
    bool yes = true;
    while (n) {
        yes &= n % 10 == 4 || n % 10 == 7;
        n /= 10;
    }
    return yes;
}

int n, k, tot_lucky, others;
int a[N], lucky_cnt[M];
vector<int> all_lucky;
int id;
mi dp[M][M];
bool vis[M][M];

void normalize() {
    sort(ALL(all_lucky));
    id = 1;
    const int m = sz(all_lucky);
    for (int i = 0; i < m; ) {
        int cnt = 0;
        int j = i;
        while (j < m && all_lucky[i] == all_lucky[j]) {
            ++j;
            ++cnt;
        }
        lucky_cnt[id] = cnt;
        id++;
        i = j;
    }
    assert(id < M);
}

// lucky_id < id and lucky_chosen <= k
mi go(int lucky_id, int lucky_chosen) {
    if (lucky_chosen > k) return mi(0);
    if (lucky_id == id) {
        int remaining = k - lucky_chosen;
        return choose(others, remaining);
    }
    if (vis[lucky_id][lucky_chosen]) return dp[lucky_id][lucky_chosen];
    vis[lucky_id][lucky_chosen] = true;
    mi& ans = dp[lucky_id][lucky_chosen];
    ans = go(lucky_id + 1, lucky_chosen);
    ans += lucky_cnt[lucky_id] * go(lucky_id + 1, lucky_chosen + 1);
    return ans;
}

void pre() {
    fact[0] = 1;
    FOR (i,1,N) fact[i] = i * fact[i - 1];
}

int32_t main() {
    pre();
    cin >> n >> k;
    FOR (i,1,n) {
        cin >> a[i];
        if (is_lucky(a[i])) {
            ++tot_lucky;
            all_lucky.push_back(a[i]);
        } else {
            others++;
        }
    }
    normalize();
    cout << go(1, 0) << '\n';
}
