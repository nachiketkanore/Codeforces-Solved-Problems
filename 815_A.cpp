#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 102 + 2, inf = 1e18;

int n, m, mat[N][N], each_col[N], each_row[N];
int fin = inf;
vector<int> row_answers(N);
vector<int> col_answers(N);

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    FOR(i,1,n) FOR(j,1,m) cin >> mat[i][j];
    int min1 = inf;
    FOR(j,1,m) min1 = min(min1, mat[1][j]);
    FOR(row1,0,min1) {
        FOR(j,1,m) {
            each_col[j] = mat[1][j] - row1;
            assert(each_col[j] >= 0);
        }
        each_row[1] = row1;
        bool poss = true;
        FOR(i,2,n) {
            if(!poss) break;
            set<int> row_inc;
            FOR(j,1,m) {
                int val = mat[i][j] - each_col[j];
                row_inc.insert(val);
                if(val < 0 || sz(row_inc) > 1) {
                    poss = false;
                    break;
                }
            }
            if(!poss) break;
            assert(sz(row_inc) == 1);
            each_row[i] = *row_inc.begin();
        }
        if(!poss) continue;
        int ans = 0;
        FOR(i,1,n) ans += each_row[i];
        FOR(j,1,m) ans += each_col[j];

        if(ans < fin) {
            fin = ans;
            FOR(i,1,n) row_answers[i] = each_row[i];
            FOR(j,1,m) col_answers[j] = each_col[j];
        }
    }
    if(fin == inf) {
        cout << -1;
    }else {
        cout << fin << '\n';
        FOR(i,1,n) {
            while(row_answers[i]-->0) {
                cout << "row " << i << '\n';
            }
        }
        FOR(j,1,m) {
            while(col_answers[j]-->0) {
                cout << "col " << j << '\n';
            }
        }
    }
}
