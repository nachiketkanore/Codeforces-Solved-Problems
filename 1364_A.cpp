#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;



int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int id = -1, u;
        int ans = -1;
        int sum = 0;
        FOR(i,0,n-1){
            cin >> u;
            sum += u;
            if(sum % x != 0)
                ans = max(ans, i + 1);
            else{
                if(~id)
                    ans = max(ans, i - id);
            }
            if(id == -1 && (sum % x != 0))
                id = i;
        }
        cout << ans << '\n';
    }
}
