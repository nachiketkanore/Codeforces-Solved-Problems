#include <bits/stdc++.h>
//#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 8000, mod = 1e9 + 7;

int a[N];
bool b[N + 2];

void solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    int t;
    cin >> t;
    while(t--)
        solve();
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum = a[i];
        for(int j = i+1; j < n; j++){
            sum += a[j];
            if(sum <= n)
                b[sum] = 1;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += b[a[i]] > 0;
    cout << ans << '\n';

    sum = 0;
    for(int i = 0; i < n; i++){
        sum = a[i];
        for(int j = i+1; j < n; j++){
            sum += a[j];
            if(sum <= n)
                b[sum] = 0;
        }
    }
}