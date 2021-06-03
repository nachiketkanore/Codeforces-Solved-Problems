#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 100 + 2, inf = 1e18;

int n, m;
char mat[N][N];
bool yes[N][N];
std::vector<array<int,3>> answer;

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

    cin >> n >> m;
    FOR(i, 1, n)FOR(j, 1, m)    cin >> mat[i][j];
    FOR(i, 1, n)FOR(j, 1, m)if(mat[i][j] == '*'){
        int len = 0;
        int lo = j - 1, hi = j + 1;
        while(lo >= 1 && hi <= m && mat[i][lo] == '*' && mat[i][hi] == '*'){
            len++;
            lo--;
            hi++;
        }
        int ans = len;
        len = 0;
        lo = i - 1, hi = i + 1;
        while(lo >= 1 && hi <= n && mat[lo][j] == '*' && mat[hi][j] == '*'){
            len++;
            lo--;
            hi++;
        }
        ans = min(ans, len);
        if(ans > 0){
            answer.push_back({i, j, ans});
            yes[i][j] = 1;
            int id = i - 1, loop = ans;
            while(id >= 1 && (loop-- > 0))
                yes[id][j] = 1, id--;
            id = i + 1, loop = ans;
            while(id <= n && (loop-- > 0))
                yes[id][j] = 1, id++;
            id = j - 1, loop = ans;
            while(id >= 1 && (loop-- > 0))
                yes[i][id] = 1, id--;
            id = j + 1, loop = ans;
            while(id <= m && (loop-- > 0))
                yes[i][id] = 1, id++;
        }
    }
    FOR(i, 1, n)FOR(j, 1, m) if(mat[i][j] == '*' && yes[i][j] == 0){
        cout << -1 << '\n';
        return 0;
    }
    cout << sz(answer) << '\n';
    for(auto &it : answer)
        cout << it[0] << " " << it[1] << " " << it[2] << '\n';
}
