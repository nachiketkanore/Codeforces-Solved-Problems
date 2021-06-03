//Let's start from scratch again
#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
    if(n < 2) return false;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0) 
            return false;
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> ans;
    for(int i = 2; i <= n; i++){
        if(prime(i)){
            for(int j = i; j <= n; j*=i)
                ans.push_back(j);
        }
    }
    cout << ans.size() << '\n';
    for(auto it : ans)
        cout << it << ' ';
}