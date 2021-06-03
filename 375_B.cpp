#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 5000 + 2, inf = 1e18;

int n, m;
int mat[N][N];
char ch;
vector<int> LENS[N]; //in each column
int ans;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);  
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   cin >> n >> m;
   FOR(i,1,n) FOR(j,1,m){
      cin >> ch;
      mat[i][j] = ch - '0';
      if(mat[i][j])
         mat[i][j] += mat[i][j - 1];
      LENS[j].push_back(mat[i][j]);
   }
   FOR(col,1,m){
      sort(LENS[col].rbegin(), LENS[col].rend());
      FOR(width,1,n){
         int height = LENS[col][width - 1];
         ans = max(ans, height * width);
      }
   }
   cout << ans;
}  
