#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, k;
int freq[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n >> k;
    FOR(i,1,n){
        int u;  cin >> u;
        freq[u]++;
    }
    int ans = 0;
    FOR(i,0,10000) FOR(j,0,10000){
        if(__builtin_popcountll(i ^ j) == k){
            ans += freq[i] * freq[j];
        }
    }
    if(k == 0){
        ans -= n;
    }
    ans >>= 1;
    cout << (ans) << '\n';
}
