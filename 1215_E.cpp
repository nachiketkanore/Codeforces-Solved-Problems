#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 4e5 + 5, mod = 1e9 + 7, inf = 1e18;

int n, a[N], cost[22][22], dp[1 << 20];

void calc(int i, int j){
    int &keep = cost[i][j];
    int swaps = 0;
    for(int k = 1; k <= n; k++){
        if(a[k] == j)
            swaps++;
        if(a[k] == i)
            keep += swaps;
    }
}

int go(int mask){
    int done = __builtin_popcountll(mask);
    if(done == 20)
        return 0;

    int &ans = dp[mask];
    if(~ans)
        return ans;
    ans = inf;

    for(int next = 0; next < 20; next++) if((mask >> next & 1LL) == 0){
        int temp = 0;
        for(int prev = 0; prev < 20; prev++) if((mask >> prev & 1LL)){
            temp += cost[prev][next];
        }
        temp += go(mask | (1LL << next));
        ans = min(ans, temp);
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

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        --a[i];
    }

    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++) if(i != j)
            calc(i, j);

    cout << go(0);
}