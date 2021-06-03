#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 1000 + 2, inf = 1e18;

int n, m, mat[N][N], row_sum[N], col_sum[N];
int row[N], col[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    FOR(i,1,n) FOR(j,1,m) {
        char ch;
        cin >> ch;
        int val = ch == '*';
        mat[i][j] = val;
        row_sum[i] += val;
        col_sum[j] += val;
    }

    int ans = 0;

    FOR(i,1,n) {
        FOR(j,1,m) {
            row[i] += mat[i][j];
            col[j] += mat[i][j];
            if(!mat[i][j]) continue;
            int left = row[i];
            int right = row_sum[i] - left;
            int up = col[j];
            int down = col_sum[j] - up;
            left--, up--;
            ans += left * up + up * right + left * down + down * right;

        }
    }

    cout << ans;
}
