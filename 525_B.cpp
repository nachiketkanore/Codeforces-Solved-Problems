#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

string s;
int n;
int pre[N];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> s; 
    n = sz(s);
    s = " " + s;
    int m;
    cin >> m;
    while(m--){
        int id; cin >> id;
        pre[id]++, pre[n - id + 2]--;
    }
    FOR(i,1,n){
        pre[i] += pre[i - 1];
        pre[i] %= 2;
    }
    FOR(i,1,n/2){
        if(pre[i])
            swap(s[i], s[n - i + 1]);
    }
    cout << s;
}
