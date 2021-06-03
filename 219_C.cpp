#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)

const int N = 5e5 + 2, inf = 1e9;

int n, k;
std::vector<int> a;
int dp[N][28];
std::vector<int> pre[26];

int go(int id, int prev) {
    if(id == n)
        return 0;

    int &ans = dp[id][prev];
    if(~ans)
        return ans;
    ans = inf;

    for(int val : pre[a[id]]) if(val != prev) {
        int cost = (val != a[id]) + go(id + 1, val);
        ans = min(ans, cost);
    }

    return ans;
}

void trace(int id, int prev) {
    if(id == n)
        return ;

    int ans = go(id, prev);

    for(int val : pre[a[id]]) if(val != prev) {
        int cost = (a[id] != val) + go(id + 1, val);
        if(cost == ans) {
            cout << (char)(val + 'A');
            return trace(id + 1, val);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    string s;
    cin >> s;
    for(char ch : s)
        a.push_back((int)(ch - 'A'));

    for(int i = 0; i < k; i++) {
        for(int j = i - 3; j < i + 3; j++) {
            int val = (j + 100 * k) % k;
            pre[i].push_back(val);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0,27) << '\n';
    trace(0,27);
    cout << '\n';
}
