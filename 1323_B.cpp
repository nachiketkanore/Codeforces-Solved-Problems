// Author : Nachiket Kanore
// Institute : PICT, Pune

/* 
Thought I almost died in my dream again (Baby, almost died)
Fightin' for my life, I couldn't breathe again
I'm fallin' in too deep (Oh, oh)
Without you, I can't sleep (Fallin' in)
'Cause my heart belongs to you
I'll risk it all for you
I want you next to me
This time, I'll never leave
I wanna share babies
Protection, we won't need
Your body next to me
Is just a memory
I'm fallin' in too deep, oh
Without you, I can't sleep
Insomnia relieve, oh
Talk to me, without you, I can't breathe

My darkest hours
Girl, I felt so alone inside of this crowded room
Different girls on the floor, distractin' my thoughts of you
I turned into the man I used to be, to be
Put myself to sleep
Just so I can get closer to you inside my dreams
Didn't wanna wake up 'less you were beside me
I just wanted to call you and say, and say

Oh, baby
Where are you now when I need you most?
I'd give it all just to hold you close
Sorry that I broke your heart, your heart

Never comin' down, uh
I was running away from facin' reality, uh
Wastin' all of my time out living my fantasies
Spendin' money to compensate, compensate
'Cause I want you, baby, uh
I be livin' in heaven when I'm inside of you
It was simply a blessing wakin' beside you
I'll never let you down again, again

Oh, baby
Where are you now when I need you most?
I'd give it all just to hold you close
Sorry that I broke your heart, your heart
I said, baby
I'll treat you better than I did before
I'll hold you down and not let you go
This time, I won't break your heart, your heart, yeah

I know it's all my fault
Made you put down your guard
I know I made you fall
Then said you were wrong for me
I lied to you, I lied to you, I lied to you (To you)
Can't hide the truth, I'd stay with her in spite of you
You did some things that you regret, still ride for you
'Cause this house is not a home

Without my baby
Where are you now when I need you most?
I gave it all just to hold you close
Sorry that I broke your heart, your heart
And I said, baby
I'll treat you better than I did before
I'll hold you down and not let you go
This time, I won't break your heart, your heart, no

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
const int N = 40005;
map<int,int> ansA, ansB;
int n , m, k;

int32_t main(){ 
   FAST;
   cin >> n >> m >> k;
   vi a(n), b(m);

   int cnt = 0;
   for(int i = 0; i < n; i++){
      cin >> a[i];
      if(a[i] == 1) cnt++;
      else if(a[i] == 0 and cnt){
         for(int ii = 1; ii <= cnt; ii++)
            ansA[ii] += (cnt - ii + 1);
         cnt = 0;
      }
   }

   if(cnt){
      for(int ii = 1; ii <= cnt; ii++)
         ansA[ii] += cnt - ii + 1;

      cnt = 0;
   }
   cnt = 0;

   for(int i = 0; i < m; i++){
      cin >> b[i];
      if(b[i] == 1) cnt++;
      else if(b[i] == 0 and cnt){
         for(int ii = 1; ii <= cnt; ii++)
            ansB[ii] += (cnt - ii + 1);
         cnt = 0;
      }
   }

   if(cnt){
      for(int ii = 1; ii <= cnt; ii++)
         ansB[ii] += cnt - ii + 1;

      cnt = 0;
   }

   int ans = 0;

   for(int i = 1; i <= 40000  && i <= k; i++){
      if(k % i == 0){
         ans += ansA[i] * ansB[k/i];
      }
   }
   cout << ans << endl;
}
