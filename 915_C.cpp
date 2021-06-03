#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

string a, b;
int freq[10];

string go(int id, bool smaller) {
    if(id == sz(b))
        return "";

    //First try putting same digit as that in b[id] as we want max
    if(smaller == false && freq[b[id] - '0'] > 0) {
        --freq[b[id] - '0'];
        string next = go(id + 1, 0);
        ++freq[b[id] - '0'];
        if(next != "#") 
            return b[id] + next;
    }

    for(int dig = smaller? 9 : b[id]-'0'-1; dig >= 0; dig--) if(freq[dig] > 0) {
        --freq[dig];
        string next = go(id + 1, 1);
        ++freq[dig];
        if(next != "#") 
            return (char)(dig + '0') + next;
    }

    return "#";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> a >> b;
    if(sz(a) < sz(b)) {
        sort(a.rbegin(), a.rend());
        cout << a;
    }else {
        for(char c : a) {
            freq[c - '0']++;
        }
        cout << go(0,0);
    }
}
