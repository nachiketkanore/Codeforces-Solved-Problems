#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

void solve();

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
        solve();
    }
}

void solve(){
    int n;
    cin >> n;
    int three = 0;
    int cnt = 0;
    while(1){
        int val = cnt * (cnt - 1)/2;
        if(val <= n){
            three = cnt;
        }else {
            break;
        }
        ++cnt;
    }
    int remaining = n - (three * (three - 1)/2);
                       cout << "133";
    FOR(i,1,remaining) cout << "7";
    FOR(i,1,three-2)     cout << "3";
                       cout << "7";
                       cout << '\n';
}
