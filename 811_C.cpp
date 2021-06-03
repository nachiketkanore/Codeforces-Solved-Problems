#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
using LL = long long;

const int N = 5000 + 2;
const long long inf = 1e9;

int n, a[N], first[N], last[N], canTake[N][N];
bool dist[N];
int subarrayXOR[N][N];
LL dp[N];

LL go(int from) {
    if(from == n + 1)
        return 0;
    
    LL &ans = dp[from];
    if(~ans)
        return ans;

    ans = go(from + 1);
    FOR(to,from,n) if(canTake[from][to]) {
        LL get = subarrayXOR[from][to] + go(to + 1);
        LL get2 = go(to + 1);
        ans = max(ans, max(get, get2));
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

    fill(first, first + N, inf);

    cin >> n;
    FOR(i,1,n) {
        cin >> a[i];
        first[a[i]] = min(first[a[i]], i);
        last[a[i]] = max(last[a[i]], i);
    }
    FOR(num,0,5000) if(last[num] != 0) {
        int L = first[num], R = last[num];
        bool good = true;
        FOR(i,L,R) {
            int val = a[i];
            good &= (first[val] >= L && last[val] <= R);
        }
        canTake[L][R] = good;
    }
    FOR(i,1,n) {
        FOR(k,0,5000) dist[k] = false;
        LL ans = 0;
        FOR(j,i,n) {
            int val = a[j];
            if(dist[val] == false){
                ans ^= val;
                dist[val] = true;
            }
            subarrayXOR[i][j] = ans;
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << max((LL)subarrayXOR[1][n],go(1)) << '\n';

}
