#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 100 + 2, inf = 1e18;

char mat[4][N];
bool hasTrain[4][N][N];
int dp[4][N][N];
int n, k;

int go(int row, int col, int time) {
    if(row < 1 || row > 3 || hasTrain[row][col][time] == true)
        return 0;
    if(col == n)
        return 1;
    int &ans = dp[row][col][time];
    if(~ans)
        return ans;
    ans = 0;

    if(hasTrain[row][col + 1][time] == false){
        if(hasTrain[row - 1][col + 1][time] == false)
            ans |= go(row - 1, col + 1, time + 1);
        if(hasTrain[row + 1][col + 1][time] == false)
            ans |= go(row + 1, col + 1, time + 1);
        if(hasTrain[row][col + 1][time] == false)
            ans |= go(row, col + 1, time + 1);
    }
    
    return ans;
}

void solve();

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

    memset(hasTrain, false, sizeof(hasTrain));
    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    int startRow = 0;
    FOR(row,1,3) FOR(col,1,n) {
        cin >> mat[row][col];
        if(mat[row][col] == 's') {
            startRow = row;
        }
        if(mat[row][col] >= 'A' && mat[row][col] <= 'Z'){
            int time = 0, pos = col;
            while(pos >= 1){
                hasTrain[row][pos][time] = true;
                pos -= 2;
                ++time;
            }
        }
    }

    int ans = go(startRow, 1, 0);
    cout << (ans ? "YES" : "NO") << '\n';
}
