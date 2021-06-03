#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define inf 5e18
#define MOD (int)(1e9 + 7)
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(),x.rend()
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fast                       \
    ios_base ::sync_with_stdio(0); \
    cin.tie(NULL);                 \
    cout.tie(NULL)
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> oset;
// oset curr;

void __print(int x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define see(x...)                 \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define see(x...)
#endif

void solve() {
    int n;
    cin>>n;
    n *= 2;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vi x(2*n), y(2*n);
    for(int i=0;i<2*n;i++) x[i]=i%2, y[i]=(1-i%2);
    vi b = a, c = a;
    sort(all(c));
    if(b==c) {
        cout<<0;
        return;
    }
    int cnt = 0;
    int ans = inf;
    int f1=0, f2=0;
    for(int i=0;i<2*n;i++) {
        if(x[i]==0) {
            for(int j=0;j<n;j+=2) {
                swap(b[j],b[j+1]);
            }
            cnt++;
        } else {
            for(int j=0;j<n/2;j++) {
                swap(b[j],b[n/2+j]);
            }
            cnt++;
        }
        if(c==b) {
            ans = min(ans,cnt);
            f1 = 1;
        }
    }
    b = a;
    cnt = 0;
    for(int i=0;i<2*n;i++) {
        if(y[i]==0) {
            for(int j=0;j<n;j+=2) {
                swap(b[j],b[j+1]);
            }
            cnt++;
        } else {
            for(int j=0;j<n/2;j++) {
                swap(b[j],b[n/2+j]);
            }
            cnt++;
        }
        if(c==b) {
            ans = min(ans,cnt);
            f2 = 1;
        }
    }
    if(f1||f2) cout<<ans<<"\n";
    else cout<<-1<<"\n";
}

signed main()
{
    fast;
    // test
    {
        solve();
    }
    return 0;   
}