#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
#define fk return cout << "NO\n", 0
using namespace std;

const int N = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;

bool solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();
}

bool solve(){
    int n, k;
    cin >> n >> k;
    if(k > n)   fk;
    if(k % 2 == 0 && n % 2 != 0)    fk;
    std::vector<int> ans;
    bool which = k % 2 == 0 || n % 2 == 1;
    int sum = 0;
    for(int i = 0; i < k - 1; i++)
        ans.push_back(which ? 1 : 2),
        sum += ans.back();
    if(n <= sum)    fk;
    ans.push_back(n - sum);
    cout << "YES" << '\n';
    for(int x : ans)
        cout << x << ' ';
    cout <<  '\n';
    return 1;
}