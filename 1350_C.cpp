#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18;
const int M = 1e7 + 5, K = 21;

int n, a[N];

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

int cnt[N][K + 2];


int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  

   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   SPF();
   cin >> n;
   for(int i = 1; i <= n; i++){
      int u;
      cin >> u;
      while(u > 1){
         int p = spf[u];
         int ex = 0;
         while(u % p == 0)
            ++ex, u /= p;
         cnt[p][ex]++;
      }
   }

   int ans = 1;
   for(int i = 1; i < N; i++){
      int temp = 0;
      for(int j = 0; j < K; j++)
         temp += cnt[i][j];
      int j;
      for(j = 1; j < K and temp > n - 2; j++)
         temp = temp - cnt[i][j];
      int times = 1;
      for(int x = 1; x < j; x++)
         times = times * i;
      ans = ans * times;
   }
   cout << ans;
}