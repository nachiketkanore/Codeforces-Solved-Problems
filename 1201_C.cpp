//Lets start from scratch
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
const int N = 2e5+100;

int n, k, a[N];
	

bool possible(int mid){
	int cost = 0;
	int curr = a[(n+1)/2];
	if(curr >= mid)
		return true;
	for(int i = (n+1)/2; i <= n; i++){
		if(mid >= a[i])
			cost += mid - a[i];
	}
	return cost <= k;
}

int32_t main(){ 
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
   	
   	cin >> n >> k;
   	for(int i = 1; i <= n; i++)
   		cin >> a[i];
   	sort(a+1,a+n+1);

   	int lo = 0, hi = 1e10;
   	int ans = a[0];

   	while(lo <= hi){
   		int mid = (lo + hi)/2;
   		if(possible(mid)){
   			ans = max(ans, mid);
   			lo = mid+1;
   		}else{
   			hi = mid-1;
   		}
   	}
   	assert(possible(ans));
   	cout << ans << '\n';
}
