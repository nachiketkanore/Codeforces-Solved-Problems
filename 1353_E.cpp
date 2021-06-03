#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 1e6 + 2, inf = 1e18;

int n, k, len, dp[3][N];
string s;
vector<bool> v;

void solve();

int go(int id, int tc){
    if(id >= len)
        return 0;
    int &ans = dp[tc][id];
    if(~ans)
        return ans;
    if(tc == 0){
        int c1 = v[id] + go(id + 1, 0);
        int c2 = !v[id] + go(id + 1, 1);
        ans = min(c1, c2);
    }
    else if(tc == 1){
        int c1 = !v[id] + go(id + 1, 1);
        int c2 = v[id] + go(id + 1, 2);
        ans = min(c1, c2);
    }else{
        int c1 = v[id] + go(id + 1, 2);
        ans = c1;
    }
    return ans;
}

int find(std::vector<bool> &x){
    len = sz(x);
    for(int i = 0; i <= len; i++)
        dp[0][i] = dp[1][i] = dp[2][i] = -1;
    return go(0, 0);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    cin >> n >> k >> s;
    int total = 0;
    for(auto &ch : s)
        total += (ch - '0');
    int ans = total;
    for(int i = 0; i < k; i++){
        v.clear();
        for(int j = i; j < n; j+=k)
            v.push_back(s[j] - '0');
        int inside = 0;
        for(auto x : v)
            inside += x;
        int curr = total - inside;
        curr += find(v);
        ans = min(ans, curr);
    }
    cout << ans << '\n';
}