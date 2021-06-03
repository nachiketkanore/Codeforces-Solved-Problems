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

    int k, prod = 1;
    cin >> k;

    multiset<int> nums;
    FOR(i,1,10){
        nums.insert(1);
    }

    while(prod < k){
        int small = *nums.begin();
        nums.erase(nums.begin());
        prod = prod / small;
        ++small;
        prod = prod * small;
        nums.insert(small);
    }
    string ans = "codeforces";
    int id = 0;
    for(int cnt : nums){
        char w = ans[id]; id++;
        FOR(i,1,cnt)
            cout << w;
    }
    cout << '\n';
}
