#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, m;
int ans[10];
int cnt[N];
map<int,vector<pair<int,int>>> row, col, diag1, diag2;

void compute(map<int, vector<pair<int,int>>> &curr){
    for(auto &it : curr){
        auto &a = it.second;
        sort(a.begin(), a.end());
        for(int i = 1; i < sz(a); i++){
            int id = a[i].second;
            cnt[id]++;
        }
        for(int i = 0; i < sz(a) - 1; i++){
            int id= a[i].second;
            cnt[id]++; 
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n >> m;
    FOR(i,1,m) {
        int x, y;
        cin >> x >> y;
        row[x].push_back({y, i});
        col[y].push_back({x, i});
        diag1[x - y].push_back({x, i});
        diag2[x + y].push_back({x, i});
    }

    compute(row);
    compute(col);
    compute(diag1);
    compute(diag2);

    FOR(i,1,m) {
        ans[cnt[i]]++;
    }
    FOR(i,0,8){
        cout << ans[i] << ' ';
    }
}
