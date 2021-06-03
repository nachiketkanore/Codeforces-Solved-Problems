#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 5000 + 5, mod = 1e9 + 7;

int n, cnta[N], cntb[N], ans;
string s;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> s;
    n = sz(s);
    s = "#" + s;
    for(int i = 1; i <= n; i++){
        cnta[i] = s[i] == 'a';
        cntb[i] = s[i] == 'b';
        cnta[i] += cnta[i - 1];
        cntb[i] += cntb[i - 1];
    }
    ans = max(cnta[n], cntb[n]);

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++){
            int bs = cntb[j] - cntb[i - 1];
            int as = cnta[i - 1] + (cnta[n] - cnta[j]);
            ans = max(ans, as + bs);
        }
    cout << ans;
}
