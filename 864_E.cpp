#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)
#define int long long

const int N = 1e4 + 2, inf = 1e18;

struct item{
	int t, d, p;
	int id;
}a[102];

int n, dp[105][N];
vector<int> ans;

int go(int id, int curr_time){
	if(id > n)
		return 0;
	int &ret = dp[id][curr_time];
	if(~ret) return ret;

	int ans = go(id + 1, curr_time);
	if(curr_time + a[id].t < a[id].d){
		int gain = a[id].p + go(id + 1, curr_time + a[id].t);
		ans = max(ans, gain);
	}
	return ret = ans;
}

void print(int id, int curr_time){
	if(id > n)
		return ;
	int real_ans = go(id, curr_time);
	if(go(id + 1, curr_time) == real_ans){
		return print(id + 1, curr_time);
	}
	if(curr_time + a[id].t < a[id].d){
		int gain = a[id].p + go(id + 1, curr_time + a[id].t);
		if(gain == real_ans){
			ans.push_back(a[id].id);
			return print(id + 1, curr_time + a[id].t);
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	memset(dp, -1, sizeof(dp));
	cin >> n;
	FOR(i,1,n){
		cin >> a[i].t >> a[i].d >> a[i].p;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, [&](item i, item j){
		if(i.d == j.d)
			return i.t < j.t;
		return i.d < j.d;
	});

	cout << go(1,0) << '\n';
	print(1,0);
	cout << sz(ans) << '\n';
	for(int x : ans)
		cout << x << ' ';
}
