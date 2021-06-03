#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 25, inf = 1e9;

int n;
int x[N], y[N], ans = inf;
int dp[1 << N], Dist[N][N];

int calc(int i, int j){
	return (abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]));
}

int dist(int i, int j){
	return Dist[i][j];
}

int go(int done){
	if(__builtin_popcount(done) == n)
		return 0;

	int &ans = dp[done];
	if(~ans)
		return ans;
	ans = inf;

	int first = 1;
	while(done & (1 << first)) first++;

	assert((done >> first & 1) == 1 or first <= n and first >= 1);

	FOR(next, first, n) if((done >> next & 1) == 0){
		int cost = dist(0, first) + dist(first, next) + dist(0, next);
		cost = cost + go(done | (1 << first) | (1 << next));
		ans = min(ans , cost);
	}
	return ans;
}

void print(int done){
	if(__builtin_popcount(done) == n)
		return ;

	int real_ans = go(done);
	int first = 1;
	while(done & (1 << first)) first++;

	FOR(next, first, n) if((done >> next & 1) == 0){
		int cost = dist(0, first) + dist(first, next) + dist(0, next);
		cost = cost + go(done | (1 << first) | (1 << next));
		if(cost == real_ans){
			if(first == next){
				cout << first << ' ' << 0 << ' ';
				return print(done | (1 << first) | (1 << next));
			}else{
				cout << first << ' ' << next << ' ' << 0 << ' ';
				return print(done | (1 << first) | (1 << next));
			}
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
	cin >> x[0] >> y[0];
	cin >> n;
	FOR(i, 1, n){
		cin >> x[i] >> y[i];
	}
	FOR(i,0,n) FOR(j,0,n) Dist[i][j] = calc(i, j);

	ans = go(0);
	cout << ans << '\n';
	cout << 0 << " ";
	print(0);

}
