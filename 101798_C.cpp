#include <bits/stdc++.h>
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

int checker = 0;

// if some number is involved then cleverly try to process the number .. 
// for ex:
// if number 3 is involved try to go through the middle element .. or if 2 is involved try to binary search
// or search the second element;
// const int N = 1e5;
// vi lps(N);
// void kmp_lps_precompute(string pattern) {
//     int len = 0, i = 1;
//     lps[0] = 0;
//     int m = pattern.size();
//     lps.resize(m);
//     while(i < m) {
//         if(pattern[i] == pattern[len]) {
//             len++;
//             lps[i] = len;
//             i++;
//         } else {
//             if(len != 0) len = lps[len-1];
//             else lps[i] = 0, i++;
//         } 
        
//     }
//     see(lps);
//     return;
// }

// void kmp_search(string s, string pat) {
//     kmp_lps_precompute(pat);
//     int i = 0, j = 0;
//     int n = s.size(), m = pat.size();
//     while(i < n-m+1) {
//         if(s[i] = pat[j]) i++, j++;
//         else {
//             if(!j) j = lps[j-1];
//             else i++;
//         }
//         if(j >= m) {
//             cout<<i<<" ";
//             j = lps[j-1];
//         }
//     } 
//     return;
// }

void solve() {
    int a[4];
    for(int i=0;i<4;i++) cin>>a[i];
    sort(a,a+4);
    cout<<a[0]*a[2]<<"\n";
}

signed main()
{
    fast;
    test 
    {
        solve();
    }
    return 0;   
}
