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



int32_t main(){ 
   FAST;
   int n;   cin >> n;
   int a[n], b[n];
   for(int i = 0; i < n; i++)
    cin >> a[i];
   for(int i = 0; i < n; i++)
    cin >> b[i];

    int his = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i])    continue;
        if(a[i] == 0 and b[i] == 1) his++;
        else cnt++;
    }

    if(his == n || cnt == 0)
        return cout << -1, 0;

    int val = his/ cnt;
    cout << val + 1 << '\n';
  
}