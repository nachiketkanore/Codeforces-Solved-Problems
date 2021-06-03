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
const int N = 5e5 + 100;

void solve(){
   string s;   cin >> s;
   int n = s.size();
   vector<vi> ans;
   
   while(true){
      int l = 0, r = sz(s) - 1;

         vi vals;
         int yes[sz(s)] = {0};
         
      while(l < r){
         if(s[l] == '(' and s[r] == ')'){
            vals.push_back(l);
            vals.push_back(r);
            yes[l] = 1, yes[r] = 1;
            l++, r--;
         }else if(s[l] == '(' and s[r] == '('){
            r--;
         }else if(s[l] == ')' and s[r] == ')'){
            l++;
         }else l++, r--;

         
      }

      if(vals.empty()) break;
         ans.push_back(vals);
         string new_s;
         for(int i = 0; i < sz(s); i++){
            if(!yes[i]) new_s.push_back(s[i]);
         }
         s = new_s;

   }

   cout << sz(ans) << endl;
   for(auto it : ans){
      cout << sz(it) << endl;
      sort(all(it));
      for(auto iit : it)  
         cout << iit + 1 << ' ';
      cout << endl;
   }
}

int32_t main(){ 
   FAST;
 
      solve(); 
 
}