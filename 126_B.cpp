#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 2e2 + 5, M = 1e6 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

vector<int> z_algorithm(string pattern) {
    // Z[i] = for the suffix [i, n) of pattern, the longest prefix that is also a prefix of pattern.
    int n = pattern.size();
    vector<int> Z(n, 0);
    Z[0] = n;
    int loc = 1;
 
    for (int i = 1; i < n; i++) {
        if (i < loc + Z[loc])
            Z[i] = min(Z[i - loc], loc + Z[loc] - i);
 
        while (i + Z[i] < n && pattern[Z[i]] == pattern[i + Z[i]])
            Z[i]++;
 
        if (i + Z[i] > loc + Z[loc])
            loc = i;
    }
 
    return Z;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);	

    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    #endif


    string str;
    cin >> str;
    vector<int> Z = z_algorithm(str);
    int n = str.size(), most = 0;
 
    for (int i = 1; i < n; i++) {
        if (min(Z[i], most) >= n - i) {
            cout << str.substr(i) << '\n';
            return 0;
        }
 
        most = max(most, Z[i]);
    }
 
    cout << "Just a legend" << '\n';
}

