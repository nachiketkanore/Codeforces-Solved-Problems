#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 1e5 + 2;
const long long LEN = 19, mod = 1e9 + 7;

long long n, u, cnt[80];
int nmask[80];
vector<int> primes;
int dp[71][1 << LEN];

bool checkPrime(int n){
	if(n < 2)
		return false;
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

long long power(long long a, long long b, long long p = mod){
	long long ret = 1;
	a %= p;
	while(b > 0){
		if(b % 2 == 1)
			ret = ret * a % p;
		b /= 2;
		a = a * a % p;
	}
	return ret;
}

int go(int id, int prod){
	if(id > 70)
		return prod == 0;

	int &ans = dp[id][prod];
	if(~ans)
		return ans;

	int newProd = nmask[id] ^ prod;

	long long c1 = 0;
	if(cnt[id] != 0)
		c1 = 1LL * (power(2LL, cnt[id] - 1) * go(id + 1, newProd));
	c1 %= mod;

	long long c2 = 1;
	if(cnt[id] != 0)
		c2 = 1LL * power(2LL, cnt[id] - 1) * go(id + 1, prod);
	else
		c2 = 1LL * go(id + 1, prod);

	c2 %= mod;

	return ans = (c1 + c2) % mod;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	memset(dp, -1, sizeof(dp));
	cin >> n;
	FOR(i,1,n){
		cin >> u;
		cnt[u]++;
	}
	FOR(x,2,70) if(checkPrime(x)) primes.push_back(x);

	FOR(x,2,70){
		int num = x, mask = 0;
		FOR(i,0,sz(primes)-1){
			int cnt = 0;
			while(num % primes[i] == 0)
				++cnt, num /= primes[i];
			mask |= (cnt % 2) << i;
		}
		nmask[x] = mask;
	}

	int ans = go(1, 0) - 1;
	cout << ans;
}
