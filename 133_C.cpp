#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define int long long

const int N = 1e5 + 2, inf = 1e18, mod = 256; 

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int prev = 0;
    string s;
    getline(cin, s);
    for(char ch : s){
        int asci = (int)(ch);
        std::vector<bool> bits;
        for(int i = 0; i < 8; i++)
            bits.push_back(asci >> i & 1);
        int num = 0;
        for(int i = 0; i < 8; i++)
            num = num + (bits[i] << (8 - i - 1));
        int ans = (prev - num + mod) % mod;
        cout << ans << '\n';
        prev = num;
    }
}
