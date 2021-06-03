#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

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

    int n, k;
    cin >> n >> k;
    map<int,int> f;
    FOR(i,1,n){
        int u;
        cin >> u;
        f[u]++;
    }
    vector<pair<int,int>> cnt;
    for(auto &it : f){
        cnt.push_back({it.first, it.second});
    }
    sort(cnt.begin(), cnt.end());
    map<int,int> back_freq;

    int curr = 0;
    for(int i = 0; i < sz(cnt); i++){
        back_freq[cnt[i].first] = curr;
        curr += cnt[i].second;
    }

    for(auto &it : cnt){
        int u = it.first, self_freq = it.second;
        int prev_freq = back_freq[u];
        int here = self_freq * prev_freq;
        here += self_freq * self_freq;
        int ahead_freq = n - (prev_freq + self_freq);
        here += self_freq * ahead_freq;
        if(k > here)
            k -= here;
        else{
            assert(k != 0);
            vector<array<int,2>> u_v_times;
            for(auto &it2 : cnt){
                int times = self_freq * it2.second;
                int v = it2.first;
                u_v_times.push_back({v, times});
            }
           // see(u_v_times);
            for(auto uvt : u_v_times){
                int times = uvt[1];
                if(k <= times){
                    cout << u << ' ' << uvt[0] << '\n';
                    return 0;
                }else{
                    k -= times;
                }
            }
            assert(0);
        }
    }

}
