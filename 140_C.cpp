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

    int n;
    cin >> n;
    set<pair<int,int>> cnt;
    map<int,int> f;
    for(int i = 0, u; i < n; i++){
        cin >> u;
        f[u]++;
    }
    for(auto it : f) {
        cnt.insert({it.second, it.first});
    }

    int ans = 0;
    vector<array<int,3>> ret;

    while(sz(cnt) >= 3){
        pair<int,int> three = *cnt.rbegin();
        cnt.erase(cnt.find(three));
        pair<int,int> two = *cnt.rbegin();
        cnt.erase(cnt.find(two));
        pair<int,int> one = *cnt.rbegin();
        cnt.erase(cnt.find(one));
        assert(one.first >= 1 && one.first <= two.first && two.first <= three.first);
        one.first--, two.first--, three.first--;
        ret.push_back({one.second, two.second, three.second});
        if(one.first > 0)
            cnt.insert(one);
        if(two.first > 0)
            cnt.insert(two);
        if(three.first > 0)
           cnt.insert(three);
    }

    cout << sz(ret) << '\n';
    for(auto it : ret){
        std::vector<int> get = {
            it[0], it[1], it[2]
        };
        sort(get.rbegin(), get.rend());
        for(int x : get)
            cout << x << ' ';
        cout << '\n';
    }
}
