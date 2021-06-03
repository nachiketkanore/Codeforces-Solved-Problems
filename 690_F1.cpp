#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 3e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, in[N], ans;

int nC2(int n){
	return n*(n-1)/2;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    #ifndef ONLINE_JUDGE
	freopen("in1.txt","r",stdin);
	freopen("out1.txt","w",stdout);
	#endif
  
  cin >> n;
  for(int i = 1, u, v; i < n; i++){
  	cin >> u >> v;
  	in[u]++, in[v]++;
  }

  for(int i = 1; i <= n; i++)
  	ans += nC2(in[i]);
  cout << ans << '\n';

}

