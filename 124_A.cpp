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

    int n,a,b;
    int ans = 0;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        int back = n - i;
        int front = i - 1;
        if(front >= a and back <= b)
            ans++;
    }
    cout << ans;
}