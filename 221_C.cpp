#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
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
    int a[n], b[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        cnt += a[i] != b[i];
    cout << (cnt == 0 || cnt == 2 ? "YES" : "NO") << '\n';
}
