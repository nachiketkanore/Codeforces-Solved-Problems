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

    string s;
    cin >> s;
    int small = 0, large = 0;
    for(char ch : s)
        small += ch >= 'a' && ch <= 'z',
        large += ch >= 'A' && ch <= 'Z';

    int ans = min(small, large);
    int st = 0, lt = 0;

    for(char ch : s){
        st += ch >= 'a' && ch <= 'z',
        lt += ch >= 'A' && ch <= 'Z';
        int cost = st + (large - lt);
        ans = min(ans, cost);
    }
    cout << ans << '\n';
}
