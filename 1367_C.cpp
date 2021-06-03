#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int tt = 1;
    cin >> tt;
    while(tt--){
        int n, k;
        cin >> n >> k;
        vector<int> id;
        string s;   cin >> s; s = " " + s;
        id.push_back(-inf);
        FOR(i,1,n) if(s[i] == '1') id.push_back(i);
        id.push_back(inf);

        int ans = 0;

        FOR(i,1,sz(id)-1){
            int prev = id[i - 1], next = id[i];

            int from = (prev == -inf ? 1 : prev + 1);
            int to = (next == inf ? n : next - 1);

            FOR(curr, from, to){
                if(curr - prev > k && (next - curr > k)){
                    ans++;
                    prev = curr;
                }
            }
        }

        cout << ans << '\n';
    }
}
