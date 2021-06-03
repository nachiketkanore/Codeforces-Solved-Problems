#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

void solve();

string analyze(int , int );
int get(int , int );


int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}


int get(int x, int Y) { 
  
    string y = to_string(Y); 
  
    int n = y.size(); 
    vector<int> p(n); 
  
    for (int i = 0; i < n; i++) { 
        p[i] = y[i] - '0'; 
    } 

    for (int i = 1; i < n; i++) {
        p[i] += p[i - 1];
    }
  
    for (int i = n - 1, k = 0; ; i--, k++) { 
        int d = 0; 
  
        if (i >= 0) 
            d = y[i] - '0'; 
  
        for (int j = d + 1; j <= 9; j++) { 
  
            int r = (i > 0) * p[i - 1] + j; 
  
            if (x - r >= 0 and x - r <= 9 * k) { 
  
                string suf = analyze(k, x - r); 
  
                string pre; 
                if (i > 0) 
                    pre = y.substr(0, i); 
  
                char cur = (char)(j + '0'); 
                pre += cur; 
  
                string ret = pre + suf;
                int ans = stoll(ret);
                return ans;
            } 
        } 
    } 
} 

void solve(){
    int n, s;
    cin >> n >> s;

    int ans = inf;

    for (int sum = s; sum >= 1; --sum) {
        int next = get(sum, n - 1);
        ans = min(ans, next - n);
    }

    cout << ans << '\n';
}


string analyze(int d, int s) {

    string ret(d, '0'); 
  
    for (int i = d - 1; i >= 0; i--) { 
        if (s >= 9) { 
            ret[i] = '9'; 
            s -= 9; 
        } else { 
            ret[i] = (char)s + '0'; 
            s = 0; 
        } 
    } 
  
    return ret; 
} 