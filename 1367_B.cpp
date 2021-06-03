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

    int tt = 1;
    cin >> tt;
    while(tt--){
        int n;  cin >> n;
        int mod0val = 0, mod0ind = 0;
        int mod1val = 0, mod1ind = 0;

        int d = 0;

        FOR(i,1,n){
            int u;  cin >> u;
            mod0ind += (i - 1) % 2 == 0;
            mod1ind += (i - 1) % 2 == 1;
            mod1val += u % 2 == 1;
            mod0val += u % 2 == 0;
            d += ((i - 1)&1) ^ (u % 2);
        }
        if(mod0val != mod0ind or(mod1val != mod1ind)){
            cout << -1 << '\n';
            continue;
        }

        cout << d/2 << '\n';
    }
}
