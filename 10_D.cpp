#include <bits/stdc++.h>
#define sz(x) (int)(x.size())
using namespace std;

const int N = 503, mod = 1e9 + 7;

int n, m, a[N], b[N], dp[N][N];
map<int, vector<int> > pos;

int go(int i, int j){
    if(i > n)
        return 0;
    
    int &ans = dp[i][j];
    if(~ans)
        return ans;
    ans = go(i + 1, j);

    if(sz(pos[a[i]]) and a[i] > b[j]){
        int index = N, lo = 0, hi = sz(pos[a[i]]) - 1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            int idx = pos[a[i]][mid];
            if(idx > j){
                index = min(index, idx);
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        if(index != N and index > j){
            ans = max(ans, 1 + go(i + 1, index));
        }
    }

    return ans;
}

void print(int i, int j){
    if(i > n)
        return ;
    
    int real = go(i, j);
    if(real == go(i + 1, j)){
        return print(i + 1, j);
    }


    if(sz(pos[a[i]]) and a[i] > b[j]){
        int index = N, lo = 0, hi = sz(pos[a[i]]) - 1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            int idx = pos[a[i]][mid];
            if(idx > j){
                index = min(index, idx);
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        if(index != N and index > j){
            if(1 + go(i + 1, index) == real){
                cout << a[i] << " ";
                return print(i + 1, index);
            }
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

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> b[i], pos[b[i]].push_back(i);
    a[0] = b[0] = -1;
    int mx = go(1, 0);
    cout << mx << '\n';
    print(1, 0);
}