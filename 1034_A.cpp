#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 3e5 + 5, M = 1.5e7 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
bool prime[M];
int cnt[M], a[N],n;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    #ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);	
	#endif

	fill(prime + 2, prime + M, true);
	cin >> n;
	int g = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		g = __gcd(g, a[i]);
	}

	for(int i = 0; i < n; i++){
		a[i] = a[i]/g;
		++cnt[a[i]];
	}

	int ans = 0;

	for(int i = 2; i < M; i++){
		if(prime[i]){
			int curr = cnt[i];
			for(int j = 2*i; j < M; j += i)
				prime[j] = false, curr += cnt[j];
			ans = max(ans, curr);
		}
	}


	cout << (ans == 0 ? -1 : n - ans) << '\n';

}

