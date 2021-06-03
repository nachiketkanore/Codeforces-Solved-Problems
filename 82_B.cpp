#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 1e5 + 2, inf = 1e9;

std::vector<int> valData[201];
map<std::vector<int>, std::vector<int> > groups;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin >> n;
    int t = n * (n - 1) / 2;
    FOR(i,1,t) {
        int x;  cin >> x;
        FOR(j,1,x) {
            int val;   cin >> val;
            valData[val].push_back(i);
        }
    }
    FOR(val,1,200) if(sz(valData[val])) {
        std::vector<int> &curr = valData[val];
        sort(curr.begin(), curr.end());
        groups[curr].push_back(val);
    }

    if(n == 2) {
        assert(sz(groups) == 1);
        for(auto &it : groups) {
            std::vector<int> &all = it.second;
            assert(sz(all) >= 2);

            cout << 1 << ' ' << all[0] << '\n';
            cout << sz(all) - 1 << ' ';
            for(int i = 1; i < sz(all); i++)
                cout << all[i] << ' ';


            break;
        }

        return 0;
    }

    for(auto &it : groups) {
        cout << sz(it.second) << ' ';
        for(int &x : it.second)
            cout << x << ' ';
        cout << '\n';
    }

}
