#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int n, magic, req[N], have[N];

bool canMake(int cnt){
	int add = 0;
	for(int i = 1; i <= n; i++){
		int w = cnt * req[i];
		int extra = max(0LL, w - have[i]);
		add += extra;
	}
	return add <= magic;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    #ifndef ONLINE_JUDGE
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif

    cin >> n >> magic;
    for(int i = 1; i <= n; i++)
    	cin >> req[i];
    for(int i = 1; i <= n; i++)
    	cin >> have[i];
    
    int lo = 0, hi = 1e9 + 100;
    int ans = 0;
    while(lo <= hi){
    	int mid = (lo + hi)/2;
    	if(canMake(mid)){
    		ans = max(ans, mid);
    		lo = mid + 1;
    	}else {
    		hi = mid - 1;
    	}
    }
    cout << ans << '\n';
}

