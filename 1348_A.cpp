#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5e5 + 5, mod = 1e9 + 7, inf = 1e17;

void solve();

int n, dp[35][30][30];

int go(int id, int one, int two){
    if(id > n)
        return (one == n/2 && two == n/2 ? 0 : inf);

    int &ans = dp[id][one][two];
    if(~ans)
        return ans;
    int val = 1LL << id;

    int c1 = val + go(id + 1, one + 1, two);
    int c2 = -val + go(id + 1, one, two + 1);
    ans = min(abs(c1), abs(c2));
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    int one = 0, two = 0;
    cout << go(1, 0, 0) << '\n';
}