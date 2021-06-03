#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

void solve();

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
    int n;
    cin >> n;
    set<int> a;
    FOR(i,1,n){
    	int u;
    	cin >> u;
    	a.insert(u);
    }
    int ans = -1;
    FOR(k,1,2000){
    	set<int> chk;
    	for(int x : a)
    		chk.insert(x^k);
    	if(chk == a){
    		ans = k;
    		break;
    	}
    }
    cout << ans << '\n';
}
