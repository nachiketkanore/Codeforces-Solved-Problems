#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int divs, ans = inf;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
const int p = 16;

void solve(int id, int val, int divisors){

	if(divisors > divs)
		return;
	if(divisors == divs)
		ans = min(ans, val);

	for(int power = 1; power <= 60; power++){
		if(val * primes[id] >= ans)
			return;
		solve(id+1, val *= primes[id], divisors * (power + 1));
	}
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    #ifndef ONLINE_JUDGE
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif	

    cin >> divs;
    solve(0,1,1);
    cout << ans << '\n';
}

