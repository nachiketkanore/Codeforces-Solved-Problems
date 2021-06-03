#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

string s;
int f[26];
string L, R;
std::vector<int> odd;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> s;
    for(char ch : s)
        f[ch - 'a']++;
    FOR(i,0,25) if(f[i]&1){
        odd.push_back(i);
        f[i]--;
    }
    int l = 0, r = sz(odd)-1;
    while(l < r){
        odd[r--] = odd[l++];
    }
    for(int id : odd)
        f[id]++;
    int oddcnt = 0;
    FOR(i,0,25) oddcnt += f[i]&1;
    assert(oddcnt <= 1);

    char what = '+';

    FOR(i,0,25){
        while(f[i] >= 2){
            L.push_back((char)('a' + i));
            R.push_back((char)('a' + i));
            f[i] -= 2;
        }
        if(f[i] == 1)
            what = (char)('a' + i);
    }

    reverse(R.begin(), R.end());
    if(what != '+')
        L.push_back(what);
    cout << L << R;

}
