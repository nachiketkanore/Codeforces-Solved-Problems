#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

void solve();

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    for(char &ch : s){
        if(t.empty())
            t.push_back(ch);
        else{
            if(ch == ')' && t.back() == '(')
                t.pop_back();
            else 
                t.push_back(ch);
        }
    }    
    int open = 0, close = 0;
    for(char &ch : t)
        open += ch == '(', close += ch == ')';
    assert(open == close);
    cout << open << '\n';
}
