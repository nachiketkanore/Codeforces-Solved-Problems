//Lets start from scratch
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18;
const int N = 2e5+100;

int n, days, cont, a[N];
	

bool possible(int mid){
	int days_needed = 0;
    int waters_active = 0;
    int waters[n] = {0};
 
    for(int i = 0; i<n; i++){
        if(i >= cont) waters_active -= waters[i - cont];
        long long needed_here = max(0LL, mid - a[i] - waters_active);
        waters[i] = needed_here;
        waters_active += waters[i];
        days_needed += waters[i];
    }
    return days_needed <= days;
}

int32_t main(){ 
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
   	
   	cin >> n >> days >> cont;
   	for(int i = 0; i < n; i++)
   		cin >> a[i];

   	int lo = 0, hi = 1e9 + 2e5;
   	int ans = *min_element(a+1,a+n+1);

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
