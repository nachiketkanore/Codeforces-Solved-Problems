#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 300 + 2, inf = 1e15;

int n, l[N], c[N];
map<int,int> dp[N];

//Min cost of selecting a subsequence with GCD = 1
int go(int id, int currGCD){
    if(currGCD == 1)
        return 0;
    if(id > n)
        return inf;
    if(dp[id].find(currGCD) != dp[id].end())
        return dp[id][currGCD];
    int c1 = go(id + 1, currGCD);
    int c2 = go(id + 1, __gcd(currGCD, l[id])) + c[id];
    return dp[id][currGCD] = min(c1, c2);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    int G = 0;
    for(int i = 1; i <= n; i++){
        cin >> l[i];
        G = __gcd(G, l[i]);
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    if(G != 1){
        cout << -1 << '\n';
        return 0;
    }
    int ans = go(1, 0);
    cout << ans << '\n';
}
