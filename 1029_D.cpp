#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)

const int N = 2e5 + 2;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//Now we can simply define our unordered_map or our gp_hash_table as follows:
//Use either, both are significantly fast

unordered_map<long long, int, custom_hash> cnt[11];

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//write above 2 lines after namespace std
//gp_hash_table<long long, int, custom_hash> safe_hash_table;

int n, k, a[N];
int len[N];
long long ans;

int LEN(int n) {
    return (n ? 1 + LEN(n/10) : 0);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i,1,n) {
        cin >> a[i];
        len[i] = LEN(a[i]);
        cnt[len[i]][a[i] % k]++;
    }    
    FOR(i,1,n) {
        cnt[len[i]][a[i] % k]--;

        // N % k = first * power(10, len) % k + second % k
        // 0 = A % k + B % k
        int power = 1;
        FOR(len,1,10) {
            power = (power * 10) % k;
            int A = (1LL * a[i] * power) % k;
            A = (k - A) % k;
            ans += 1LL * cnt[len][A];
        }

        cnt[len[i]][a[i] % k]++;
    }
    cout << ans;
}
