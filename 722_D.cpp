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
    set<int> f;
    FOR(i,1,n){
        int u;  cin >> u;
        f.insert(u);
    }
    while(1){
        int large = *f.rbegin();
        int val = large >> 1;
        bool stop = true;
        while(val > 0 && f.count(val) > 0){
            val >>= 1;
        }
        if(val > 0){
            f.erase(large);
            f.insert(val);
            stop = false;
        }
        if(stop) 
            break;
    }
    for(int x : f)
        cout << x << ' ';
}
