// Author : Nachiket Kanore
// Institute : PICT, Pune

/* 
Looking from a window above
It's like a story of love
Can you hear me?
Came back only yesterday
I'm moving further away
Want you near me
All I needed was the love you gave
All I needed for another day
And all I ever knew
Only you
Sometimes when I think of her name
When it's only a game
And I need you
Listen to the words that you say
It's getting harder to stay
When I see you
All I needed was the love you gave
All I needed for another day
And all I ever knew
Only you, only you
Uh uh uh only you, only you
Only you, only you, only you
This is going to take a long time
And I wonder what's mine
Can't take no more
Wonder if you'll understand
It's just the touch of your hand
Behind a closed door
And all I needed was the love you gave
All I needed for another day
And all I ever knew
Only you, only you, only you
All I needed was the love you gave
All I needed for another day
And all I ever knew
Only you, only you, only you
Only you
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define endl '\n'
#define rep(x,s,e) for(int x=s;x<=(e);x++)
#define repn for(int x=0;x<n;x++)
#define rep1n for(int x=1;x<=n;x++)
#define rep1m for(int y=1;y<=m;y++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define precise(x) cout << fixed << setprecision(x)
#define bits(x) __builtin_popcountll(x)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define sz(x) ((int)(x.size()))
#define test int t; cin>>t; while(t--)
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;


void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}


template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define see(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define see(x...)
#endif

const int inf = 3e18;
const int N = 4e5+100;

int n, m, col[N], in[N], out[N],tree[4*N], lazy[4*N], vis[N], a[N], timer;
vi g[N];

void push(int node, int L, int R){
   if(L != R)
      lazy[2*node] = lazy[node], 
      lazy[2*node + 1] = lazy[node];
   tree[node] = lazy[node];
   lazy[node] = 0;
}

void build(int node, int L, int R) {
   if(L == R){
      tree[node] = a[L];
   }else {
      int mid = (L + R) / 2;
      build(2*node, L, mid);
      build(2*node+1, mid + 1, R);
      tree[node] = tree[2*node] | tree[2*node + 1];
   }
}

void update(int node, int tl, int tr, int ql, int qr, int val){
   if(lazy[node])
      push(node, tl, tr);
   if(qr < tl || ql > tr)
      return;
   if(tl >= ql and tr <= qr){
      tree[node] = val;
      if(tl != tr){
         lazy[2*node] = val,
         lazy[2*node + 1] = val;
      }
      return;
   }
   int mid = (tl + tr) /2;
   update(2*node, tl, mid, ql,qr, val);
   update(2*node + 1, mid + 1,tr, ql ,qr,val);
   tree[node] = tree[2*node] | tree[2*node + 1];
}

int query(int node, int tl, int tr, int ql, int qr){
   if(lazy[node])
      push(node, tl, tr);
   if(qr < tl || tr < ql)
      return 0;
   if(tl >= ql and tr <= qr)
      return tree[node];
   int mid = (tl + tr)/2;
   return query(2*node, tl, mid, ql, qr) | query(2*node + 1, mid+1,tr, ql, qr);

}

void dfs(int u, int p){
   in[u] = ++timer;
   a[timer] = col[u];
   for(int v : g[u])
      if(v != p)
         dfs(v, u);
   out[u] = timer;
}

int32_t main(){ 
   FAST;
   cin >> n >> m;
   for(int i = 1; i <= n; i++)
      cin >> col[i], col[i] = 1LL << col[i];

   for(int i = 1; i < n; i++){
      int u , v;  cin >> u >> v;
      g[u].push_back(v), g[v].push_back(u);
   }

   dfs(1, 1);
   build(1,1,n);

   while(m--){
      int t;   cin >> t;
      if(t == 1){
         int vert;   cin >> vert;
         int color;  cin >> color;
         color = 1LL << color;
         update(1,1,n,in[vert], out[vert], color);
      }else {
         int vert;   cin >> vert;
         int mask = query(1,1,n,in[vert], out[vert]);
         mask = bits(mask);
         cout << mask << '\n';
      }
   }

}
