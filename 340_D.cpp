#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, a[N];

int LIS(){
	multiset<int> seq;
	for(int i = 1; i <= n; i++){
		seq.insert(a[i]);
		auto it = seq.upper_bound(a[i]);
		if(it != seq.end())
			seq.erase(it);
	}
	return sz(seq);
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    #ifndef ONLINE_JUDGE
    freopen("in1.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif	

   	cin >> n;
   	for(int i = 1; i <= n; i++)
   		cin >> a[i];
   	cout << LIS() << '\n';
}

