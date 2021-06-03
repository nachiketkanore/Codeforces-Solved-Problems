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

    int n;
    cin >> n;
    n += 2;
    vector<pair<int,int>> ans;
    FOR(i,1,n){
        FOR(j,i-1,i+1){
            if(j >= 1 && j <= n){
                ans.push_back({i,j});
            }
        }
    }
    cout << sz(ans) << '\n';
    for(auto &it: ans)
        cout << it.first << ' ' << it.second << '\n';
}
