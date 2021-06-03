#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 1e6 + 2, inf = 1e9;

vector<int> a(10);
int dp[N];

int go(int rem){
    if(rem <= 0){
        return (rem == 0 ? 0 : -inf);
    }

    int &ans = dp[rem]; 
    if(~ans)
        return ans;
    ans = 0;

    FOR(i,1,9){
        int get = 1 + go(rem - a[i]);
        ans = max(ans, get);
    }
    return ans;
}

void trace(int rem){
    if(rem <= 0)
        return;

    int real_ans = go(rem);

    for(int i = 9; i >= 1; i--){
        int get = 1 + go(rem - a[i]);
        if(real_ans == get){
            cout << i;
            return trace(rem - a[i]);
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

    int v;
    cin >> v;
    FOR(i,1,9){
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    int mxDigs = go(v);
    if(mxDigs == 0){
        cout << -1;
    }
    else{
        trace(v);
    }
}
