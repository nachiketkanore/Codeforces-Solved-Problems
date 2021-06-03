#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e12;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    x -= n - 1;
    y -= n - 1;

    for(int last = 1; last * last <= inf; last++) {
        int last_square = last * last;
        if(last <= y && last_square >= x) {
            FOR(i,1,n-1) cout << 1 << '\n';
            cout << last << '\n';
            return 0;
        }
    }
    cout << -1;
}
/*
squared sum >= x
sum <= y

(a1 + a2 + .. + an)^2 = (a1^2 + a2^2 + ... + an^2) + 2 * (a1s2 + a1a3 + a1a4 + ...)

sum <= 1e6
so iterate on it
how to find squared sum from that?

a1^2 = a1 when a1 = 1
make all 1s except last
(n - 1) * 1 + last^2 >= x 
(n - 1) * 1 + last <= y
last^2 >= x - (n - 1)
last <= y - (n - 1)
*/