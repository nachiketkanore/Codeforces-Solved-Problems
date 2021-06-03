#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)

int ans = -1, n, m;
vector<vector<int>> ret, mat;

bool one(int i, int j, int next) {
    if (i + 2 >= n || j + 2 >= m)
        return false;

    if (!mat[i][j] && !mat[i][j + 1] && !mat[i][j + 2] && !mat[i + 1][j + 1] && !mat[i + 2][j + 1]) {
        mat[i][j] = mat[i][j + 1] = mat[i][j + 2] = mat[i + 1][j + 1] = mat[i + 2][j + 1] = next;
        return true;
    }
    return false;
}

void restore_one(int i, int j) {
    assert(i + 2 < n && j + 2 < m);
    mat[i][j] = mat[i][j + 1] = mat[i][j + 2] = mat[i + 1][j + 1] = mat[i + 2][j + 1] = 0;
}

bool two (int i, int j, int next) {
    if (i + 2 >= n || j + 2 >= m)
        return false;

    if (!mat[i + 1][j] && !mat[i + 1][j + 1] && !mat[i + 1][j + 2] && !mat[i][j + 2] && !mat[i + 2][j + 2]) {
        mat[i + 1][j] = mat[i + 1][j + 1] = mat[i + 1][j + 2] = mat[i][j + 2] = mat[i + 2][j + 2] = next;
        return true;
    }
    return false;
}

void restore_two(int i, int j) {
    assert(i + 2 < n && j + 2 < m);
    mat[i + 1][j] = mat[i + 1][j + 1] = mat[i + 1][j + 2] = mat[i][j + 2] = mat[i + 2][j + 2] = 0;
}

bool three(int i, int j, int next) {
    if (i + 2 >= n || j + 2 >= m)
    return false;

    if (!mat[i][j + 1] && !mat[i + 1][j + 1] && !mat[i + 2][j + 1] && !mat[i + 2][j] && !mat[i + 2][j + 2]) {
        mat[i][j + 1] = mat[i + 1][j + 1] = mat[i + 2][j + 1] = mat[i + 2][j] = mat[i + 2][j + 2] = next;
        return true;
    }
    return false;
}

void restore_three(int i, int j) {
    assert(i + 2 < n && j + 2 < m);
    mat[i][j + 1] = mat[i + 1][j + 1] = mat[i + 2][j + 1] = mat[i + 2][j] = mat[i + 2][j + 2] = 0;
}

bool four(int i, int j, int next) {
    if (i + 2 >= n || j + 2 >= m)
    return false;

    if (!mat[i][j] && !mat[i + 1][j] && !mat[i + 1][j + 1] && !mat[i + 1][j + 2] && !mat[i + 2][j]) {
        mat[i][j] = mat[i + 1][j] = mat[i + 1][j + 1] = mat[i + 1][j + 2] = mat[i + 2][j] = next;
        return true;
    }
    return false;
}

void restore_four(int i, int j) {
    assert(i + 2 < n && j + 2 < m);
    mat[i][j] = mat[i + 1][j] = mat[i + 1][j + 1] = mat[i + 1][j + 2] = mat[i + 2][j] = 0;
}

void update_answer(std::vector<std::vector<int>> &mat) {
    int mx = 0;
    FOR(i,0,n-1) FOR(j,0,m-1) mx = max(mx, mat[i][j]);
    if (ans < mx) {
        ans = mx;
        ret = mat;
    }
}

int max_upto_here[12][12];

void go(int row, int col, int curr_ans) {

    if (row + 2 >= n) {
        if (curr_ans > ans) {
            ans = curr_ans;
            ret = mat;
        }
        return;
    }

    if (col + 2 >= m) {
        go(row + 1, 0, curr_ans);
        return;
    }

    if (max_upto_here[row][col] - 1 > curr_ans) 
        return;

    max_upto_here[row][col] = max(max_upto_here[row][col], curr_ans);

    go(row, col + 1, curr_ans);

    if (one(row, col, curr_ans)) {
        go(row, col + 1, curr_ans + 1);
        restore_one(row, col);
    }
    if (two(row, col, curr_ans)) {
        go(row, col + 1, curr_ans + 1);
        restore_two(row, col);
    }
    if (three(row, col, curr_ans)) {
        go(row, col + 1, curr_ans + 1);
        restore_three(row, col);
    }
    if (four(row, col, curr_ans)) {
        go(row, col + 1, curr_ans + 1);
        restore_four(row, col);
    }
    

}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    mat = vector<vector<int>> (n, vector<int> (m, 0));
    go(0,0,1);

    ans = max(ans, 0);
    cout << ans - 1 << '\n';
    FOR(i,0,n-1) {
        FOR(j,0,m-1) {
            char pr = (ret[i][j] == 0 ? '.' : (char)('A' + ret[i][j] - 1));
            cout << pr;
        }
        cout << '\n';
    }
}
