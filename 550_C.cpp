#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

string s;
int n;
int dp[102][8][2];

bool go(int id, int sum, bool taken){
    if(id >= n)
        return sum == 0 && taken;

    int &ans = dp[id][sum][taken];
    if(~ans)
        return ans;

    bool c1 = go(id + 1, sum, taken);
    bool c2 = go(id + 1, (sum * 10 + (s[id] - '0')) % 8, 1);
    return ans = (c1 || c2);
}

void trace(int id, int sum, bool taken){
    if(id >= n)
        return ;

    bool c1 = go(id + 1, sum, taken);
    if(c1)
        return trace(id + 1, sum, taken);

    bool c2 = go(id + 1, (sum * 10 + (s[id] - '0')) % 8, 1);
    if(c2){
        cout << s[id];
        return trace(id + 1, (sum * 10 + (s[id] - '0')) % 8, 1);
    }
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
    bool zero = 0;
    for(char ch : s) zero |= ch == '0';
    if(zero){
        cout << "YES\n0";    
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    bool yes = go(0,0,0);
    if(yes){
        cout << "YES\n";
        trace(0,0,0);
    }else{
        cout << "NO";
    }

}
