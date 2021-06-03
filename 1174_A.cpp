#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(2 * n);
    for(int& x : a) cin >> x;
    sort(a.begin(), a.end());
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < (n << 1); i++) {
        if(i >= n) sum2 += a[i];
        else sum1 += a[i];
    }    
    if(sum1^sum2) {
        for(int x : a) cout << x << ' ';
    }else {
        cout << -1;
    }
}
