#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1000 + 2, inf = 1e18;

int mat[6][N];
int before[N][N];
std::vector<int> g[N];
int dp[N];
int n, k;

int go(int node){
    int &ans = dp[node];
    if(~ans)
        return ans;
    ans = 1;
    for(int v : g[node]){
        int nextPathLength = go(v);
        ans = max(ans, 1 + nextPathLength);
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

    cin >> n >> k;
    FOR(i,1,k){
        FOR(j,1,n){
            cin >> mat[i][j];
        }
    }
    FOR(I,1,k) FOR(i,1,n) FOR(j,i+1,n){
        ++before[mat[I][i]][mat[I][j]];
    }
    FOR(i,1,n) FOR(j,1,n) if(before[i][j] == k){
        g[i].push_back(j);
    }
    memset(dp, -1, sizeof(dp));
    int mxPathLength = 0;
    FOR(i,1,n){
        mxPathLength = max(mxPathLength, go(i));
    }
    cout << mxPathLength;
}
