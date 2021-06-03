//It's time to be who I am, rather than who I am supposed to be.
#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5+10;
const int mod = 998244353;
const int inf = 1e18;
int n, m, cx, cy, ans;

bool inside(int steps, int dx, int dy){
	int ccx = cx + steps * dx;
	int ccy = cy + steps * dy;
	return (ccx >= 1 and ccx <= n and ccy >= 1 and ccy <= m);
}

int32_t main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

    cin >> n >> m;
    cin >> cx >> cy;
    int k;
    cin >> k;
    while(k--){
    	int dx, dy;
    	cin >> dx >> dy;
    	int lo = 0, hi = 1e10;
    	int toTake = 0;
    	while(lo <= hi){
    		int mid = (lo + hi)/2;
    		if(inside(mid, dx, dy)){
    			toTake = max(toTake, mid);
    			lo = mid + 1;
    		}else hi = mid - 1;
    	}
    	ans += toTake;
    	cx = cx + toTake * dx;
    	cy = cy + toTake * dy;
    }
    cout << ans << '\n';
}