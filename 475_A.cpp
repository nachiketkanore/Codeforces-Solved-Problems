//It's time to be who I am, rather than who I am supposed to be.
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;
const int mod = 998244353;

string a[4];
int k;

int32_t main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

    cin >> k;

    a[0] = a[1] = a[3] = "#.#.#.#.#.#.#.#.#.#.#.";
    a[2] = "#.....................";
    if(k == 0)
    	a[2][0] = '#';

    int len = a[0].size();

    for(int i = 0; i < len; i += 2){
    	if(i == 0){
    		for(int j = 0; j < 4; j++){
    			if(k > 0 ){
    				k--;
    				a[j][i] = 'O';
    			}
    		}
    	}else{
    		for(int j = 0; j < 4; j++){
    			if(j == 2) continue;
    			if(k > 0){
    				k--;
    				a[j][i] = 'O';
    			}
    		}
    	}
    }
    

    cout << "+------------------------+" << '\n';

    //seating here

    cout << "|" << a[0] << "|D|)";	cout << endl;
    cout << "|" << a[1] << "|.|";	cout << endl;
    cout << "|" << a[2] << "..|";	cout << endl;
    cout << "|" << a[3] << "|.|)";	cout << endl;

	cout << "+------------------------+" << '\n';

}