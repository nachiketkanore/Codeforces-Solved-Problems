#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int SOD(int n){
    if(n == 0)
        return 0;
    return n%10 + SOD(n/10);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, s;
    cin >> n >> s;
    int ans = -1;
    int lo = 1, hi = n;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        bool chk = mid - SOD(mid) >= s;
        if(chk){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    if(~ans)
        cout << (n - ans + 1);
    else 
        cout << 0;
}
