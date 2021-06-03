#include <bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5 + 5;
const int inf = 1e12;
const int mod = 1e9 + 7;
int n, l, x, y, a[N];
bool one = false, two = false;
map<int,int> f;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	cin >> n >> l >> x >> y;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		f[a[i]] = true;
	}

	for(int i = 1; i <= n; i++){
		int nextX = a[i] + x,
			nextY = a[i] + y;
		one |= f[nextX];
		two |= f[nextY];
	}

	if(one && two){
		cout << 0 << '\n';
	}else if(one ^ two){
		cout << 1 << '\n';

		for(int i = 1; i <= n; i++){
			int next = 0;
			if(!one) next = a[i] + x;
			if(!two) next = a[i] + y;
			if(!f[next] && next <= l){
				cout << next << '\n';
				exit(0);
			}
		}
	}else{
		int ans = 2;
		set<int> possibleA, possibleB;

		for(int i = 1; i <= n; i++){
			int nextX = a[i] + x,
				nextY = a[i] + y;
			int backX = a[i] - x,
				backY = a[i] - y;
			if(!f[nextX] and nextX <= l)
				possibleA.insert(nextX);
			if(!f[backX] and backX >= 1)
				possibleA.insert(backX);
			if(!f[nextY] and nextY <= l)
				possibleB.insert(nextY);
			if(!f[backY] and backY >= 1)
				possibleB.insert(backY);
		}

		// for(int p : possibleA)
		// 	cout << p << ' ';
		// cout << endl;

		// for(int p : possibleB)
		// 	cout << p << ' ';
		// cout << endl;

		for(int p : possibleB){
			if(possibleA.count(p)){
				cout << 1 << '\n';
				cout << p << '\n';
				return 0;
			}
		}

		for(int p : possibleA){
			if(f[p + y] || f[p - y]){
				cout << 1 << '\n';
				cout << p << '\n';
				return 0;
			}
		}

		for(int p : possibleB){
			if(f[p + x] || f[p - x]){
				cout << 1 << '\n';
				cout << p << '\n';
				return 0;
			}
		}



		cout << ans << '\n';
		cout << *possibleA.begin() << " " << *possibleB.begin() << '\n';

	}

}