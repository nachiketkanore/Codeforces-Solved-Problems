/*Falling != Failing*/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 2e5 + 2, inf = 1e18, mod = 1e9 + 7; 

void solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int tt = 1;
    //cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    int n, s;
    cin >> n >> s;
    if(s - n + 1 <= 0){
        cout << "NO" << '\n';
        return;
    }
    int ans[n + 2] = {0};
    for(int i = 1; i < n; i++)
        ans[i] = 1;
    ans[n] = s - n + 1;
    set<int> poss;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += ans[i];
        poss.insert(sum);
    }
    sum = 0;
    for(int i = n; i >= 1; --i){
        sum += ans[i];
        poss.insert(sum);
    }
    for(int k = 0; k <= s; k++){
        if(poss.count(k) == 0 and poss.count(s - k) == 0){
            cout << "YES" << '\n';
            for(int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << '\n';
            cout << k << '\n';
            return;
        }
    }
    cout << "NO" << '\n';   
}
