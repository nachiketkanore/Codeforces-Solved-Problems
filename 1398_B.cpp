#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; (L <= R? i <= R : i >= R); (L <= R? i += 1 : i -= 1))
#define int long long

const int N = 2e5 + 2, inf = 1e18;

void solve();


/*---------------------------------------DEBUG-----------------------------------------------*/
void __print(int x) {
    cerr << x;
}
void __print(float x) {
    cerr << x;
}
void __print(double x) {
    cerr << x;
}
void __print(long double x) {
    cerr << x;
}
void __print(char x) {
    cerr << '\'' << x << '\'';
}
void __print(const char *x) {
    cerr << '\"' << x << '\"';
}
void __print(const string &x) {
    cerr << '\"' << x << '\"';
}
void __print(bool x) {
    cerr << (x ? "true" : "false");
}


template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';
}
template<typename T>
void __print(const T &x) {
    int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";
}
void _print() {
    cerr << "]\n";
}
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t); if (sizeof...(v)) cerr << ", "; _print(v...);
}
#ifndef ONLINE_JUDGE
#define see(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define see(x...)
#endif
/*---------------------------------------DEBUG-----------------------------------------------*/


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);  

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    string s;
    cin >> s;
    bool one = false;
    for(char ch : s) {
        one |= ch == '1';
    }
    if(one == false) {
        cout << 0 << '\n';
        return;
    }
    char curr = s[0];
    int len = 1;
    vector<int> lens;
    for(int i = 1; i < sz(s); ++i){ 
        if(curr == s[i]){ 
            ++len;
        }else {
            if(curr == '1') {
                lens.push_back(len);
                curr = s[i];
                len = 1;
            }else {
                curr = s[i];
                len = 1;
            }
        }
    }
    if(curr == '1') {
        lens.push_back(len);
    }
    sort(lens.rbegin(), lens.rend());
    int ans = 0;
    for(int i = 0; i < sz(lens); i+=2) {
        ans += lens[i];
    }
    see(lens);
    cout << ans << '\n';
}
