#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int power(int a, int b){
	int ret = 1;
	while(b){
		if(b&1)
			ret = ret * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return ret;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    #ifndef ONLINE_JUDGE
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif	

    string s;
    cin >> s;
    int ans = 0, cnt = 0;
    for(char ch : s){
    	if(ch == 'a')
    		++cnt;
    	else{
    		ans = (ans + power(2,cnt) - 1) % mod;
    	}
    }
    cout << ans << '\n';
}

