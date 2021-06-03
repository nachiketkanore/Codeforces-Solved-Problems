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

    int n;  cin >> n;
    string a[n];
    FOR(i,0,n-1) cin >> a[i];
    sort(a, a + n, [&](string &a, string &b){
        return a+b < b+a;
    });
    FOR(i,0,n-1)
        cout << a[i];
}
