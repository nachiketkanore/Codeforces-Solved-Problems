#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

vector<string> a;
string s;
int n;
int dp[2][N];

int go(int id, int want){
    if(want == 2)
        return 1;
    if(id >= n)
        return 0;
    int &ans = dp[want][id];
    if(~ans)
        return ans;

    ans = go(id + 1, want);
    string curr;
    curr.push_back(s[id - 1]);
    curr.push_back(s[id]);
    if(a[want] == curr){
        ans |= go(id + 2, want + 1);
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

    cin >> s;
    n = sz(s);
    a.push_back("AB"); a.push_back("BA");
    memset(dp, -1, sizeof(dp));
    bool ans = go(1,0);
    reverse(a.begin(), a.end());
    memset(dp, -1, sizeof(dp));
    ans |= go(1,0);
    cout << (ans ? "YES" : "NO" ) << '\n';
}
