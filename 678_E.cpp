#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 18, inf = 1e18;

int n;
double prob[N][N], dp[N][1 << (N + 1)];
bool vis[N][1 << (N + 1)];

double go(int winner, int done){
    if(__builtin_popcountll(done) == n){
        if(winner == 0)
            return 1.0;
        return 0;
    }else{
        if(done & 1)
            return 0;
    }

    if(vis[winner][done])
        return dp[winner][done];
    vis[winner][done] = true;

    double &ans = dp[winner][done];

    for(int i = 0; i < n; i++) if((done >> i & 1) == 0){
        double c1 = prob[winner][i] * go(winner, done | (1 << i));
        double c2 = prob[i][winner] * go(i, done | (1 << i));
        ans = max(ans, c1 + c2);
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
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> prob[i][j];
    double ans = 0.0;

    for(int start = 0; start < n; ++start){
        double tans = go(start, 1 << start);
        ans = max(ans, tans);
    }

    cout << fixed << setprecision(12) << ans << '\n';
}
