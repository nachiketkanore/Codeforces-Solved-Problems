/*Falling != Failing*/
#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 2e5 + 2, inf = 1e18, mod = 1e9 + 7; 

void solve();

void __print(int x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define see(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define see(x...)
#endif

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
        solve();
    }
}

void solve(){
    int n, u;
    cin >> n;
    int cnt[n + 2] = {0};
    for(int i = 0; i < n; i++){
        cin >> u;
        cnt[u]++;
    }
    int ans = 0;
    std::vector<int> a;
    for(int i = 1; i <= n; i++){
        ans += cnt[i]/i;
        
        int rem = cnt[i] % i;
        while(rem--)
            a.push_back(i);
    }

//    cout << ans << '\n';

    int have = 0, add = 0;
    for(int i = 0; i < sz(a); i++){
        ++have;
        if(a[i] == have){
            ++add;
            have = 0;
        }
    }

    //see(a);
    //see(add);
    ans += add;
    cout << ans << '\n';
}
