#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, m;
string s[102];
bool done[102];

bool pal(string &t){
    bool pal = true;
    int lo = 0, hi = sz(t) - 1;
    while(lo < hi)
        pal &= (t[lo++] == t[hi--]);
    return pal;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n >> m;
    std::vector<pair<string,string>> a;

    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) if(!done[i] && !done[j]){
            string t  = s[i] + s[j];
            
            if(pal(t)){
                done[i] = done[j] = true;
                a.push_back({s[i], s[j]});
            }
        }

    string ans;
    for(int i = 0; i < n; i++) if(!done[i]){
        if(pal(s[i])){
            if(sz(ans) < sz(s[i])){
                ans = s[i];
            }
        }
    }

    int len = sz(ans);
    for(auto x : a)
        len += sz(x.first) + sz(x.second);
    cout << len << '\n';
    for(auto x : a)
        cout << x.first;
    cout << ans;
    reverse(a.begin(), a.end());
    for(auto x : a)
        cout << x.second;
}
