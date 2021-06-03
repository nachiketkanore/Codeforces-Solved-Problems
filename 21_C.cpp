//Starting from zero, we got nothing to lose
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
const int N = 1e5+10;
int n, a[N];

int32_t main(){ 
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
   	
   	int n;
   	cin >> n;
   	if(n < 3){
   		cout << 0 << '\n';
   		return 0;
   	}
   	int sum = 0;
   	for(int i = 1; i <= n; i++){
   		cin >> a[i];
   		sum += a[i];
   		a[i] += a[i-1];
   	}
   	if(sum % 3 != 0){
   		cout << 0 << '\n';
   	}else{
   		int one = sum/3;
   		int two = 2*one;
   		int ans = 0, curr = 0;
   		for(int i = 1; i < n; i++){
   			if(a[i] == two)
   				ans += curr;
   			if(a[i] == one)
   				curr++;
   		}
   		cout << ans << endl;
   	}

}
