#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 2e3 + 3, inf = 1e18;

int n, k, p, a[N], b[N], dp[N][N];

int go(int id1, int id2){
    if(id1 > n)
        return 0;
    if(id2 > k)
        return inf;

    int& ans = dp[id1][id2];
    if(~ans)
        return ans;

    int c1 = max(abs(a[id1] - b[id2]) + abs(b[id2] - p), go(id1 + 1, id2 + 1));
    int c2 = go(id1, id2 + 1);
    return ans = min(c1, c2);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    memset(dp, -1, sizeof(dp));
    cin >> n >> k >> p;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= k; ++i)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);
    cout << go(1, 1);
}
