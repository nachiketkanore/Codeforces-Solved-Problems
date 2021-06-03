#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

long long modpow(long long a, long long b, long long m) {
    long long p = 1, q = a;
    for (int i = 0; i < 32; i++) {
        if ((b / (1LL << i)) % 2 == 1) { p *= q; p %= m; }
        q *= q; q %= m;
    }
    return p;
}
 
long long Div(long long a, long long b, long long m) {
    return (a * modpow(b, m - 2, m)) % m;
}
 
long long mod = 1e9 + 7;
long long fact[1 << 20], factinv[1 << 20];
 
void init() {
    fact[0] = 1;
    for (int i = 1; i <= 1000000; i++) fact[i] = (1LL * i * fact[i - 1]) % mod;
    for (int i = 0; i <= 1000000; i++) factinv[i] = Div(1, fact[i], mod);
}
 
long long ncr(long long n, long long r) {
    return (fact[n] * factinv[r] % mod) * factinv[n - r] % mod;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    init();

    int ans = 0;
    int a, b, n;
    cin >> a >> b >> n;
    FOR(aCount,0,n){
        int bCount = n - aCount;
        int sumOfDigits = a * aCount + b * bCount;
        bool chk = true;
        while(sumOfDigits) {
            int dig = sumOfDigits % 10;
            chk &= (dig == a or dig == b);
            sumOfDigits /= 10;
        }
        if(chk){
            ans = (ans + ncr(n, aCount)) % mod;
        }
    }
    cout << ans << '\n';
}
