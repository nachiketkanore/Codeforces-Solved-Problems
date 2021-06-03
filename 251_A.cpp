//Let's start from scratch again
#include<bits/stdc++.h>
using namespace std;

using LL = long long;

LL nC2(LL val){
    return (val * (val - 1))/2;
}

int main(){
    int n, d;
    cin >> n >> d;
    LL a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];    

    LL ans = 0;
    for(int i = 2; i < n; i++){
       
        int prev = lower_bound(a, a + n, (a[i] - d)) - a;
        int len = i - prev;
        ans += nC2(len);
    
    }
    cout << ans << '\n';
}