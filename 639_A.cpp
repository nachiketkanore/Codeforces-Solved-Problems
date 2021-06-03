//It's time to be who I am, rather than who I am supposed to be.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;
const int mod = 998244353;

int32_t main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

    int n, k, q;
    cin >> n >> k >> q;
    multiset <int> active;
    map<int,bool> online;
    int a[n+1] = {0};
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    while(q--){
    	int type, id;
    	cin >> type >> id;
    	if(type == 1){
    		active.insert(a[id]);
    		online[id] = 1;
    		while((int)(active.size()) > min(k,n))
    			active.erase(active.begin());
    	}else{
    		if(!online[id])
    			cout << "NO" << '\n';
    		else{
    			if(active.count(a[id]))
    				cout << "YES" << '\n';
    			else cout << "NO" << '\n';
    		}
    	}
    }
	
}