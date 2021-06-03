#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; (L <= R? i <= R : i >= R); (L <= R? i += 1 : i -= 1))
#define int long long

const int N = 200 + 5, inf = 1e18;

int R, G, B;
int a[3][N];
int dp[N][N][N];

int go(int i, int j, int k) {
    
    int &ans = dp[i][j][k];
    if(~ans)
        return ans;
    ans = 0;
    for(int one = 0; one < 3; one++) {
        for(int two = 0; two < 3; two++) if(one != two) {
            if(one == 0 && i > R) continue;
            if(one == 1 && j > G) continue;
            if(one == 2 && k > B) continue;
            if(two == 0 && i > R) continue;
            if(two == 1 && j > G) continue;
            if(two == 2 && k > B) continue;
            if(one == 0 && two == 1) {
                int get = a[one][i] * a[two][j] + go(i + 1, j + 1, k);
                ans = max(ans, get);
            }else if(one == 0 && two == 2) {
                int get = a[one][i] * a[two][k] + go(i + 1, j, k + 1);
                ans = max(ans, get);
            }else if(one == 1 && two == 2) {
                int get = a[one][j] * a[two][k] + go(i, j + 1, k + 1);
                ans = max(ans, get);
            }
        }
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> G >> B;
    FOR(i,1,R) {
        cin >> a[0][i];
    }
    FOR(i,1,G) {
        cin >> a[1][i];
    }
    FOR(i,1,B) {
        cin >> a[2][i];
    }
    sort(a[0] + 1, a[0] + R + 1, greater<int>());
    sort(a[1] + 1, a[1] + G + 1, greater<int>());
    sort(a[2] + 1, a[2] + B + 1, greater<int>());

    memset(dp, -1, sizeof(dp));
    cout << go(1, 1, 1);
}
