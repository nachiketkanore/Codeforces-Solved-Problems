#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

map<string, int> cnt;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;
    int n = sz(s);
    for(int i = 0; i < n; i++) {
        string curr;
        for(int j = i; j < n; j++) {
            curr.push_back(s[j]);
            cnt[curr]++;
        }
    }    
    int ans = 0;
    for(auto& it : cnt) if(it.second >= 2) {
        ans = max(ans, sz(it.first));
    }

    cout << ans << '\n';
}
