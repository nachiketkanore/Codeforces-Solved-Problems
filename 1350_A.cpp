#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int mod = 1e9 + 7, inf = 1e18;

const int N = 1e6+50;   //Can go upto N = 1e7
int spf[N+10];
 
void SPF(){
 
   spf[1] = 1; 
  
    for (int i = 2; i <= N; i++) 
        if (spf[i] == 0) { 
            spf[i] = i; 
            for (int j = 2*i; j <= N; j += i) 
                if (spf[j] == 0) 
                   spf[j] = i; 
        } 
}


void solve();

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  

   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   SPF();
   int t = 1;
   cin >> t;
   while(t--)
      solve();
}

void solve(){
   int n, k;
   cin >> n >> k;
   if(n % 2 == 0){
      cout << n + 2*k << '\n';
      return;
   }
   int ans = n + 2*(k - 1) + spf[n];
   cout << ans << '\n';
}