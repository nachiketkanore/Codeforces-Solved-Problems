#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

bool OK(string &s, int from, int to) {
    int len = to - from + 1;
    if(len < 3) return false;
    char want = 'o';
    while(from <= to) {
        if(s[from] != want) {
            return false;
        }
        if(want == 'o') want = 'g';
        else want = 'o';
        from++;
    }
    if(s[to] != 'o') return false;
    return true;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0; i < n; ) {
        bool ok = false;
        for(int j = n - 1; j >= i; j--) {
            if(OK(s,i,j)) {
                cout << "***";
                ok = true;
                i = j + 1;
                break;
            }
        }
        if(!ok) {
            cout << s[i];
            i++;
        }
    }
}
