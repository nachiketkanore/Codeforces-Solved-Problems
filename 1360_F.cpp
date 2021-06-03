#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 10 + 2, inf = 1e18;

string s[N];
int n, m, dp[N][1 << N];

void solve();

bool go(int id, int mask){
    if(id >= m)
        return true;

    int &ret = dp[id][mask];
    if(~ret)
        return ret;

    bool ans = false;


    for(char ch = 'a'; ch <= 'z'; ch++){
        int nm = mask;
        bool ok = true;
        for(int i = 0; i < n; i++)
            if(nm >> i & 1LL){
                if(s[i][id] != ch)
                    ok = false;
                else
                    nm |= 1LL << i;
            }else{
                if(s[i][id] != ch)
                    nm |= 1LL << i;
            }
        if(!ok) continue;
        ans |= go(id + 1, nm);
    }
    return ret = ans;
}

void print(int id, int mask){
    if(id >= m)
        return ;

    bool ans = false;

    for(char ch = 'a'; ch <= 'z'; ch++){
        int nm = mask;
        bool ok = true;
        for(int i = 0; i < n; i++)
            if(nm >> i & 1LL){
                if(s[i][id] != ch)
                    ok = false;
                else
                    nm |= 1LL << i;
            }else{
                if(s[i][id] != ch)
                    nm |= 1LL << i;
            }
        if(!ok) continue;
        ans |= go(id + 1, nm);
        if(ans){
            cout << ch;
            return print(id + 1, nm);
        }
    }
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

    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];

    bool poss = false;

    for(char ch = 'a'; ch <= 'z'; ch++){
        int mask = 0;
        for(int i = 0; i < n; i++)
            if(s[i][0] != ch)
                mask |= 1LL << i;
        poss |= go(1, mask);
    }

    if(!poss){
        cout << -1 << '\n';
        return;
    }

    print(0, 0);
    cout << '\n';
}