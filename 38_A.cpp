#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;


int32_t main(){
   int n;
   cin >> n;
   int ar[n + 2] = {0};
   for(int i = 1; i <= n - 1; i++)
        cin >> ar[i];
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a; i <= b-1; i++)
        ans += ar[i];
    cout << ans;
}