#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e5 + 2, inf = 1e18;

int n, ans = inf;
int currIdx;
int cost[N], howManyComeHere[N], which[N];

void goThroughAllPossibilities(int val, int reqCost){
    if(val < 1 || val > 100000)
        return;
    if(which[val] != currIdx) {
        which[val] = currIdx;
        cost[val] += reqCost;
        howManyComeHere[val]++;
        goThroughAllPossibilities(val >> 1, reqCost + 1);
        goThroughAllPossibilities(val << 1, reqCost + 1);
    }else{
        return;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin >> n;
    FOR(i,1,n){
        int val;
        cin >> val;
        currIdx = i;
        //previous solution was not going through all possible values 'val' can take
        //we could do a left-shift of right-shift at current value of 'val'
        goThroughAllPossibilities(val,0);
    }
    FOR(i,1,100000) if(howManyComeHere[i] == n){
        ans = min(ans, cost[i]);
    }
    cout << ans << '\n';
}
