#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int ans = -inf;
int n, a[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    ans = max(ans, a[n]);
    ans = max(ans, -a[n]);

    FOR(i,1,n){
        ans = max(ans, -a[i] + (a[n] - a[i]));
        ans = max(ans, -(a[n] - a[i - 1]) + a[i - 1]);
    }

    int maxSumSubarray = -inf;
    int prevMin = inf;
    FOR(i,1,n){
        maxSumSubarray = max(maxSumSubarray, a[i] - prevMin);
        prevMin = min(prevMin, a[i]);
    }
    ans = max(ans, 2 * maxSumSubarray - a[n]);
    cout << ans << '\n';
}
