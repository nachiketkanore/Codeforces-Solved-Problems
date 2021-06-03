//Let's start from scratch again
#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans = 0;


int nCr(int n, int r){
    int p = 1, k = 1;
    r = min(r, n - r);
    if(r != 0){
        while(r){
            p *= n;
            k *= r;
            int g = __gcd(p,k);
            p /= g;
            k /= g;
            n--, r--;
        }
    }else p = 1;
    return p;
}

int32_t main(){
    int n, m, t;
    cin >> n >> m >> t;

    for(int i = 4; i <= t; i++){
        for(int j = 1; j <= t; j++){
            if((i <= n) and (j <= m) and ((i+j) == t)){
                ans += 1LL*nCr(n,i)*nCr(m,j);
            }
        }
    }
    cout << ans << endl;
}