#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5e5 + 3, mod = 1e9 + 7, inf = 1e18;

int n;
array<int,2> a[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i][1] >> a[i][0];
    }
    sort(a + 1, a + n + 1);
    int cc = 0;
    int rmax = 0;
    for(int i = 1; i <= n; i++){
        if(rmax < a[i][1]){
            ++cc;
            rmax = a[i][0];
        }
    }
    cout << cc;
}
