#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int n, ans;
int a[N], b[N], pos1[N], pos2[N], f1[N], f2[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    FOR(i,0,n-1) cin >> a[i], pos1[a[i]] = i;
    FOR(i,0,n-1) cin >> b[i], pos2[b[i]] = i, ans += a[i] == b[i];
    FOR(i,1,n){
        int diff1 = (pos1[i] - pos2[i] + n + n) % n;
        int diff2 = (pos2[i] - pos1[i] + n + n) % n;

        f1[diff1]++;
        f2[diff2]++;
    }
    FOR(shift,0,n-1){
        int get = max(f1[shift], f2[shift]);
        ans = max(ans, get);
    }
    cout << ans;
}
