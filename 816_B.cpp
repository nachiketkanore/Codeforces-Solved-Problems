#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;

int pref[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, k, q;
    cin >> n >> k >> q;
    while(n--){
        int l, r;
        cin >> l >> r;
        pref[l]++, pref[++r]--;
    }
    for(int i = 1; i < N; i++){
        pref[i] += pref[i - 1];
    }
    for(int i = 1; i < N; i++){
        pref[i] = pref[i] >= k;
        pref[i] += pref[i - 1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }

}