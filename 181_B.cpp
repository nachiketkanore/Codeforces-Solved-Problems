#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int cnt[2200][2200];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    int x[n], y[n];
    FOR(i,0,n-1) {
        cin >> x[i] >> y[i];
        x[i] += 1002;
        y[i] += 1002;
        cnt[x[i]][y[i]]++;
    }    
    int ans = 0;
    FOR(i,0,n-1) FOR(j,i+1,n-1) {
        if((x[i] + x[j]) % 2) continue;
        if((y[i] + y[j]) % 2) continue;
        int mx = (x[i] + x[j])/2;
        int my = (y[i] + y[j])/2;
        ans += cnt[mx][my];
    }
    cout << ans;
}
