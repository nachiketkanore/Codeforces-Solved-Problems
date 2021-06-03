#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e2 + 5, inf = 1e8, mod = 1e9 + 7;

int x;

void solve(){
	cin >> x;
	for(int i = 1; i*i <= x; i++){
		if(x % i == 0){
			int fi = i, se = x/i;
			int ab = x * fi - fi*fi;
			if(ab > 0){
				cout << 1 << " " << ab << endl;
				return;
			}
			ab = x * se - se*se;
			if(ab > 0){
				cout << 1 << " " << ab << endl;
				return;
			}
		}
	}
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    #ifndef ONLINE_JUDGE
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif

    int t;
    cin >> t;
    while(t--)
    	solve();
}

