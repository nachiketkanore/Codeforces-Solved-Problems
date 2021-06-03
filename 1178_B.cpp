#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e6 + 2, inf = 1e18;

string s;
int n, pref[N], suff[N], ans;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> s;
    n = sz(s);  s = " " + s;

    FOR(i,2,n) if(s[i] == 'v' && s[i - 1] == 'v'){
        pref[i] = 1;
    }
    FOR(i,1,n-1) if(s[i] == 'v' && s[i + 1] == 'v'){
        suff[i] = 1;
    }
    FOR(i,1,n)
        pref[i] += pref[i - 1];
    for(int i = n; i >= 1; i--)
        suff[i] += suff[i + 1];
    
    FOR(i,1,n) if(s[i] == 'o'){
        int left = pref[i - 1], right = suff[i + 1];
        ans += left * right;
    }
    cout << ans;
}
