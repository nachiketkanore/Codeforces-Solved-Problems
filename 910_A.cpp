#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, d;
char s[N];
int dp[N];

int go(int id){
    if(s[id] == '0')
        return inf;
    if(id >= n)
        return (id == n ? 0 : inf);

    int &ans = dp[id];
    if(~ans)
        return ans;
    ans = inf;

    FOR(i,1,d){
        int get = 1 + go(id + i);
        ans = min(ans, get);
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
    cin >> n >> d;
    FOR(i,1,N-1){
        if(i <= n)
            cin >> s[i];
        else 
            s[i] = '0';
    }
    cout << (go(1) >= inf? -1 : go(1)) << '\n';
}
