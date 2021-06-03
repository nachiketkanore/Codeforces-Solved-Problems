#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n;
bool mat[51][51];
int dp[51][51][51][51];

int go(int x1, int y1, int x2, int y2) {
    int &ans = dp[x1][y1][x2][y2];
    if(~ans)
        return ans;
    if(x1 == x2 && y1 == y2) {
        return ans = mat[x1][y1];
    }

    int len = x2 - x1 + 1, bed = y2 - y1 + 1;
    ans = max(len, bed);
    //Either take this big rectangle or break it into smaller rectangles to find better answers
    for(int x = x1; x < x2; x++) {
        int get = go(x1, y1, x, y2) + go(x + 1, y1, x2, y2);
        ans = min(ans, get);
    }

    for(int y = y1; y < y2; y++) {
        int get = go(x1, y1, x2, y) + go(x1, y + 1, x2, y2);
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

    cin >> n;
    FOR(i,1,n) {
        FOR(j,1,n) {
            char ch;    cin >> ch;
            mat[i][j] = (ch == '#' ? 1 : 0);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << go(1,1,n,n) << '\n';
}
