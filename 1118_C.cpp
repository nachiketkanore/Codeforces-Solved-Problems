#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 20 + 2, inf = 1e18;

int n, mat[N][N];
int u, f[1010];
bool ans = true;

int get(int cnt){
   FOR(i,1,1000) if(f[i] >= cnt) {
      f[i] -= cnt;
      return i;
   }
   return -1;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   cin >> n;
   FOR(i,1,n*n){
      cin >> u;
      f[u]++;
   }
   int l = 1, r = n;
   while(l < r){
      int u = 1, d = n;
      while(u < d){
         int val = get(4);
         ans &= val > 0;
         mat[u][l] = mat[d][l] = mat[u][r] = mat[d][r] = val;
         u++, d--;
      }
      l++, r--;
   }

   if(n % 2 == 1){
      int mid = (n + 1)/2;
      l = 1, r = n;
      while(l < r){
         int val = get(2);
         ans &= val > 0;
         mat[l][mid] = mat[r][mid] = val;
         val = get(2);
         ans &= val > 0;
         mat[mid][l] = mat[mid][r] = val;
         l++, r--;
      }
      int val = get(1);
      ans &= val > 0;
      mat[mid][mid] = val;
   }

   if(ans == false)
      cout << "NO";
   else{
      cout << "YES\n"; FOR(i,1,n) FOR(j,1,n) cout << mat[i][j] << " \n"[j == n];
   }
}
