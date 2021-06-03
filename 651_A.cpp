#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int a, b;
    cin >> a >> b;
    int time = 0;
    while(min(a,b) >= 1 && max(a, b) >= 2){
        if(a < b){
            a += 1;
            b -= 2;
        }else{
            a -= 2;
            b += 1;
        }
        time++;
    }
    cout << time << '\n';
}
