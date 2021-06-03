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

    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> even, odd;
        FOR(i,1,2*n){
            int u;
            cin >> u;
            if(u & 1) odd.push_back(i);
            else      even.push_back(i);
        }
        vector<pair<int,int>> ans;
        while(sz(ans) < n-1){
            if(sz(even) >= 2){
                ans.push_back({even[sz(even) - 1], even[sz(even) - 2]});
                even.pop_back();
                even.pop_back();
            }
            else if(sz(odd) >= 2){
                ans.push_back({odd[sz(odd) - 1], odd[sz(odd) - 2]});
                odd.pop_back();
                odd.pop_back();
            }
        }
        for(auto &it : ans){
            cout << it.first << ' ' << it.second << '\n';
        }   
    }
}
