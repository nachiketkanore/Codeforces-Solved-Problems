#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5e5 + 5, mod = 1e9 + 7, inf = 1e17;

void solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    while(t--)
        solve();
}

void solve(){
    int a[4], d;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> d;
    int cnt[d + 2] = {0};
    for(int i = 0; i < 4; i++)
        for(int j = a[i]; j <= d; j += a[i])
            cnt[j] = 1;
    cout << accumulate(cnt, cnt + d + 2,0LL) << '\n';
}