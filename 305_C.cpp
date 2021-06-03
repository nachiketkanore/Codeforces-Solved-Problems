//Let's start from scratch again
#include<bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    int n;
    cin >> n;
    multiset<int> f;
    for(int i = 0; i < n; i++){
        int vl;
        cin >> vl;
        f.insert(vl);
    }
    int set_bits = 0;
    int len = 0;
    while(!f.empty()){
        int small = *f.begin();
        len = max(len, small+1);
        f.erase(f.begin());
        if(!f.empty() and *f.begin() == small){
            f.erase(f.begin());
            f.insert(small+1);
            len = max(len, *f.rbegin()+1);
        }else set_bits++;
    }
    //cout << len << ' ' << set_bits << endl;
    int unset_bits = len - set_bits;
    cout << unset_bits << '\n';
}