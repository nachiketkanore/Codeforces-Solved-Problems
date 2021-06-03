#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 2e5 + 5, inf = 1e18, mod = 1e9 + 7;

int val[N + 2];
int n;

void solve();

set<array<int,3>> chk;

void go(int l, int r){
    if(l > r)
        return;
    chk.insert({r - l + 1, l, r});

    int mid = (l + r)/2;
    int left = mid - l, right = r - mid;
    if(left >= right){
        go(l, mid - 1);
        go(mid + 1, r);
    }else{
        go(mid + 1, r);
        go(l, mid - 1);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t = 1;
    cin >> t;
    while(t--)
        solve();
}

void solve(){
    cin >> n;

    go(1, n);

    map< int, vector<pair<int,int>>> f;
    for(auto &it : chk){
        f[it[0]].push_back({it[1], it[2]});
    }
    std::vector<pair<int,int>> ans;
    for(auto &it : f){
        sort(it.second.rbegin(), it.second.rend());
        for(auto &x : it.second){
            ans.push_back({x.first, x.second});
        }
    }

    reverse(ans.begin(), ans.end());

    int keep = 1;
    for(auto &x : ans){
        int id = (x.first + x.second)/2;
        val[id] = keep++;
    }

    for(int i = 1; i <= n; i++)
        cout << val[i] << " ", val[i] = 0;
    cout << '\n';
    chk.clear();
}