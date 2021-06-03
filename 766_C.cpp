#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 1e9 + 7;

int n, a[26], pref[26][1005];
int dpWays[1005];
int dpDivs[1005];
string s;
int maxLen;

int getLen(int L, int R){
    return (R - L + 1);
}

int getCount(int L, int R, int ch){
    return (pref[ch][R] - pref[ch][L-1]);
}

int WAYS(int id){
    if(id == n + 1)
        return 1;
    int &ans = dpWays[id];
    if(~ans)
        return ans;
    ans = 0;
    FOR(jump,id,n){
        bool good = true;
        FOR(ch,0,25) if(getCount(id, jump, ch)){
            good &= getLen(id,jump) <= a[ch];
        }
        if(good){
            ans = (ans + WAYS(jump + 1)) % mod;
            if(WAYS(jump + 1)){
                maxLen = max(maxLen, getLen(id, jump));
            }
        }
    }
    return ans; 
}

int MINDIVS(int id){
    if(id == n + 1)
        return 0;
    int &ans = dpDivs[id];
    if(~ans)
        return ans;
    ans = inf;
    FOR(jump,id,n){
        bool good = true;
        FOR(ch,0,25) if(getCount(id, jump, ch)){
            good &= getLen(id,jump) <= a[ch];
        }
        if(good){
            ans = min(ans, 1 + MINDIVS(jump + 1));
        }
    }
    return ans; 
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    cin >> n >> s;
    s = " " + s;
    FOR(i,1,n) {
        pref[s[i] - 'a'][i]++;
        FOR(j,0,25) {
            pref[j][i] += pref[j][i - 1];
        }
    }
    FOR(i,0,25) {
        cin >> a[i];
    }
    int ways = 0;
    int minDivs = inf;

    memset(dpWays, -1, sizeof(dpWays));
    FOR(jump,1,n){
        bool good = true;
        FOR(ch,0,25) if(getCount(1,jump,ch)) {
            good &= getLen(1,jump) <= a[ch];
        }
        if(good){
            ways = (ways + WAYS(jump + 1)) % mod;
            if(WAYS(jump + 1)){
                maxLen = max(maxLen, getLen(1,jump));
            }
        }
    }
    cout << ways << '\n';
    cout << maxLen << '\n';

    memset(dpDivs, -1, sizeof(dpDivs));
    FOR(jump,1,n){
        bool good = true;
        FOR(ch,0,25) if(getCount(1,jump,ch)) {
            good &= getLen(1,jump) <= a[ch];
        }
        if(good){
            int get = 1 + MINDIVS(jump + 1);
            minDivs = min(minDivs, get);
        }
    }
    cout << minDivs << '\n';
}
