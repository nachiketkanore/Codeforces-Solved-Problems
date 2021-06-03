#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(x,y,z) for(int x = y; x <= z; x++)

const int N = 1e3 + 2;

char mat[N][N];
int colpref[N][N], rowpref[N][N];
int n, m, cntrow[N][N], cntcol[N][N];
std::vector<array<int,3>> ans;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);  

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	cin >> n >> m;
	FOR(i, 1, n) FOR(j, 1, m){
		cin >> mat[i][j];
		if(mat[i][j] == '*')
			colpref[i][j] = 1, rowpref[i][j] = 1;
	}
	FOR(i, 1, n) FOR(j, 1, m) rowpref[i][j] += rowpref[i][j - 1];
	FOR(j, 1, m) FOR(i, 1, n) colpref[i][j] += colpref[i - 1][j];

	FOR(i, 1, n) FOR(j, 1, m) if(mat[i][j] == '*'){
		int l = j, r = j, u = i, d = i;

		int lo = j + 1, hi = m;
		while(lo <= hi){
			int mid = (lo + hi)/2;
			int len = mid - j, sum = rowpref[i][mid] - rowpref[i][j];
			if(sum == len){
				r = mid;
				lo = mid + 1;
			}else{
				hi = mid - 1;
			}
		}

		lo = 1, hi = j - 1;
		while(lo <= hi){
			int mid = (lo + hi)/2;
			int len = j - mid, sum = rowpref[i][j - 1] - rowpref[i][mid - 1];
			if(sum == len){
				l = mid;
				hi = mid - 1;
			}else{
				lo = mid + 1;
			}
		}

		lo = i + 1, hi = n;
		while(lo <= hi){
			int mid = (lo + hi)/2;
			int len = mid - i, sum = colpref[mid][j] - colpref[i][j];
			if(sum == len){
				d = mid;
				lo = mid + 1;
			}else{
				hi = mid - 1;
			}
		}

		lo = 1, hi = i - 1;
		while(lo <= hi){
			int mid = (lo + hi)/2;
			int len = i - mid, sum = colpref[i - 1][j] - colpref[mid - 1][j];
			if(sum == len){
				u = mid;
				hi = mid - 1;
			}else{
				lo = mid + 1;
			}
		}

		int ray = min({j - l, r - j, d - i, i - u});
		if(ray > 0){
			ans.push_back({i, j, ray});
			l = j - ray, r = j + ray;
			u = i - ray, d = i + ray;
			cntrow[i][l]++, cntrow[i][r + 1]--;
			cntcol[u][j]++, cntcol[d + 1][j]--;
		}
	}

	FOR(i, 1, n) FOR(j, 1, m) cntrow[i][j] += cntrow[i][j - 1];
	FOR(j, 1, m) FOR(i, 1, n) cntcol[i][j] += cntcol[i - 1][j];
	FOR(i, 1, n) FOR(j, 1, m) if(mat[i][j] == '*' && cntrow[i][j] == 0 && cntcol[i][j] == 0){
		cout << -1;
		return 0;
	}

	cout << sz(ans) << '\n';
	for(auto &it : ans)
		cout << it[0] << ' ' << it[1] << ' ' << it[2] << '\n';
}
