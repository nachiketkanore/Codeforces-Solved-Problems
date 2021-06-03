#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)

const int mod = 1e9 + 7;

int n, k, a[205], dp[205][205][1005];

long long go(int id, int open_groups, int total_imbalance) {
    if (total_imbalance > k)
        return 0;
    if (id == n + 1)
        return open_groups == 0;

    int &ret = dp[id][open_groups][total_imbalance];
    if (~ret)
        return ret;
    long long ans = 0;

    long long add = open_groups * (a[id] - a[id - 1]);

    if (open_groups > 0) {
        // We can close any 1 of the currently open groups
        long long c1 = 1LL * open_groups * go(id + 1, open_groups - 1, total_imbalance + add) % mod;
        ans = (ans + c1) % mod;
    }

    // Create one more group
    long long c2 = 1LL * go(id + 1, open_groups + 1, total_imbalance + add) % mod;
    ans = (ans + c2) % mod;

    // Add the current time to any one of the currently active groups
    long long c3 = open_groups * go(id + 1, open_groups, total_imbalance + add) % mod;
    ans = (ans + c3) % mod;

    // A group of single person
    long long c4 = 1LL * go(id + 1, open_groups, total_imbalance + add) % mod;
    ans = (ans + c4) % mod;
    ret = ans;
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> k;
    FOR(i,1,n) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof(dp));

    cout << go(1,0,0);
}

/*

Suppose A[i] is sorted

A[L], A[L + 1], A[L + 2], .... , A[R - 1], A[R]
Here, for this group,
max = A[R], min = A[L] (since array is sorted)

Observe, max - min = A[R] - A[L]
                   = (A[L + 1] - A[L]) + (A[L + 2] - A[L + 1]) + ... + (A[R] - A[R - 1])
                   = Sum of abs(adjacent differences)

Use this fact to store the total imbalance of all groups

*/