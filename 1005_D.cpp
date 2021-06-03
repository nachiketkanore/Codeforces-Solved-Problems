#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

string s;
int n, dp[N][3];

int go(int id, int mod){
    if(id >= n)
        return mod == 0;

    int &ans = dp[id][mod]; if(~ans) return ans;

    if(mod == 0){
        ans = 1 + go(id + 1, (s[id] - '0') % 3);
        return ans;
    }

    //continue with number
    int c1 = go(id + 1, (10 * mod + (s[id] - '0')) % 3);
    //create new number from this index
    int c2 = go(id + 1, (s[id] - '0') % 3);
    return ans = max(c1, c2);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    memset(dp, -1, sizeof(dp));
    cin >> s;
    n = sz(s);
    int ans = go(1, (s[0] - '0') % 3);
    cout << ans << '\n';
}
