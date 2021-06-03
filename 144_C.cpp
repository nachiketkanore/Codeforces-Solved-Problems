//It's time to be who I am, rather than who I am supposed to be.
#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x.size())
using namespace std;

const int N = 1e5+10;
const int mod = 998244353;
string s, t;
int n, m, fs[N][26], ft[26], ans, ques[N];


void solve(){

	for(int i = 0; i < n; i++){
		if(s[i] != '?')
			fs[i][s[i] - 'a']++;
		else ques[i]++;
	}

	for(int i = 0; i < m; i++)
		ft[t[i] -'a']++;

	for(int i = 1; i < n; i++)
		ques[i] += ques[i-1];

	for(int i = 1; i < n; i++)
		for(int j = 0; j < 26; j++)
			fs[i][j] += fs[i-1][j];

	int f[26] = {0};
	for(int i = 0; i < sz(t); i++)
		if(s[i] != '?')
			f[s[i] - 'a']++;

		bool ok = true;
		int quest = ques[sz(t) - 1];

	int cnt = 0;
	for(int i = 0; i < 26; i++)
		if(f[i] > ft[i]){
			ok = false;
		}else cnt += ft[i] - f[i];

	if(ok && (quest == cnt))
		ans++;

	int left = 0;
	for(int right = sz(t); right < n; right++){
		int currF[26] = {0};
		for(int i = 0; i < 26; i++)
			currF[i] = fs[right][i] - fs[left][i];
		int currQues = ques[right] - ques[left];
		left++;
		bool yes = true;
		int add = 0;
		for(int i = 0; i < 26; i++)
			if(currF[i] > ft[i])
				yes = false;
			else add += ft[i] - currF[i];
		ans += (yes && (add == currQues));
	}
	cout << ans << '\n';

}


int32_t main(){
	ios::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   #endif

    cin >> s >> t;
    n = sz(s), m = sz(t);

    if(sz(s) < sz(t)){
    	cout << 0 << '\n';
    	return 0;
    }
    solve();
}