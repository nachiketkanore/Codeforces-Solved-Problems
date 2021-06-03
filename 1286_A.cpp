#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 100 + 2, inf = 1e18;

int n, a[N];
set<int> given;
int even, odd;
int dp[2][N][N][N];

int go(int id, int remEven, int remOdd, bool prev){
    if(remOdd < 0 || remEven < 0)
        return inf;
    if(id > n)
        return 0;

    int &ans = dp[prev][id][remEven][remOdd];
    if(~ans)
        return ans;
    ans = inf;

    if(a[id] == 0){
        int c1 = (prev ^ 0) + go(id + 1, remEven - 1, remOdd, 0);
        int c2 = (prev ^ 1) + go(id + 1, remEven, remOdd - 1, 1);
        ans = min({ans, c1, c2});
    }
    else{
        int c1 = (prev ^ (a[id] & 1)) + go(id + 1, remEven, remOdd, a[id] & 1);
        ans = min(ans, c1);
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    FOR(i,1,n){
        cin >> a[i];
        if(a[i] != 0)
            given.insert(a[i]);
    }
    FOR(i,1,n){
        if(given.count(i) == 0)
            even += i % 2 == 0,
            odd += i % 2 == 1;
    }

    memset(dp, -1, sizeof(dp));
    int ans = inf;

    if(a[1] == 0){
        if(odd > 0)
            ans = min(ans, go(2, even, odd - 1, 1));
        if(even > 0)
            ans = min(ans, go(2, even - 1, odd, 0));
    }
    else{
        ans = min(ans, go(2, even, odd, a[1]&1));
    }
    cout << ans;
}
