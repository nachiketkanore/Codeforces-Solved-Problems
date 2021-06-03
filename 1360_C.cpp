#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
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
    int a[n];
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        even += a[i] % 2 == 0;
        odd += a[i] % 2 == 1;
    }

    even %= 2;
    odd %= 2;
    bool ans = false;
    if(even == 0 && odd == 0)
        ans = true;
    else{
        bool found = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) if(i != j){
                if(abs(a[i] - a[j]) == 1)
                    found = 1;
            }
        if(found)
            ans = true;
    }

    cout << (ans ? "YES" : "NO") << '\n';
}