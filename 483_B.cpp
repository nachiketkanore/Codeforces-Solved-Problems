#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int w1, w2, A, B;

int canGive(int n){
    if(n < w1 + w2)
        return 0;
    int byA = n/A, byB = n/B, byAB = n/(A*B);
    int toA = n - byA;
    int toB = n - byB;
    int bothCanTake = n - byAB;

    return (toA >= w1 && toB >= w2 && (bothCanTake >= (w1 + w2)));
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> w1 >> w2 >> A >> B;

    int lo = 1, hi = inf;
    int ans = inf;

    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(canGive(mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    cout << ans << '\n';
}